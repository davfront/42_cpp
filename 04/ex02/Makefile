# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 18:40:26 by dapereir          #+#    #+#              #
#    Updated: 2023/05/30 20:22:08 by dapereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# COMMANDS

CXX					=	c++
CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98
RM					=	rm -rf


# PROJECT

NAME				=	ex02.out

SRCS_DIR			=	.
SRCS_FILES			=	AAnimal.cpp Brain.cpp Cat.cpp Dog.cpp main.cpp
SRCS				=	$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS_DIR			=	./obj
OBJS_FILES			=	$(SRCS_FILES:.cpp=.o)
OBJS				=	$(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

HEADERS_DIR			=	.
HEADERS_FILES		=	text_formatting.hpp AAnimal.hpp Brain.hpp Cat.hpp Dog.hpp
HEADERS				=	$(addprefix $(HEADERS_DIR)/, $(HEADERS_FILES))
HEADERS_INC			=	-I $(HEADERS_DIR)

.PHONY: all
all:				$(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.cpp Makefile $(HEADERS)
					@mkdir -p $(@D)
					@$(CXX) $(CXXFLAGS) $(HEADERS_INC) -c $< -o $@

$(NAME):			$(OBJS)
					$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

.PHONY: clean
clean:
					$(RM) $(OBJS_DIR)

.PHONY: fclean
fclean:				clean
					$(RM) $(NAME)

.PHONY: re
re:					fclean
					$(MAKE) all
