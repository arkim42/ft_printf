# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arkim <arkim@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/17 16:46:43 by arkim             #+#    #+#              #
#    Updated: 2020/01/24 22:42:00 by arkim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
LIB_FT_DIR	=	./libft/
LIB_FT_LNK	=	-L libft -lft

DIR_S		=	./srcs/
DIR_O		=	./objs/
DIR_I		=	./includes/

SRCS		=	$(wildcard $(DIR_S)*.c)
OBJS		=	$(addprefix $(DIR_O), $(notdir $(SRCS:.c=.o)))

GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m
CHECK		=	\033[0;33m\xE2\x9C\x94\033[0m
PINK		=	\033[0;1;35m
YELLOW		=	\033[0;33m

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB_FT_DIR)
	@cp libft/libft.a $(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\r $(CHECK)$(GREEN)      $(NAME) has been compiled! (100/100%)"

$(DIR_O)%.o: $(DIR_S)%.c $(DIR_I)ft_printf.h
	@mkdir -p $(DIR_O)
	@$(CC) $(CFLAGS) -I $(DIR_I) -o $@ -c $<

gccW:
	@$(CC) $(CFLAGS) main.c $(SRCS) $(LIB_FT_DIR)/srcs/*.c -I $(DIR_I) -I $(LIB_FT_DIR)includes/
	@echo "\n $(CHECK)$(PINK)	Finished !!"

gcc:
	@$(CC) $(SRCS) main.c $(LIB_FT_DIR)srcs/*.c -I $(DIR_I) -I $(LIB_FT_DIR)includes/
	@echo "\n $(CHECK)$(PINK)	Finished !!"


norm:
	norminette $(LIB_FT_DIR)
	@echo
	norminette $(DIR_I)
	@echo
	norminette $(DIR_S)

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIB_FT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_FT_DIR)

re: fclean all

.PHONY: all clean fclean re
