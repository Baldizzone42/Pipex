CC 		= clang
NAME 	= pipex
CFLAGS 	= -Wall -Wextra -Werror -fsanitize=address
LIBFT = libft
SRC_DIR = src/
OBJ_DIR = obj/
PIPEX_H = $(NAME).h

MAGENTA = \033[35;1m
YELLOW  = \033[33;1m
GREEN   = \033[32;1m
WHITE   = \033[37;1m
RESET   = \033[0m
GRAY 	= \033[0;90m
BLUE    = \033[34;1m
CYAN    = \033[37;1m
BOLD	= \033[1m
RED		= \033[31;1m

SRC_FILES = main child_process path \

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o,$(SRC_FILES)))

OBJF = .cache_exists

all: $(NAME)

$(NAME): compiling $(OBJ)
		@echo
		@make all -C $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -o $(NAME)
		@echo "$(YELLOW)Pipex compiled!$(RESET)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(PIPEX_H)| $(OBJF)
		@mkdir -p $(dir $@)
		@echo "$(GREEN)Compiling: $(RESET)$(notdir $<)"
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
		@mkdir -p $(OBJ_DIR)
		
compiling:
		@echo "$(GREEN)Compiling Pipex: $(RESET)"

clean:
		@rm -rf $(OBJ_DIR)
		@make clean -C $(LIBFT)
		@echo "$(BLUE)Cleaning Pipex's objects. $(RESET)"
		@echo

fclean:
		@rm -rf $(OBJ_DIR)
		@rm -rf $(NAME)
		make fclean -C $(LIBFT)
		@echo "$(BLUE)Cleaning Pipex's executables.$(RESET)"

re: fclean all

.PHONY: all clean fclean re compiling