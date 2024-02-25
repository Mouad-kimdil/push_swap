SRCS = push_swap.c push_swap_helper.c push_swap_err.c \
		push_swap_is_double.c push_swap_lists.c split.c \
		push_swap_init_stack.c push_swap_strings.c \
		push_swap_instructions.c push_swap_instruction2.c \
		push_swap_message.c push_swap_instructions3.c \
		push_swap_sort.c push_swap_indexing.c \
		
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