# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/29 17:20:30 by pheilbro          #+#    #+#              #
#    Updated: 2019/10/25 14:08:41 by pheilbro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP	= push_swap
CHECKER		= checker

CC			= gcc
LIB			= -L../libft -lft
INC_FLAGS	= -I inc -I ../libft/inc
CFLAGS		= -Wall -Werror -Wextra
DEBUG_FLAGS	= -g -fsanitize=address

SRC_DIR		= src
OBJ_DIR		= obj
UTIL_DIR	= utils
PS_DIR		= push_swap
C_DIR		= checker

SRC			= clean init
OBJ			= $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

PS_SRC		= main
PS_OBJ		= $(patsubst %, $(OBJ_DIR)/%.o, \
			  $(patsubst %, $(PS_DIR)/%, $(PS_SRC)))

C_SRC		= check init main parse print update
C_OBJ		= $(patsubst %, $(OBJ_DIR)/%.o, \
			  $(patsubst %, $(C_DIR)/%, $(C_SRC)))

UTIL_SRC	= push rotate reverse_rotate swap
UTIL_OBJ	= $(patsubst %, $(OBJ_DIR)/%.o, \
			  $(patsubst %, $(UTIL_DIR)/%, $(UTIL_SRC)))

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(C_OBJ) $(UTIL_OBJ) $(OBJ) ../libft/libft.a
	@$(CC) $(CFLAGS) $(LIB) -o $@ $^

$(PUSH_SWAP): $(PS_OBJ) $(UTIL_OBJ) $(OBJ) ../libft/libft.a
	$(CC) $(CFLAGS) $(LIB) -o $@ $^

../libft/libft.a:
	@make -sC libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

debug_checker: 
	@$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) src/*.c src/checker/*.c src/utils/*.c \
		../libft/src/*/*.c ../libft/src/rbtree/utils/*.c \
		../libft/src/stdio/ft_printf/*.c ../libft/src/stdio/ft_printf/*/*.c
debug: 
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) src/*.c ../libft/src/*/*.c \
		../libft/src/stdio/ft_printf/*.c ../libft/src/stdio/ft_printf/*/*.c

clean: clean_debug
	#make clean -C lib/
	rm -rf $(OBJ_DIR)

clean_debug:
	rm -f debug 
	rm -rf debug.dSYM 

fclean: clean clean_debug
	#make fclean -C lib/
	rm -f $(PUSH_SWAP) $(CHECKER)

re: fclean all
