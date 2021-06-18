##
## EPITECH PROJECT, 2019
## DEFENDER
## File description:
## Makefile
##

SRC		=	src/main.c						\
			src/usage.c						\
			src/destroy.c  					\
			src/generate_from_file.c 		\
			src/verif_params.c 				\
			src/particles.c					\
			src/init/init.c      			\
			src/init/init2.c				\
			src/sprite/create_sprite.c		\
			src/sprite/move_player.c		\
			src/sprite/collision.c			\
			src/sprite/portal.c 			\
			src/sprite/overlay.c 			\
			src/intro/intro.c 				\
			src/game_menu/main_menu.c		\
			src/game_menu/inventory_menu.c  \
			src/game_menu/shop.c 			\
			src/game_menu/settings_menu.c 	\
			src/game_menu/htp.c 			\
			src/game_menu/pause_menu.c 		\
			src/game_menu/win.c 			\
			src/pointeur/pointeur.c			\
			src/pointeur/pointeur2.c		\
			src/pointeur_w/pointeur_w.c		\
			src/pointeur_w/pointeur_w_2.c	\
			src/pointeur_w/pointeur_w_3.c	\
			src/talk/create.c				\
			src/utils/utils.c				\
			src/sound/sound.c				\
			src/enemies/init.c				\
			src/enemies/display.c			\

NAME	=	my_rpg

COMPIL	=	-Llib/my -lmy

CFLAGS	+=	-I include/

CSFML	= 	-l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		gcc -o $(NAME) $(SRC) $(COMPIL) $(CFLAGS) $(CSFML)

clean:
		rm -f $(OBJ)
		make clean -C lib/my

fclean:	clean
		rm -f $(NAME)
		make fclean -C lib/my

re:		fclean all

debug:	CFLAGS += -Wall -Wextra
debug:	$(OBJ)
		make -C lib/my
		make clean -C lib/my
		gcc -o $(NAME) $(SRC) $(COMPIL) -g $(CFLAGS) $(CSFML)

.PHONY: all clean fclean re debug