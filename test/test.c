/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:53:04 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/19 18:40:20 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

void	key_hook(int keycode, t_vars *vars)
{
    printf("%d\n", keycode);
}

void	exit_and_free(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
}

int main()
{
	t_vars vars;
	int y = 249;
	int x = 249;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 600, 600, "This is a test !");
	while (++y <= 350)
	{
		x = 249;
		while (++x <= 350)
			mlx_pixel_put(vars.mlx, vars.win, x, y, 0x00FF0000);
	}
	while (++y < 600)
		mlx_pixel_put(vars.mlx, vars.win, x, y, 0x00FF0000);
    mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_and_free, &vars);
	mlx_loop(vars.mlx);
}

/*
int             main(void)
{
    t_vars      vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
    mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_and_free, &vars);
    mlx_loop(vars.mlx);
}*/
