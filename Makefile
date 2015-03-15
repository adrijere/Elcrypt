##
## Makefile for elcrypt in /home/cardon_v/Documents/PSU/elcrypt
## 
## Made by Valentin Cardon
## Login   <cardon_v@epitech.net>
## 
## Started on  Sat Mar 14 11:00:30 2015 Valentin Cardon
## Last update Sun Mar 15 01:15:07 2015 Valentin Cardon
##

NAME		=	elcrypt

SRC		=	source/main.c		\
			source/parser.c		\
			source/init.c		\
			source/check_struct.c	\
			source/get_prim_key.c	\
			source/print_struct.c

OBJ		=	$(SRC:.c=.o)

TMP		=	$(SRC:.c=.c~)

CFLAGS		=	-W -Wall -ansi -pedantic -I include/

all		:	$(NAME)

$(NAME)		:	$(OBJ)
			cc -o $(NAME) $(OBJ) $(CFLAGS)

clean		:
			rm -rf $(TMP) $(OBJ)

fclean		:	clean
			rm -rf $(NAME)

re		:	fclean	all
