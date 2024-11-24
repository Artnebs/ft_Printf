# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+           #
#    Created: 2024/11/11 13:18:37 by anebbou           #+#    #+#              #
#    Updated: 2024/11/18 20:30:00 by anebbou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Fichiers source et objets spécifiques à ft_printf
SRCS = ft_printf.c ft_printf_char_str.c ft_printf_numbers.c ft_printf_utils.c
OBJS = $(SRCS:.c=.o)

# Commandes et flags de compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# **************************************************************************** #
# Règles principales
# **************************************************************************** #

all: $(LIBFT) $(NAME)

# Compile la Libft via son propre Makefile
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Compile la bibliothèque ft_printf
$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS) $(LIBFT_DIR)/*.o

# Règle générique pour compiler les fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# **************************************************************************** #
# Gestion d'un fichier de test (désactivée)
# **************************************************************************** #

# Pour tester avec un fichier main.c:

# TEST = test_program
# 
# $(TEST): $(NAME) $(LIBFT) main.o
# 	$(CC) $(CFLAGS) main.o -L. -lftprintf -L$(LIBFT_DIR) -lft -o $(TEST)
# 
# main.o: main.c
# 	$(CC) $(CFLAGS) -c main.c -o main.o

# **************************************************************************** #
# Nettoyage
# **************************************************************************** #

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	# rm -f main.o # Décommentez si main.c utilisé

fclean: clean
	rm -f $(NAME)
	# rm -f $(TEST) # Décommentez si main.c utilisé
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
