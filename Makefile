NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror

SRC =	ft_printf.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_puthex.c \
		ft_putchar.c \
		ft_putptr.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) *.o

all: $(NAME)

.c.o:
	cc	$(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean