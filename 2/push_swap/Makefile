# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 02:32:00 by yje               #+#    #+#              #
#    Updated: 2022/11/13 04:04:04 by yje              ###   ########.fr        #
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
SRCS_BONUS_FILES = $(SRCS_BONUS:c=o)

MAND_DIR = mandatory

NAME = push_swap
RM = rm -rf

%.o : %c
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(SRCS_FILES)
	$(CC) $(CFLAGS) -o $@ $^


all : $(NAME)


clean :
	$(RM) $(SRCS_FILES)

fclean : clean
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re bonus