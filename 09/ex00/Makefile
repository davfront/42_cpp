# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 16:05:32 by dapereir          #+#    #+#              #
#    Updated: 2023/09/22 16:07:59 by dapereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# COMMANDS

CXX					=	c++
CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98
RM					=	rm -rf


# PROJECT

NAME				=	btc

SRCS_DIR			=	.
SRCS_FILES			=	main.cpp BitcoinExchange.cpp
SRCS				=	$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS_DIR			=	./obj
OBJS_FILES			=	$(SRCS_FILES:.cpp=.o)
OBJS				=	$(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

HEADERS_DIR			=	.
HEADERS_FILES		=	BitcoinExchange.hpp
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
