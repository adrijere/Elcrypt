/*
** check_struct.c for elcrypt in /home/cardon_v/Documents/PSU/elcrypt/source
** 
** Made by Valentin Cardon
** Login   <cardon_v@epitech.net>
** 
** Started on  Sat Mar 14 21:09:15 2015 Valentin Cardon
** Last update Sat Mar 14 23:40:52 2015 Valentin Cardon
*/

#include	"elcrypt.h"

int		check_crypt(t_parser *p)
{
  if (p->decrypt == 1 && p->encrypt == 1)
    {
      printf("Wrong parameters:\n");
      printf("You can't decrypt and encrypt at the same time\n");
      return (-1);
    }
  return (0);
}

int		check_in_out(t_parser *p)
{
  if (p->file_in != 1 && p->file_out != 1)
    {
      printf("Wrong parameters:\n");
      printf("You must give a source file to decrypt/encrypt ");
      printf("and an output file to save the result\n");
      return (-1);
    }
  return (0);
}

int		check_file(t_parser *p, t_file *f)
{
  if ((f->fd_in = open(p->name_in, O_RDONLY)) == -1)
    {
      printf("Wrong paramaters:\n");
      printf("File \"%s\" doesn't exist\n", p->name_in);
      return (-1);
    }
  if ((f->fd_in = open(p->name_out, O_CREAT | O_RDWR | O_TRUNC, 0644)) == -1)
    {
      printf("Wrong parameters:\n");
      printf("Their is an error with \"%s\" output file\n",
	     p->name_out);
      return (-1);
    }
  return (0);
}

int		check_key(t_parser *parser)
{
  (void)parser;
  return (0);
}

int		check_struct(t_parser *parser, t_file *file)
{
  if (check_crypt(parser) == -1)
    return (-1);
  if (check_in_out(parser) == -1)
    return (-1);
  if (check_file(parser, file) == -1)
    return (-1);
  if (check_key(parser) == -1)
    return (-1);
  return (0);
}
