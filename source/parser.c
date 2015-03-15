/*
** parser.c for elcrypt in /home/cardon_v/Documents/PSU/elcrypt/source
** 
** Made by Valentin Cardon
** Login   <cardon_v@epitech.net>
** 
** Started on  Sat Mar 14 15:32:00 2015 Valentin Cardon
** Last update Sun Mar 15 00:16:24 2015 Valentin Cardon
*/

# include	"elcrypt.h"

char		*file_struct(char *arg)
{
  int		len;
  char		*str;

  len = strlen(arg);
  str = malloc(sizeof(char) * len + 1);
  str = strncpy(str, arg, len);
  str[len] = '\0';
  return (str);
}

t_parser	*put_in_struct(char **av, t_parser *parser)
{
  if (strncmp(av[1], "-d", 2) == 0)
    parser->decrypt = 1;
  else if (strncmp(av[1], "-e", 2) == 0)
    parser->encrypt = 1;
  if (strncmp(av[2], "-f", 2) == 0)
    {
      parser->file_in = 1;
      parser->name_in = file_struct(av[3]);
    }
  if (strncmp(av[4], "-o", 2) == 0)
    {
      parser->file_out = 1;
      parser->name_out = file_struct(av[5]);
    }
  if (strncmp(av[6], "-k", 2) == 0)
    {
      parser->key = 1;
      parser->key_string = file_struct(av[7]);
    }
  return (parser);
}

t_parser	*parser(char **av)
{
  t_parser	*parser;
  t_file	*file;

  parser = init_parser();
  file = init_file();
  parser = put_in_struct(av, parser);
  print_struct(parser);
  if (check_struct(parser, file) == -1)
    return (NULL);
  return (parser);
}
