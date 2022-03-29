# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/13 19:04:24 by spoliart          #+#    #+#              #
#    Updated: 2022/03/30 00:00:43 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# [ VARIABLES ] #

NAME	=	miniRT
RM		=	/bin/rm -rf
MAKE	=	make
LIBFT	=	lib/libft
LIBX	=	lib/minilibx

# [ COLORS ] #

_END	=	\e[0m
_RED	=	\e[31m
_GREEN	=	\e[32m
_YELLOW	=	\e[33m

# [ COMPILATION VARIABLES ]#

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -O3 -Wconversion -pthread
LDFLAGS	=	-Llib/libft -lft -Llib/minilibx -lmlx -L/usr/lib -lXext -lX11 -lm -lz

# [ VALGRIND VARIABLES ] #

VALGRIND	=	/usr/bin/valgrind
VFLAGS		=	--leak-check=full --show-leak-kinds=all --track-origins=yes

# [ DIRECTORIES ] #

S		=	srcs/
O		=	objs/
I		=	-Iincludes -Ilib/minilibx -I/usr/include

# [ SOURCES ] #

MLX	=	mlx.c \
		set_image.c

OBJECTS_INTERSECTION	=	sphere.c \
							plane.c \
							cylinder.c

MATERIAL_COMPUTATION	=	light.c \
							shadow.c \
							reflection.c \
							refraction.c \
							fresnel.c \
							compute_material.c

RAYTRACING	=	$(MATERIAL_COMPUTATION) \
				ray.c

IMAGE	=	image.c \
			color.c \
			cam.c

PARSING	=	parse.c \
			parse_elem.c \
			parse_objects.c \
			parse_utils.c \
			parse_bonus.c \
			check_arguments.c \

MATH	=	vector_calculs.c \
			vector_calculs2.c \
			points.c \
			maths.c

EVENT	=	init_mlx_events.c \
			mlx_exit.c \
			cameras_event.c \
			lights_event.c \
			objects_event.c \
			update_window.c \
			object_properties.c \
			is_movement_keycode.c \
			print_status.c \
			print_objects.c \
			print_utils.c \
			mouse_hook.c

SAVE	=	save.c \
			create_video.c \

LST		=	lst.c \
			cam_lst.c \

UTILS	=	$(LST) \
			error.c \
			is_dir.c \
			utils.c \

THREAD	=	progress_bar.c \
			init_data.c \
			routine.c \

SRCS	=	main.c \
			$(UTILS) \
			$(PARSING) \
			$(IMAGE) \
			$(OBJECTS_INTERSECTION) \
			$(RAYTRACING) \
			$(MATH) \
			$(EVENT) \
			$(LST) \
			$(SAVE) \
			$(THREAD) \
			$(MLX)

# [ OBJECTS ] #

OBJS	=	$(SRCS:%.c=$O%.o)

# [ PATH ] #

VPATH	=	includes:srcs:srcs/utils:srcs/utils/lst:srcs/save:srcs/parsing:\
			srcs/raytracing:srcs/raytracing/color_computation:srcs/maths:\
			srcs/objects_intersection:srcs/image:srcs/events:srcs/thread:\
			srcs/mlx

# [ RULES ] #

all:		$(NAME)

$(NAME):	$(OBJS)
			@printf "\033[2K\r$(_GREEN) All files compiled into '$O'. $(_END)✅\n"
			@$(MAKE) -s -C $(LIBFT)
			@$(MAKE) -s -C $(LIBX)
			@$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
			@printf "$(_GREEN) Binary '$(NAME)' created. $(_END)✅\n"

$O:
			@mkdir -p $@

$O%.o:		%.c	| $O
			@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END)⌛"
			@$(CC) $(CFLAGS) $I -c $< -o $@

clean:
			@make -s clean -C $(LIBFT)
			@make -s clean -C $(LIBX)
			@$(RM) $O
			@printf "$(_RED) '$O' has been deleted. $(_END)🗑️\n"

fclean:		clean
			@make -s fclean -C $(LIBFT)
			@make -s clean -C $(LIBX)
			@$(RM) $(NAME)
			@printf "$(_RED) '$(NAME)' has been deleted. $(_END)🗑️\n"

re:			fclean
			@make -s -j

valgrind: 	all
			@$(VALGRIND) $(VFLAGS) ./$(NAME)

test: del
		@make -C lib/minilibx/
		@make -C lib/libft/
		@gcc $(CFLAGS) test/test.c -o test/test lib/libft/libft.a lib/minilibx/libmlx.a -lXext -lX11 -lm -lz
		@./test/test

del:
		@rm -f test/test

# [ PHONY ] #

.PHONY:	all clean fclean re valgrind
