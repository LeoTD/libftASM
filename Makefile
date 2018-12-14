NAME		= libftASM

CC			= gcc
CFLAGS		+= -Wall -Werror -Wextra
CFLAGS		+= -I inc
CFLAGS		+= -g

ASM			= nasm
SFLAGS		+= -f macho64

FILES		= ft_strlen.s \
			  ft_bzero.s \
			  ft_strcat.s \
			  ft_isupper.s \
			  ft_islower.s \
			  ft_isalpha.s \
			  ft_isdigit.s \
			  ft_isalnum.s \
			  ft_isprint.s \

SRC			= $(addprefix src/, $(FILES))
OBJ			= $(addprefix obj/, $(FILES:.s=.o))

MAIN		= main.c

# ---------------------------------------------------------------------------- #

BLUE		= \033[38;5;105;1m
GREEN		= \033[1;32m
ORANGE		= \033[38;5;202;1m
NO_COLOR    = \033[m

all: $(NAME)

$(NAME): $(SRC) $(OBJ) $(MAIN)
	@mkdir -p bin/
	@printf "%b" "$(GREEN)Compiling: $(BLUE)$(NAME)\n$(NO_COLOR)"
	@$(CC) $(DEBUG) $(CFLAGS) -o $(NAME) $(MAIN) $(OBJ)
	@mv $(NAME) bin/

obj:
	@mkdir -p obj/

obj/%.o: src/%.s | obj
	@printf "%b" "$(GREEN)Compiling: $(ORANGE)$@\n$(NO_COLOR)"
	@$(ASM) $(SFLAGS) $< -o $@

clean:
	@printf "Cleaning up $(NAME)...\n"
	@rm -rf obj/

fclean: clean
	@rm -f bin/$(NAME)
	@rm -f $(NAME)

run: all
	@printf "Running $(NAME).\n\n"
	@bin/$(NAME)

re: fclean all

.PHONY: clean fclean all re
