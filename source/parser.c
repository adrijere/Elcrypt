/*
** parser.c for elcrypt in /home/cardon_v/Documents/PSU/elcrypt/source
** 
** Made by Valentin Cardon
** Login   <cardon_v@epitech.net>
** 
** Started on  Sat Mar 14 15:32:00 2015 Valentin Cardon
** Last update Sat Mar 14 16:21:47 2015 Valentin Cardon
*/

# include	"elcrypt.h"

void		print_struct(t_parser *parser)
{
  printf("decrypt => %d\n", parser->decrypt);
  printf("encrypt => %d\n", parser->encrypt);
  printf("file_in => %d\n", parser->file_in);
  printf("file_out => %d\n", parser->file_out);
  printf("key => %d\n", parser->key);
  printf("name_in => %s\n", parser->name_in);
  printf("name_out => %s\n", parser->name_out);
  printf("name_key=> %s\n", parser->name_key);
}

t_parser	*init_struct()
{
  t_parser	*tmp;

  tmp = malloc(sizeof(t_parser));
  tmp->decrypt = 0;
  tmp->encrypt = 0;
  tmp->file_in = 0;
  tmp->file_out = 0;
  tmp->name_in = NULL;
  tmp->name_out = NULL;
  tmp->name_key = NULL;
  return (tmp);
}

char		*file_struct(char *arg)
{
  int		len;
  char		*str;

  len = strlen(arg);
  str = malloc(sizeof(char) * len + 1);
  str = strdup(arg);
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
      parser->name_key = file_struct(av[7]);
    }
  return (parser);
}

t_parser	*parser(char **av)
{
  t_parser	*parser;
  
  parser = init_struct();
  parser = put_in_struct(av, parser);
  print_struct(parser);
  return (parser);
}
