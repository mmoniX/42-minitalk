CC = cc
CFLAGS = -Wall -Wextra -Werror -I42-printf

OBJ_DIR = obj
C_SRC =	client.c utils.c
S_SRC =	server.c
C_OBJ = $(C_SRC:%.c=$(OBJ_DIR)/%.o)
S_OBJ = $(S_SRC:%.c=$(OBJ_DIR)/%.o)

C_NAME = client
S_NAME = server

PRINTF_DIR = 42-printf
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(PRINTF) $(C_NAME) $(S_NAME)

$(PRINTF_DIR):
	git clone https://github.com/mmoniX/42-printf.git

$(PRINTF): $(PRINTF_DIR)
	@echo "\033[34m🔄 Loading....\033[0m"
	@$(MAKE) -C $(PRINTF_DIR)

$(OBJ_DIR)/%.o: %.c
	@mkdir	-p	$(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(C_NAME): $(C_OBJ) $(PRINTF)
	@$(CC) $(CFLAGS) -o $(C_NAME) $(C_OBJ) $(PRINTF)

$(S_NAME): $(S_OBJ) $(PRINTF)
	@$(CC) $(CFLAGS) -o $(S_NAME) $(S_OBJ) $(PRINTF)
	@echo "\033[32m🚀 Program is ready to execute\033[0m"
	@echo "\033[33mPlease call the SERVER first\033[0m"

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(PRINTF_DIR) fclean
	@echo "\033[31mProgram removed\033[0m"

fclean: clean
	@rm -f $(C_NAME) $(S_NAME)
	@rm -f $(PRINTF)

re: fclean all

bonus:	all

.PHONY: all clean fclean re bonus
