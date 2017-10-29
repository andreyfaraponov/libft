# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 14:40:16 by afarapon          #+#    #+#              #
#    Updated: 2017/10/28 17:59:00 by afarapon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
KEYS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(KEYS) *.c
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
