NAME	=	my_diff

SRC	=	main.c			\
		FilesFunctions.c	\
		ArgumentsFunctions.c

OBJS	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-W -Wall -Werror


$NAME: $(OBJS)
	$(CC)  $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
	rm -f $(OBJS)

distclean:	clean
	rm -f $(NAME)

rebuild:	distclean all
