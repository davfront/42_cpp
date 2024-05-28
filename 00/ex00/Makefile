# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 16:05:32 by dapereir          #+#    #+#              #
#    Updated: 2023/05/08 16:05:32 by dapereir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# COMMANDS

CXX					=	c++
CXXFLAGS			=	-Wall -Wextra -Werror -std=c++98
RM					=	rm -rf


# PROJECT

NAME				=	megaphone

SRCS_DIR			=	.
OBJS_DIR			=	./obj

SRCS_FILES			=	megaphone.cpp
OBJS_FILES			=	$(SRCS_FILES:.cpp=.o)

SRCS				=	$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS				=	$(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

.PHONY: all
all:				$(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.cpp Makefile
					@mkdir -p $(@D)
					@$(CXX) $(CXXFLAGS) -c $< -o $@

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
