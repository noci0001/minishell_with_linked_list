NAME	= minishell
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -rf

HEADER	= headers/minishell.h

SRCS	= src/main.c src/lexing.c src/redirection.c src/quotes_check.c \
	src/debug.c src/builtins/ft_export.c src/builtins/ft_env.c \
	src/builtins/ft_cd.c src/builtins/ft_pwd.c

SRC_DIR = src
OBJS	= $(SRCS:.c=.o)
OBJ_DIR = obj

LIBFT_PATH	= ./headers/libft
LIBFT		= $(LIBFT_PATH)/libft.a

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJS) $(LIBFT)
			@cp $(LIBFT) .
			@$(CC) $(CFLAGS) $(OBJS) libft.a -o $(NAME) -lreadline
			@mv src/*.o ./obj
			@mv src/builtins/*.o ./obj
			@touch src/debugging.txt

$(OBJ_DIR):
			mkdir $(OBJ_DIR)

$(LIBFT):
			make -sC $(LIBFT_PATH) all


clean:
		@$(RM) obj/
		@make -C $(LIBFT_PATH) clean

fclean:	clean
		@$(RM) $(NAME)
		@$(RM) libft.a get_next_line.a
		@make -C $(LIBFT_PATH) fclean
		@rm -rf src/debugging.txt

re:		fclean all