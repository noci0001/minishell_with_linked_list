# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 20:13:14 by snocita           #+#    #+#              #
#    Updated: 2023/06/13 17:19:47 by snocita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Seven “core” automatic variables:
# 	$@: The filename representing the target.
# 	$^: The filenames of all the prerequisites, separated by spaces. This list has duplicate filenames removed since for most uses, such as compiling, copying, etc., duplicates are not wanted.
# 	$<: The filename of the first prerequisite.
#	$%: The filename element of an archive member specification.
#	$?: The names of all prerequisites that are newer than the target, separated by spaces.
#	$+: Similar to $^, this is the names of all the prerequisites separated by spaces, except that $+ includes duplicates. This variable was created for specific situations such as arguments to linkers where duplicate values have meaning.
# 	$*: The stem of the target filename. A stem is typically a filename without its suffix. Its use outside of pattern rules is discouraged.

#Makefile Libft 

#MACROS

CC 			=	gcc
CFLAGS 		=	-Wall -Wextra -Werror
NAME 		=	libft.a
SRCS_DIR	=	src
OBJS_DIR	=	obj
RM			=	rm -rf
AR			=	ar -rcs

SRC			=	ft_isalpha ft_isdigit ft_isalnum ft_isascii \
				ft_isprint ft_strlen ft_memset ft_bzero ft_memcpy \
				ft_memmove ft_strlcpy ft_strlcat ft_toupper ft_tolower \
				ft_strchr ft_strrchr ft_strncmp ft_memchr ft_memcmp \
				ft_strnstr ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin \
				ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri ft_putchar_fd \
				ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_isspace ft_double_strdup

SRCS		=	$(addsuffix .c, $(SRC))
OBJS		=	$(addsuffix .o, $(SRC))

.c: $(SRCS)
		$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		@$(AR) libft.a $(OBJS)
		@mkdir -p $(OBJS_DIR)
		@< $(OBJS_DIR)/

all: $(NAME)
	

clean: 
	@$(RM) *.o
	@rm -rf obj/

fclean: clean
	@$(RM) $(NAME)

re: fclean all
	
.PHONY: all clean fclean re