# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 02:32:00 by yje               #+#    #+#              #
#    Updated: 2022/11/13 03:55:03 by yje              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJS = args.c checksort.c find.c main.c operationp.c operationr.c operations.c \
		operationrr.c rotate.c sort_utils.c sort.c stack_pop.c\
		stack_push.c stack.c utils_split.c utils.c

SRCS = $(addprefix mandatory/, $(OBJS))
# SRCS_BONUS = $(addprefix bonus/, $(OBJS_CHECKER))
SRCS_FILES = $(SRCS:c=o)
MAND_DIR = mandatory

NAME = push_swap
RM = rm -rf

%.o : %c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(SRCS_FILES)
	$(CC) $(CFLAGS) -o $@ $^
	@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all : $(NAME)

clean :
	$(RM) $(SRCS_FILES)
	@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean : clean
	$(RM) $(NAME)
	@echo -e "$(RED)all deleted!$(DEFAULT)"

re : fclean all

.PHONY: all clean fclean re

#COLORS
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
DEFAULT		=	\033[0m