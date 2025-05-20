# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 17:43:57 by gnicolo           #+#    #+#              #
#    Updated: 2025/02/27 16:38:01 by gpirozzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
NAME_BONUS = checker
SRC = errors_detector.c insertion_sort.c push_swap.c push.c reverse_rotate.c\
		rotate.c stack_init.c swap.c utils.c util2.c index_list.c for_chunks.c

BONUS_SRC = checker.c

OBJ_DIR = obj
OBJ_SRC = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJ_SRC_NO_MAIN = $(filter-out $(OBJ_DIR)/push_swap.o, $(OBJ_SRC)) # Escludi push_swap.o
BONUS_OBJ = $(addprefix $(OBJ_DIR)/, $(BONUS_SRC:.c=.o))

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
		@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ_SRC) $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) $(OBJ_SRC) -L$(LIBFT_DIR) -lft -o $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
		@$(CC) -c $(CFLAGS) -I$(LIBFT_DIR) $< -o $@

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

bonus: $(OBJ_SRC_NO_MAIN) $(BONUS_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) $(OBJ_SRC_NO_MAIN) $(BONUS_OBJ) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)

clean:
		rm -rf $(OBJ_DIR)
		@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
		rm -rf $(NAME) $(NAME_BONUS)
		@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re bonus
