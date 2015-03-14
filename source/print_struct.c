/*
** print_struct.c for elscrypt in /home/cardon_v/Documents/PSU/elcrypt/source
** 
** Made by Valentin Cardon
** Login   <cardon_v@epitech.net>
** 
** Started on  Sat Mar 14 21:04:54 2015 Valentin Cardon
** Last update Sat Mar 14 21:38:06 2015 Valentin Cardon
*/

#include	"elcrypt.h"

void            print_struct(t_parser *parser)
{
  printf("decrypt => %d\n", parser->decrypt);
  printf("encrypt => %d\n", parser->encrypt);
  printf("file_in => %d\n", parser->file_in);
  printf("file_out => %d\n", parser->file_out);
  printf("key => %d\n", parser->key);
  printf("name_in => %s\n", parser->name_in);
  printf("name_out => %s\n", parser->name_out);
  printf("key_string=> %s\n", parser->key_string);
}
