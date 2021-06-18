##
## EPITECH PROJECT, 2019
## CPool_bistro-matic_2019
## File description:
## Makefile
##

SRC  =  my_getnbr.c\
		my_putchar.c\
		my_put_nbr.c\
		my_putstr.c\
		my_revstr.c\
		my_show_word_array.c\
		my_strcat.c\
		my_strcmp.c\
		my_strcpy.c\
		my_strdup.c\
		my_str_isalpha.c\
		my_str_islower.c\
		my_str_isupper.c\
		my_str_isnum.c\
		my_str_isprintable.c\
		my_strlen.c\
		my_strncat.c\
		my_strncmp.c\
		my_strncpy.c\
		my_swap.c\
		my_atof.c\
		my_str_to_wordtab.c\
		my_str_to_wordtab_t.c\
		realloc.c\
		base_converter.c\
		my_clean_str.c\
		my_itoa.c\
		freetab.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS =	-I../../include

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:	fclean all