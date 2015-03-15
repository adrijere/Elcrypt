/*
** crypt_funct.c for crypt_funct in /home/mathon_j/rendu/elcrypt/source
**
** Made by Jérémy MATHON
** Login   <mathon_j@mathonj>
**
** Started on  Sun Mar 15 16:05:30 2015 Jérémy MATHON
** Last update Sun Mar 15 17:38:04 2015 Jérémy MATHON
*/

#include	"elcrypt.h"

static void	get_bloc(char *buf, u_bloc *bloc)
{
  int		i;

  i = 0;
  while (i < 8)
    {
      bloc->_char[i] = buf[7 - i];
      i++;
    }
}

static void		algo_crypt(t_parser *parser, char *str, t_file *file)
{
  u_bloc		bloc;
  u_key			tmp;
  int			i;
  unsigned int		flag_tmp[2];

  i = 0;
  get_bloc(buff, &bloc);
  tmp.llong = parser->key_prim->llong;
  flag_tmp[0] = bloc._flag[0];
  bloc._flag[0] = bloc._flag[1];
  bloc._flag[1] = flag_tmp[0];
  while (i < 8)
    {
      flag_tmp[1] = bloc._flag[1];
      flag_tmp[0] = (tmp.iint[0] ^ bloc._flag[1]) ^ bloc._flag[0];
      rotate_crypt(&tmp);
      bloc._flag[0] = flag_tmp[1];
      bloc._flag[1] = flag_tmp[0];
      i++;
    }
  while (--i >= 0)
    str[i] = bloc._char[7 - i];
  write(file->fd_out, str, 8);
}

void		my_crypt(t_parser *parser, t_file *file)
{
  int		red;
  char		buf[8];
  int		tmp;

  while ((ret = read(file->fd_in, buf, 8)) == 8)
    algo_crypt(parser, buf, file);
  if (ret == -1)
    return ;
  tmp = 8 - ret;
  while (ret < 8)
    {
      buf[ret] = (char)tmp;
      ret++;
    }
  algo_crypt(parser, buf, file);
}

int		check_mode(t_parser *parser, t_file *file)
{
  if (parser->encrypt == 1)
    {
      my_crypt(parser, file);
      return (0);
    }
  else if (parser->decrypt == 1)
    {
      my_decrypt(parser, file);
      return (0);
    }
  else
    return (-1);
}
