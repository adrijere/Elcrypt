/*
** elcrypt.h for elcrypt in /home/cardon_v/Documents/PSU/elcrypt/include
** 
** Made by Valentin Cardon
** Login   <cardon_v@epitech.net>
** 
** Started on  Sat Mar 14 11:08:00 2015 Valentin Cardon
** Last update Sat Mar 14 23:56:22 2015 Valentin Cardon
*/

#ifndef		_ELCRYPT_H_
#define		_ELCRYPT_H_

#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
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
  char		*key_string;
}		t_parser;

typedef struct	s_file
{
  int		fd_in;
  int		fd_out;
}		t_file;

t_parser	*init_parser();
t_file		*init_file();
t_parser	*parser(char **);
int		check_struct(t_parser *, t_file *);
void		print_struct(t_parser *);

#endif		/* _ELCRYPT_H_ */
