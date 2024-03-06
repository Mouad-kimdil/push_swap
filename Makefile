SRCS =  cheapest.c check_err.c do_move.c get_target.c init_stack.c \
		is_double.c lists.c push_swap.c push.c utils.c strings.c \
		reverse_rotate.c rotate.c shift_stack.c swap.c \
		sort.c split.c 
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