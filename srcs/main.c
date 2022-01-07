/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:36:51 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/07 14:27:27 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_leaks(void) __attribute__((destructor));

void	free_leaks(void)
{
	free_area(NULL);
}

/*
**	Initialize minilibx utilities
*/

void	init_mlx(t_data *data, t_scene scene)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		internal_error("unable to initialize minilibx");
	if (data->save == false)
	{
		data->win = mlx_new_window(data->mlx, scene.res.x,
				scene.res.y, "MiniRT");
		if (!data->win)
			internal_error("unable to create minilibx window");
	}
	data->img = mlx_new_image(data->mlx, scene.res.x, scene.res.y);
	if (!data->img)
		internal_error("unable to create minilibx image");
	data->data = mlx_get_data_addr(data->img, &data->pixel_bits,
			&data->line_bytes, &data->endian);
}

void	set_img(t_data data)
{
//	mlx_clear_window(data.mlx, data.win);
//	mlx_hook(data->win, 2, 1L, handle_key, &data);
//	mlx_hook(data->win, 33, 0, close_window, &data);
//	mlx_key_hook(data->win, key_hook, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
}

void	minirt(int argc, char **argv)
{
	t_data	data;
	t_scene	scene;

	data.save = false;
	if (argc == 3)
		data.save = true;
	scene = parsing(argv[1]);
	init_mlx(&data, scene);
	create_img(&data, scene);
	if (data.save == false)
		set_img(data);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		internal_error("missing file operand\n");
	else if (argc > 3)
		internal_error("too many arguments");
	else if (argc == 3 && ft_strequ(argv[2], "--save") == 0)
		internal_error("Second argument must be `--save'");
	else if (ft_strend(argv[1], ".rt") == 0)
		internal_error("First argument must be a `.rt' file");
	init_area(NULL);
	minirt(argc, argv);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
