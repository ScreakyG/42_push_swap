NAME = push_swap
CFLAGS = -Wall -Werror -Wextra
SRCS = main.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
			make -C libft/
			gcc $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			rm -f $(OBJS)
			@cd libft && $(MAKE) clean

fclean: clean
			rm -f $(NAME)
			@cd libft && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
