/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:53:04 by spoliart          #+#    #+#             */
/*   Updated: 2021/06/01 11:52:19 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/libft/includes/libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_vars {
    void        *mlx;
    void        *win;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}               t_vars;

void	exit_and_free(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
}

int main()
{
	t_vars *vars;

	if (!(vars = (t_vars *)malloc(sizeof(t_vars))))
		return (1);
	vars->mlx = mlx_init();
	vars->img = mlx_new_image(vars->mlx, 600, 600);
	vars->data = mlx_get_data_addr(vars->img,
			&vars->bpp, &vars->size_line, &vars->endian);
	vars->win = mlx_new_window(vars->mlx, 600, 600, "MiniRT");
	printf("mlx: [%p]\nimg: [%p]\nwin: [%p]\ndata: [%s]\nbpp: [%d]\nsize_line: [%d]\nendian: [%d]\n", vars->mlx, vars->img, vars->win, vars->data, vars->bpp, vars->size_line, vars->endian);
//	mlx_hook(vars->win, 17, 0, exit_and_free, &vars);
//	printf("\n\nmlx: [%p]\nimg: [%p]\nwin: [%p]\ndata: [%s]\nbpp: [%d]\nsize_line: [%d]\nendian: [%d]\n", vars->mlx, vars->img, vars->win, vars->data, vars->bpp, vars->size_line, vars->endian);
	mlx_loop(vars->mlx);
	return (0);
}

int             main(void)
{
    t_vars      vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
    mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_and_free, &vars);
    mlx_loop(vars.mlx);
}*/

#include "../lib/minilibx-linux/mlx.h"
#include "../lib/libft/includes/libft.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	uiclose(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_hook(int keycode, t_vars *vars)
{
	printf("key: [%d]\n", keycode);
	if (keycode == 65307)
		uiclose(vars);
//	else if (keycode == 114)
//		next_cam(vars);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 300, 300, "Hello world!");
	mlx_hook(vars.win, 33, 0, uiclose, &vars);
    mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_hook(vars.win, 2, 1L<<0, uiclose, &vars);
	mlx_loop(vars.mlx);
}
