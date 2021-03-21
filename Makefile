# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/20 14:54:32 by spoliart          #+#    #+#              #
#    Updated: 2021/03/21 16:40:01 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:	
		gcc -lmlx -framework OpenGL -framework AppKit test/test.c -o test/test
		./test/test

del:
		rm test/test
