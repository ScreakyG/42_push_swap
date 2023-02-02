NAME = push_swap
CFLAGS = -Wall -Werror -Wextra -g
SRCS = main.c input_checker.c input_checker_utils.c utils.c initialisation.c stack.c swap.c rotate.c sort_tiny.c reverse_rotate.c sort.c push.c cost.c do_move.c position.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
			gcc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -f $(OBJS)

fclean: clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
