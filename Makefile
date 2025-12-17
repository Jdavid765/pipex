CC = gcc
NAME = pipex
CFLAGS = -Wall -Werror -Wextra -g
DIRPRINTF = printf
PRINTF = $(DIRPRINTF)/libftprintf.a
DIRLIBFT = libft
LIBFT = $(DIRLIBFT)/libft.a
SRC = utils.c\
	main.c
OBJ = $(SRC:.c=.o)
RM = rm -rf

# --------------------------------------------------------
#        BARRE DE PROGRESSION (ROSE) POUR COMPILATION
# --------------------------------------------------------

NB := $(words $(SRC))
BARLEN = 30

%.o: %.c
	@$(eval CNT := $(shell ls $(DIRPRINTF)/*.o 2>/dev/null | wc -l))
	@$(eval PROG := $(shell echo $$(($(CNT) * 100 / $(NB))) ))
	@$(eval FILLED := $(shell echo $$(($(PROG) * $(BARLEN) / 100)) ))
	@$(eval EMPTY := $(shell echo $$(($(BARLEN) - $(FILLED))) ))

	@printf "\r\033[35m[%s%s] %3s%%\033[0m  \033[90m(%s)\033[0m" \
		$$(printf '#%.0s' $$(seq 1 $(FILLED))) \
		$$(printf '.%.0s' $$(seq 1 $(EMPTY))) \
		"$(PROG)" "$<"

	@$(CC) $(CFLAGS) -c $< -o $@

# --------------------------------------------------------

all : $(LIBFT) $(PRINTF) $(NAME)

$(LIBFT):
	$(MAKE) -C $(DIRLIBFT) --no-print-directory > /dev/null

$(PRINTF):
	$(MAKE) -C $(DIRPRINTF) --no-print-directory > /dev/null

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(PRINTF) $(LIBFT) $(CFLAGS) -o $(NAME)

clean :
	$(RM) $(OBJ)
	$(MAKE) -C $(DIRPRINTF) clean --no-print-directory > /dev/null
	$(MAKE) -C $(DIRLIBFT) clean --no-print-directory > /dev/null

fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(DIRPRINTF) fclean --no-print-directory > /dev/null
	$(MAKE) -C $(DIRLIBFT) fclean --no-print-directory > /dev/null

re : fclean all

.PHONY : all clean fclean re