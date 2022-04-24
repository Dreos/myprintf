SRCS = 	sources/ft_printf.c \
	sources/display1.c \
	sources/display2.c \
	sources/utils.c \


OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a 

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

all: ${NAME}

$(NAME): ${OBJS}
	ar -rc ${NAME} ${OBJS}
	ranlib ${NAME}

%o: %c 
	${CC} ${CFLAGS} -c $< -o $@


clean:
	${RM} ${OBJS}

fclean: clean 
	${RM} ${NAME}

re: fclean all

.PHONY: re clean fclean all
