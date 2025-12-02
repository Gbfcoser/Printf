# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: giborges <giborges@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 18:09:38 by giborges          #+#    #+#              #
#    Updated: 2025/12/02 12:55:13 by giborges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = 	cc

CFLAGS = -Wall -Wextra -Werror -Ilibft

SRC = ft_printf.c 

LIBFT_SRCS = libft/ft_bzero.c libft/ft_memset.c libft/ft_atoi.c libft/ft_calloc.c libft/ft_isalnum.c libft/ft_itoa.c \
libft/ft_isalpha.c libft/ft_isascii.c libft/ft_isdigit.c libft/ft_isprint.c libft/ft_memchr.c libft/ft_memcmp.c \
libft/ft_memcpy.c libft/ft_strchr.c libft/ft_strdup.c libft/ft_strlen.c libft/ft_strjoin.c libft/ft_strlcat.c \
libft/ft_strlcpy.c libft/ft_memmove.c libft/ft_tolower.c libft/ft_toupper.c libft/ft_substr.c \
libft/ft_strtrim.c libft/ft_strncmp.c libft/ft_strrchr.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c\
libft/ft_putnbr_fd.c libft/ft_split.c libft/ft_strmapi.c libft/ft_strnstr.c libft/ft_striteri.c\
libft/ft_lstnew.c libft/ft_lstadd_front.c libft/ft_lstadd_back.c libft/ft_lstclear.c libft/ft_lstdelone.c\
libft/ft_lstiter.c libft/ft_lstlast.c libft/ft_lstsize.c libft/ft_lstmap.c \

OBJ = $(SRC:%.c=%.o) $(LIBFT_SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(TESTS) -c $< -o $@

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)                                                                                                                                                                                                   
	gcc -nostartfiles -shared -o libft.so $(OBJ) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
