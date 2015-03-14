/*
** main.c for elcrypt in /home/cardon_v/Documents/PSU/elcrypt/source
** 
** Made by Valentin Cardon
** Login   <cardon_v@epitech.net>
** 
** Started on  Sat Mar 14 11:05:19 2015 Valentin Cardon
** Last update Sat Mar 14 16:11:16 2015 Valentin Cardon
*/

# include	"elcrypt.h"

/*
./elcrypt -d -f source -o output -k key
./elcrypt -e -f source -o output -k key
*/

void		print_usage()
{
  printf("Usage:\n");
  printf("./elcrypt [OPTION]\n");
  printf("\t-d\t\tDecrypt\n\t-e\t\tEncrypt\n");
  printf("\t-f [FILE]\tFile to decrypt/encrypt\n");
  printf("\t-o [FILE]\tOutput result file\n");
  printf("\t-k [KEY]\tPrimary key in 64bits\n\n");
  printf("Exemple:\n");
  printf("./elcrypt [-d]/[-e] [-f] [SOURCE] [-o] [FILE] [-k] [key]\n");  
  printf("Decrypt/encrypt [SOURCE] file in [FILE] with the [KEY] key\n");
}

int		main(int ac, char **av)
{
  t_parser	*struc;

  if (ac < 7)
    {
      print_usage();
      return (0);
    }
  if ((struc = parser(av)) == NULL)
    return (0);
  return (0);
}
