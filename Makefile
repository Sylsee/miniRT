# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/20 14:54:32 by spoliart          #+#    #+#              #
#    Updated: 2021/03/20 15:10:22 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

test:
		gcc -lmlx -framework OpenGL -framework AppKit test.c -o test
		./test

del:
		rm test

re:		del test

