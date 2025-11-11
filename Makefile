# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: giborges <giborges@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 18:09:38 by giborges          #+#    #+#              #
#    Updated: 2025/11/11 16:49:13 by giborges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = 

OBJ = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ) 
	ar rcs $(NAME) $(OBJ) 

%.o: %.c
	$(CC) $(CFLAGS) $(TESTS) -c $< -o $@

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

clean:
	rm -f $(OBJ) $(BOBJS)
	
fclean: clean
	rm -f $(NAME) .bonus

re: fclean all
	
.PHONY: all clean fclean re bonus
