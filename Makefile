SRCS = push_swap.c push_swap_helper.c
INC = push_swap.h
NAME = push_swap
CC = cc
FLAGS = -Wall -Wextra -Werror
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

%.o: %.c ${INC}
	${CC} ${FLAGS} -c $<

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re