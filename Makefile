SRCS = cheapest.c check_err.c do_move.c get_target.c init_stack.c \
	   is_double.c lists.c push_swap.c push.c utils.c strings.c \
	   reverse_rotate.c rotate.c shift_stack.c swap.c sort.c split.c
SRCS_BONUS = check_err.c init_stack.c is_double.c lists.c \
			push.c utils.c strings.c reverse_rotate.c rotate.c \
			push_swap_bonus.c get_next_line_bonus.c swap.c \
			get_next_line_utils_bonus.c split.c get_target.c \
			instruction_bonus.c instruction2_bonus.c shift_stack.c
INC = push_swap.h
NAME = push_swap
NAME_BONUS = checker
CC = cc
FLAGS = -Wall -Wextra -Werror
OBJS = $(addprefix obj/, $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix obj/, $(SRCS_BONUS:.c=.o))

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS}
	${CC} ${FLAGS} ${OBJS_BONUS} -o ${NAME_BONUS}

obj/%.o: %.c ${INC}
	@mkdir -p $(dir $@)
	${CC} ${FLAGS} -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -rf ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re bonus
