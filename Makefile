# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <sylvio.poliart@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 19:04:24 by spoliart          #+#    #+#              #
#    Updated: 2021/05/26 01:27:22 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###### VARIABLES ######


## CUSTOMIZATION ##

_END		=	\e[0m

_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m

## COMPILATION ##

CC				=	gcc

L_FLAGS			=	-lft -lmlx_Linux -lXext -lm -lX11 -Llibft -Lminilibx-linux
CC_FLAGS		=	-Wall -Wextra -Werror

## DELETE ##

RM				=	rm -rf

## NORME ##

NORMINETTE		:=	${HOME}/.norminette/norminette.rb

## DIRECTORIES ##

DIR_HEADERS		=	./includes/

DIR_SRCS		=	./srcs/

DIR_OBJS		=	./objs/

SUB_DIRS		=	. \
					error \
					image \
					math \
					objects \
					parse

SUB_DIR_OBJS	=	$(SUB_DIRS:%=$(DIR_OBJS)%)

## FILES ##

SRCS			=	error/error.c \
					image/image.c \
					math/math_func.c \
					objects/intersec_sphere.c \
					parse/parse.c \
					parse/parse_elem.c \
					parse/parse_elem2.c \
					parse/parse_utils.c

## COMPILED ##

OBJS		=	$(SRCS:%.c=$(DIR_OBJS)%.o)

NAME		=	minirt

# **************************************************************************** #

###### RULES ######

all:			$(NAME)

## VARIABLES RULES ##

$(NAME):		$(OBJS)
					@printf "\033[2K\r$(_GREEN) All files compiled into '$(DIR_OBJS)'. $(_END)✅\n"
					@make -C lib/libft/
					@make -C lib/minilibx-linux/
					@cp lib/libft/libft.a ./minirt.a
					@cp lib/minilibx-linux/libmlx.a ./minirt.a
					@ar rc minirt.a $(OBJS)
					@gcc -Iincludes $(OBJS) $(L_FLAGS) $(CC_FLAGS) srcs/minirt.c minirt.a lib/libft/libft.a lib/minilibx-linux/libmlx.a -o minirt
					@printf "$(_GREEN) $(NAME) created. $(_END)✅\n"

$(DIR_OBJS)%.o:	$(DIR_SRCS)%.c
					@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END)⌛"
					@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(OBJS):		| $(DIR_OBJS)

$(DIR_OBJS):	$(SUB_DIR_OBJS)

$(SUB_DIR_OBJS):
					@mkdir -p $(SUB_DIR_OBJS)

## OBLIGATORY PART ##

clean:
					@make clean -C lib/libft/
					@$(RM) $(DIR_OBJS)
					@printf "$(_RED) '$(DIR_OBJS)' has been deleted. $(_END)🗑️\n"

fclean:			clean
					@make fclean -C lib/libft/
					@$(RM) $(NAME) minirt minirt.a
					@printf "$(_RED) '$(NAME)' and minirt.a has been deleted. $(_END)🗑️\n"

re:				fclean all

## NORME ##

norme:
					@$(NORMINETTE) $(DIR_SRCS)
					@$(NORMINETTE) $(DIR_HEADERS)

## PHONY ##

.PHONY:			all clean re fclean norme
