# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yje <yje@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/01 13:13:46 by yje          #+#    #+#              #
#    Updated: 2022/11/27 19:54:37 by yje         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SETUP
NAME		=	philo_bonus
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
THREAD		=	-pthread
RM			=	rm -rf

# HEADER
HEADER_SRCS	=	philo_bonus.h
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

# FILES
MPATH_SRCS	=	main_bonus.c utils_bonus.c init_bonus.c philo_bonus.c
MPATH_DIR	=	srcs/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

#COMMANDS
%.o:			%.c $(HEADER) Makefile
				@${CC} ${CFLAGS} -c $< -o $@

$(NAME):		$(OBJ_M)
				@$(CC) $(OBJ_M) $(THREAD) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

bonus:			all

clean:
				@$(RM) $(OBJ_M)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED			=	\033[1;31m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
DEFAULT		=	\033[0m
