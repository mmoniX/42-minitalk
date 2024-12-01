CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF_PATH = ft_printf
PRINTF_ARCHIVE = $(PRINTF_PATH)/libftprintf.a

C_SRC =	client.c utils.c
S_SRC =	server.c
C_NAME = client
S_NAME = server

CB_SRC = client_bonus.c utils.c
SB_SRC = server_bonus.c
CB_NAME = client_bonus
SB_NAME = server_bonus

all: $(C_NAME) $(S_NAME)
bonus:	$(CB_NAME) $(SB_NAME)

$(C_NAME): $(C_SRC) $(PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) -o $(C_NAME) $(C_SRC) $(PRINTF_ARCHIVE)

$(S_NAME): $(S_SRC) $(PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) -o $(S_NAME) $(S_SRC) $(PRINTF_ARCHIVE)

$(CB_NAME): $(CB_SRC) $(PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) -o $(CB_NAME) $(CB_SRC) $(PRINTF_ARCHIVE)

$(SB_NAME): $(SB_SRC) $(PRINTF_ARCHIVE)
	$(CC) $(CFLAGS) -o $(SB_NAME) $(SB_SRC) $(PRINTF_ARCHIVE)

$(PRINTF_ARCHIVE):
	$(MAKE) -C $(PRINTF_PATH)

clean:
	$(MAKE) -C $(PRINTF_PATH) clean

fclean: clean
	$(MAKE) -C $(PRINTF_PATH) fclean
	rm -f $(C_NAME) $(S_NAME) $(CB_NAME) $(SB_NAME)

re: fclean all