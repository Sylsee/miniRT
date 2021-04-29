# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/20 14:54:32 by spoliart          #+#    #+#              #
#    Updated: 2021/04/21 20:26:08 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
		@echo "Compiling minilibx\n"
		@make re -C minilibx-linux/
		@echo "\n\nCompiling libft\n"
		@make re -C libft/

test:
		@make re -C minilibx-linux/
		@make re -C libft/
		@gcc test/test.c -o test/test minilibx-linux/minilibx-linux.a -lXext -lX11
		@./test/test

del:
		@rm test/test

#		gcc -lmlx -framework OpenGL -framework AppKit test/test.c -o test/test
