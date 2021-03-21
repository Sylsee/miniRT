/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:53:04 by spoliart          #+#    #+#             */
/*   Updated: 2021/03/21 14:30:20 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
/*
int main()
{
	int y = 249;
	int x = 249;
	void *ptr = mlx_init();
	void *win = mlx_new_window(ptr, 1920, 1080, "This is a test !");
	while (++y <= 350)
	{
		x = 249;
		while (++x <= 350)
			mlx_pixel_put(ptr, win, x, y, 0x00FF0000);
	}
	while (++y < 600)
		mlx_pixel_put(ptr, win, x, y, 0x00FF0000);
	mlx_loop(ptr);
}*/

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

int		key_hook(int keycode, t_vars *vars)
{

    return(printf("%d\n", keycode));
}

int	exit_and_free(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
	return(1);
}

int             main(void)
{
    t_vars      vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
    mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_and_free, &vars);
    mlx_loop(vars.mlx);
}
