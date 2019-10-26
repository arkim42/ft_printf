# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arkim <arkim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 20:40:49 by arkim             #+#    #+#              #
#    Updated: 2019/09/05 20:50:14 by arkim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	= 	$(wildcard *.c)
OBJS	=	$(SRCS:.c=.o)

GREEN	=	\033[0;32m
RED		=	\033[0;31m
RESET	=	\033[0m
CHECK	=	\033[0;33m\xE2\x9C\x94\033[0m

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\r $(CHECK)$(GREEN)      Libft has been compiled! (100/100%)"

$(OBJS) :
	@echo "\n$(RED)         Compiling Libft    .....\c"
	@$(CC) $(CFLAGS) -c $(SRCS)

clean :
	@/bin/rm -rf $(OBJS)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
