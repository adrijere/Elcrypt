/*
** rotate_key.c for elcrypt in /home/cardon_v/Documents/PSU/elcrypt/source
** 
** Made by Valentin Cardon
** Login   <cardon_v@epitech.net>
** 
** Started on  Sun Mar 15 17:32:28 2015 Valentin Cardon
** Last update Sun Mar 15 17:36:59 2015 Valentin Cardon
*/

#include	"elcrypt.h"

void		rotate_crypt(u_key *key)
{
  unsigned long	tmp;
  unsigned long ttmp;

  tmp = (key->llong << 4);
  ttmp = (key->llong >> (56 - 4));
  key->llong = tmp | ttmp;
  key->cchar[7] = 0;
}
