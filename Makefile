NAME = push_swap
CFLAGS = -Wall -Werror -Wextra
SRCS = main.c input_checker.c input_checker_utils.c utils.c initialisation.c stack.c

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
