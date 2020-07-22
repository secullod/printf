SRC	=	ft_printf.c \
print_stuff.c \
print_stuff_too.c \
help_print_stuff.c \
help_print_stuff_too.c \
general.c \
general_too.c \
general_too_too.c \
general_too_too_too.c \

OBJS =	${SRC:.c=.o}

INCLUDES =	includes

NAME =	libftprintf.a

CC =	gcc

FLAGS	=	-Wall -Werror -Wextra

all: ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCLUDES}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

clean:
	rm -f ${OBJS}

fclean: 	clean
	rm -f ${NAME}

re: 		fclean all

.PHONY: clean all fclean re
