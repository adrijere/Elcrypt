/*
** decrypt_funct.c for decrypt_funct in /home/mathon_j/rendu/elcrypt/source
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Sun Mar 15 17:33:46 2015 Jérémy MATHON
** Last update Sun Mar 15 18:06:16 2015 Jérémy MATHON
*/

#include	"elcrypt.h"

static void	get_bloc(char *str, u_bloc *bloc)
{
  int		i;

  i = 0;
  while (i < 8)
    {
      bloc->_char[i] = str[7 - i];
      i++;
    }
}

static void	algo_decrypt(t_parser *parser, char *buf, int ret, t_file *file)
{
  u_bloc	bloc;
  u_key		tmp;
  int		i;
  unsigned int	flag_tmp[2];

  i = 8;
  get_bloc(buf, &bloc);
  flag_tmp[0] = bloc._flag[0];
  bloc._flag[0] = bloc._flag[1];
  bloc._flag[1] = flag_tmp[0];
  while (i > 0)
    {
      rotate_decrypt(&tmp, parser->key_prim, i);
      flag_tmp[1] = bloc._flag[1];
      flag_tmp[0] = (tmp.iint[0] ^ bloc._flag[1]) ^ bloc._flag[0];
      bloc._flag[0] = flag_tmp[1];
      bloc._flag[1] = flag_tmp[0];
      i--;
    }
  i--;
  while (++i < 8)
    buf[i] = bloc._char[7 - i];
  ret = 0;
  write(file->fd_out, buf, 8 - ret);
}

void		my_decrypt(t_parser *parser, t_file *file)
{
  char		buf[8];
  int		ret;

  while ((ret = read(file->fd_in, buf, 8)) == 8)
    algo_decrypt(parser, buf, 0, file);
  if (ret == -1)
    return ;
  if (ret != 0)
    algo_decrypt(parser, buf, 0, file);
}
