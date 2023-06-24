# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 15:24:15 by snocita           #+#    #+#              #
#    Updated: 2023/06/24 16:30:03 by amurawsk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -rf

HEADER	= headers/minishell.h

SRCS	= src/main.c src/lexing.c src/execution/redirection.c

SRC_DIR = src
OBJS	= $(SRCS:.c=.o)
OBJ_DIR = obj

LIBFT_PATH	= ./headers/libft
LIBFT		= $(LIBFT_PATH)/libft.a

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJS) $(LIBFT)
			cp $(LIBFT) .
			@$(CC) $(CFLAGS) $(OBJS) libft.a -o $(NAME) -lreadline
			mv src/*.o ./obj

$(OBJ_DIR):
			mkdir $(OBJ_DIR)

$(LIBFT):
			make -sC $(LIBFT_PATH) all


clean:
		@$(RM) obj/
		make -C $(LIBFT_PATH) clean

fclean:	clean
		@$(RM) $(NAME)
		$(RM) libft.a get_next_line.a
		make -C $(LIBFT_PATH) fclean

re:		fclean all