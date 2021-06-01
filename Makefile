# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/20 14:54:32 by spoliart          #+#    #+#              #
#    Updated: 2021/05/31 21:01:31 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
		@echo "Compiling minilibx\n"
		@make re -C lib/minilibx-linux/
		@echo "\n\nCompiling libft\n"
		@make re -C lib/libft/

test: del		
		@make re -C lib/minilibx-linux/
		@make re -C lib/libft/
		@gcc test/test.c -o test/test lib/libft/libft.a lib/minilibx-linux/libmlx_Linux.a -lXext -lX11
		@./test/test

del:
		@rm test/test

#		gcc -lmlx -framework OpenGL -framework AppKit test/test.c -o test/test
