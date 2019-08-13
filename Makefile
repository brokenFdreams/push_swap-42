#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/07 12:42:32 by fsinged           #+#    #+#              #
#    Updated: 2019/08/13 12:01:12 by fsinged          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc -Wall -Wextra -Werror
PUSH = push_swap
CHECKER = checker

SRCS_PATH = ./src/
SRCS_FILES = functions.c push.c rotate.c swap.c
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
SWAP = $(addprefix $(SRCS_PATH), new_push_swap.c)
CHECK = $(addprefix $(SRCS_PATH), checker.c)

LIB_PATH = ./libft/
LIB = ./libft/libft.a
HEADER = -I ./includes/ -I ./libft/

all:$(LIB) $(PUSH) $(CHECKER)

$(LIB):
	@make -C $(LIB_PATH)

$(PUSH):
	@$(CC) $(SRCS) $(SWAP) $(LIB) $(HEADER) -o $(PUSH)

$(CHECKER):
	@$(CC) $(SRCS) $(CHECK) $(LIB) $(HEADER) -o $(CHECKER)

clean:
	@make fclean -C $(LIB_PATH)

fclean:clean
	@/bin/rm -f $(PUSH) $(CHECKER)

re:fclean all