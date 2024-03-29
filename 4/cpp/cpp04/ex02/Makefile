# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yje <yje@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 18:22:00 by yje               #+#    #+#              #
#    Updated: 2023/03/15 17:51:55 by yje              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= a.out

# CXXFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
CXXFLAGS			= -Wall -Wextra -Werror -std=c++98

# NOTE : Add Source directory here
# ------------------------------------------------------ #
# SRC_DIR			= src

# NOTE : Add Source files here
# ------------------------------------------------------ #
# MAIN_SRC		= main

# NOTE : Add to SRC here
# ------------------------------------------------------ #
# SRC = $(addsuffix .c, $(addprefix $(MAIN_DIR), $(MAIN_SRC)))

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp \
	Brain.cpp

# ------------------------------------------------------ #

OBJ = $(SRC:cpp=o)

all: $(NAME)

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
ORANGE = \033[38;5;208m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
CUSTOM = \033[38;5;135m

#-----------------------------------------------------------------------
#    Mac compile option                                                |
#-----------------------------------------------------------------------
$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)╔══════════════════════════════════════════╗$(DEF_COLOR)"
	@echo "$(GREEN)║      cpp_04 ex02 compile finished.       ║$(DEF_COLOR)"
	@echo "$(GREEN)╚══════════════════════════════════════════╝$(DEF_COLOR)"

%.o: %.cpp
	@${CXX} ${CXXFLAGS} -c $< -o $@
	@echo "$(GREEN)Compiling... \t$< $(DEF_COLOR)"
# #-----------------------------------------------------------------------

clean:
	@rm -f $(OBJ)
	@echo "$(CUSTOM)ex02 obj files has been deleted.$(DEF_COLOR)"

fclean:
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@rm -f $(NAME)2	@echo "$(CUSTOM)ex02 archive files has been deleted.$(DEF_COLOR)"

re: fclean all2
	@echo "$(CUSTOM)Cleaned and rebuilt ex02.$(DEF_COLOR)"

.PHONY: all clean fclean re
