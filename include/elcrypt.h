/*
** elcrypt.h for elcrypt in /home/cardon_v/Documents/PSU/elcrypt/include
** 
** Made by Valentin Cardon
** Login   <cardon_v@epitech.net>
** 
** Started on  Sat Mar 14 11:08:00 2015 Valentin Cardon
** Last update Sat Mar 14 16:05:14 2015 Valentin Cardon
*/

#ifndef		_ELCRYPT_H_
#define		_ELCRYPT_H_

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

typedef struct	s_parser
{
  int		decrypt;
  int		encrypt;
  int		file_in;
  int		file_out;
  int		key;
  char		*name_in;
  char		*name_out;
  char		*name_key;
}		t_parser;

t_parser	*parser(char **);

#endif		/* _ELCRYPT_H_ */
