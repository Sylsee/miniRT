/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:53:04 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/26 22:38:19 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx/mlx.h"
#include "../lib/libft/includes/libft.h"
#include <stdio.h>
#include <stdlib.h>
/*
typedef struct  s_vars {
	void        *mlx;
	void        *win;
	void		*img;
	char		*data;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}               t_vars;

int	exit_and_free(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(EXIT_SUCCESS);
}

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
	return (0);
}*/
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;




	int i = 1275;
	int j = 1275;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, i, j, "Hello world!");
	img.img = mlx_new_image(mlx, i, j);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	for (int x = 0; x < i; x++) {
		for (int y = 0; y < j; y++) {
			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
/*
void	put_color(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->data + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	t_vars      vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	vars.img = mlx_new_image(vars.mlx, 640, 480);
	vars.data = mlx_get_data_addr(vars.img,
			&vars.bits_per_pixel, &vars.line_length, &vars.endian);
//	for (int x = 0; x < 640; x++) {
//		for (int y = 0; y < 480; y++) {
//			put_color(&vars, x, y, 0xFF0000);
//		}
//	}
	put_color(&vars, 10, 10, 0x00FF0000);
	put_color(&vars, 10, 11, 0x00FF0000);
	put_color(&vars, 10, 12, 0x00FF0000);
	put_color(&vars, 10, 13, 0x00FF0000);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 320, 240);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 0, exit_and_free, &vars);
	mlx_loop(vars.mlx);
}*/
/*
#include "../lib/minilibx-linux/mlx.h"
#include "../lib/libft/includes/libft.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 300, 300, "Hello world!");
	mlx_hook(vars.win, 33, 0, uiclose, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	//mlx_hook(vars.win, 2, 1L<<0, uiclose, &vars);
	mlx_loop(vars.mlx);
}*/
/*
int main()
{
	t_vars *vars;

	if (!(vars = (t_vars *)malloc(sizeof(t_vars))))
		return (1);
	vars->mlx = mlx_init();
	vars->img = mlx_new_image(vars->mlx, 600, 600);
	vars->data = mlx_get_data_addr(vars->img,
			&vars->bits_per_pixel, &vars->line_length, &vars->endian);
	vars->win = mlx_new_window(vars->mlx, 600, 600, "MiniRT");
//	printf("mlx: [%p]\nimg: [%p]\nwin: [%p]\ndata: [%s]\nbits_per_pixel: [%d]\nline_length: [%d]\nendian: [%d]\n", vars->mlx, vars->img, vars->win, vars->data, vars->bits_per_pixel, vars->line_length, vars->endian);
	//	mlx_hook(vars->win, 17, 0, exit_and_free, &vars);
	//	printf("\n\nmlx: [%p]\nimg: [%p]\nwin: [%p]\ndata: [%s]\nbits_per_pixel: [%d]\nline_length: [%d]\nendian: [%d]\n", vars->mlx, vars->img, vars->win, vars->data, vars->bits_per_pixel, vars->line_length, vars->endian);
	mlx_loop(vars->mlx);
	return (0);
}
*/
