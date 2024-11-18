# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anebbou <anebbou@student42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 14:27:24 by anebbou           #+#    #+#              #
#    Updated: 2024/11/17 16:10:16 by anebbou          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_strlen.c \
ft_strdup.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_memcmp.c \
ft_atoi.c \
ft_itoa.c \
ft_split.c \
ft_isascii.c \
ft_isprint.c \
ft_toupper.c \
ft_tolower.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_strnstr.c \
ft_memchr.c \
ft_calloc.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_utoa.c \
ft_ltoa.c \
ft_isupper.c \
ft_islower.c \
ft_ltoa_base.c \
ft_ltoa_base_upper.c

BONUS_SRCS = ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)


all: $(NAME)

# Créer la bibliothèque à partir des fichiers objets
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Générer la bibliothèque avec les fonctions bonus
bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)


clean:
	rm -f $(OBJS) $(BONUS_OBJS)


fclean: clean
	rm -f $(NAME)


re: fclean all

.PHONY: all clean fclean re bonus