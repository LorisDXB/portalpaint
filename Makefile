##
## EPITECH PROJECT, 2023
## secured
## File description:
## Makefile
##

LIB =   lib/my/my_putchar.c     \
		lib/my/my_put_nbr.c     \
		lib/my/my_putstr.c      \
		lib/my/my_strcmp.c      \
		lib/my/my_strncmp.c		\
		lib/my/my_strlen.c      \
		lib/my/my_printf.c      \
		lib/my/uconv.c  \
		lib/my/pconv.c  \
		lib/my/hexconv.c        \
		lib/my/majhexconv.c     \
		lib/my/octalconv.c      \
		lib/my/nflag.c  \
		lib/my/fflag.c  \
		lib/my/eflag.c  \
		lib/my/maj_eflag.c \
		lib/my/gflag.c  \
		lib/my/maj_gflag.c      \
		lib/my/my_nbrlen.c      \
		lib/my/my_strcat.c      \
		lib/my/my_strcpy.c	\
		lib/my/str_to_word_array.c	\
		lib/my/my_atoi.c	\
		lib/my/my_getnbr.c		\
		lib/my/str_to_word_array_collumn.c	\
		lib/my/str_to_word_array_n.c	\
		lib/my/my_tabcpy.c				\
		lib/my/my_strdup.c

SRC = 	src/main.c		\
		src/destroy_everything.c	\
		src/drawing_handler.c	\
		src/draw_sprites.c	\
		src/drop_menu.c	\
		src/get_color.c	\
		src/handle_events.c	\
		src/handling_button.c	\
		src/init_about.c	\
		src/init_shortcut.c		\
		src/init_toolbox.c	\
		src/save_from_pixels.c	\
		src/button_click.c		\
		src/newfile_handler.c	\

CFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -lm

NAME = libmy.a

NAME2 = portalpaint

OBJ = $(LIB:.c=.o)

all: compil fclean

compil:	$(OBJ)
		ar rc $(NAME) lib/my/*.o
		gcc -o $(NAME2) $(SRC) -L./ -lmy $(CFLAGS)

clean:
		rm -f *~
		rm -f #*#

fclean: clean
		rm -f lib/my/*.o
		rm -f src/*.o
		rm -f libmy.a
		rm -f  *.log
		rm -f $(NAME)

re: fclean all
