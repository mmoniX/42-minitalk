CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF_PATH = ft_printf
PRINTF_ARCHIVE = $(PRINTF_PATH)/libftprintf.a

C_SRC =	client.c utils.c
S_SRC =	server.c

C_OBJ = $(C_SRC:.c=.o)
S_OBJ = $(S_SRC:.c=.o)

C_NAME = client
S_NAME = server

all: $(C_NAME) $(S_NAME)
bonus:	all

$(C_NAME): $(C_OBJ) $(PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) -o $(C_NAME) $(C_OBJ) $(PRINTF_ARCHIVE)

$(S_NAME): $(S_OBJ) $(PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) -o $(S_NAME) $(S_OBJ) $(PRINTF_ARCHIVE)

$(PRINTF_ARCHIVE):
	$(MAKE) -C $(PRINTF_PATH) all

clean:
	$(MAKE) -C $(PRINTF_PATH) clean
	rm -f $(C_OBJ) $(S_OBJ)

fclean: clean
	$(MAKE) -C $(PRINTF_PATH) fclean
	rm -f $(C_NAME) $(S_NAME)

re: fclean all