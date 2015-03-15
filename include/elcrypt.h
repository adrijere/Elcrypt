/*
** elcrypt.h for elcrypt in /home/cardon_v/Documents/PSU/elcrypt/include
** 
** Made by Valentin Cardon
** Login   <cardon_v@epitech.net>
** 
** Started on  Sat Mar 14 11:08:00 2015 Valentin Cardon
** Last update Sun Mar 15 18:14:24 2015 Jérémy MATHON
*/

#ifndef		_ELCRYPT_H_
#define		_ELCRYPT_H_

# include	<stdio.h>
# include	<stdlib.h>
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<string.h>
# include	<unistd.h>

typedef	union	u_key
{
  unsigned int	iint[2];
  unsigned char	cchar[8];
  unsigned long	llong;
}		u_key;

typedef	union		u_bloc
{
  unsigned	int	_flag[2];
  unsigned	char	_char[8];
}			u_bloc;

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
  u_key		*key_prim;
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
u_key		*get_key_prim(t_parser *);
void		rotate_crypt(u_key *);
void		rotate_decrypt(u_key *, u_key *, int);
void		my_decrypt(t_parser *, t_file *);
void		my_crypt(t_parser *, t_file *);
int		check_mode(t_parser *, t_file *);
#endif		/* _ELCRYPT_H_ */
