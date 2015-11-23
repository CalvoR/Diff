NAME	=	my_diff

SRC	=	main.c			\
		Liste.c			\
		find_difference.c	

OBJS	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-W -Wall 

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC)   -o $(NAME) $(OBJS) 


clean:
	rm -f $(OBJS)

distclean:	clean
	rm -f $(NAME)

rebuild:	distclean all
