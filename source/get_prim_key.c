/*
** get_prim_key.c for elcrypt in /home/cardon_v/Documents/PSU/elcrypt/source
** 
** Made by Valentin Cardon
** Login   <cardon_v@epitech.net>
** 
** Started on  Sun Mar 15 01:07:23 2015 Valentin Cardon
** Last update Sun Mar 15 01:15:34 2015 Valentin Cardon
*/

#include	"elcrypt.h"

u_key		*get_key_prim(t_parser *parser)
{
  int		i;
  unsigned char	tmp;
  u_key		*key_prim;
  u_key		key_second;

  i = 0;
  if ((key_prim = malloc(sizeof(u_key))) == NULL)
    return (NULL);
  key_second.llong = strtoul(parser->key_string, NULL, 16);
  key_prim->llong = 0;
  while (i < 8)
    {
      tmp = (key_second.cchar[1] >> 1);
      key_prim->llong = key_prim->llong | ((unsigned long)tmp << (7 * i));
      i++;
    }
  return (key_prim);
}
