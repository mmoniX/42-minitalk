CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC =	ft_printf.c ft_char.c ft_str.c ft_pointer.c \
		ft_nbr.c ft_unsigned_nbr.c ft_lowhex.c ft_caphex.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all