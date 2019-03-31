NAME		= libfts.a

CC			= gcc
MYCFLAGS	= -Wall -Werror -Wextra -I inc

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
			  ft_isascii.s \
			  ft_toupper.s \
			  ft_tolower.s \
			  ft_puts.s \
			  ft_memset.s \
			  ft_memcpy.s \
			  ft_strdup.s \
			  ft_cat.s \

SRC			= $(addprefix src/, $(FILES))
OBJ			= $(addprefix obj/, $(FILES:.s=.o))

MAIN		= main.c
TESTEXEC	= libftasm_tests

# ---------------------------------------------------------------------------- #

BLUE		= \033[38;5;105;1m
GREEN		= \033[1;32m
ORANGE		= \033[38;5;202;1m
NO_COLOR    = \033[m

all: $(NAME)

$(NAME): $(SRC) $(OBJ) $(MAIN)
	@mkdir -p bin/
	@printf "%b" "$(GREEN)Creating Archive: $(BLUE)$(NAME)\n$(NO_COLOR)"
	@ar rcs $(NAME) $(OBJ)
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
	@rm -f bin/$(TESTEXEC)

test: all
	@printf "Compiling $(TESTEXEC).\n\n"
	@$(CC) $(MYCFLAGS) $(CFLAGS)
	@mv $(NAME) bin/

re: fclean all

.PHONY: clean fclean all re
