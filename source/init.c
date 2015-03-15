/*
** init.c for elcrypt in /home/cardon_v/Documents/PSU/elcrypt/source
** 
** Made by Valentin Cardon
** Login   <cardon_v@epitech.net>
** 
** Started on  Sat Mar 14 21:49:52 2015 Valentin Cardon
** Last update Sun Mar 15 01:19:12 2015 Valentin Cardon
*/

#include	"elcrypt.h"

t_parser	*init_parser()
{
  t_parser	*tmp;

  tmp = malloc(sizeof(t_parser));
  tmp->decrypt = 0;
  tmp->encrypt = 0;
  tmp->file_in = 0;
  tmp->file_out = 0;
  tmp->name_in = NULL;
  tmp->name_out = NULL;
  tmp->key_string = NULL;
  tmp->key_prim = NULL;
  return (tmp);
}

t_file		*init_file()
{
  t_file	*tmp;

  tmp = malloc(sizeof(t_file));
  tmp->fd_in = 0;
  tmp->fd_out = 0;
  return (tmp);
}
