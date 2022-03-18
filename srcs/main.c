/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:36:51 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/18 20:15:59 by arguilla         ###   ########.fr       */
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

void	init_mlx(t_data *data, t_scene *scene)
{
	int	x;
	int	y;

	data->mlx = mlx_init();
	if (!data->mlx)
		internal_error("unable to initialize minilibx");
	mlx_get_screen_size(data->mlx, &x, &y);
	if (scene->res.x > x)
		scene->res.x = x;
	if (scene->res.y > y)
		scene->res.y = y;
	if (data->save == false)
	{
		data->win = mlx_new_window(data->mlx, scene->res.x,
				scene->res.y, "MiniRT");
		if (!data->win)
			internal_error("unable to create minilibx window");
	}
	data->img = mlx_new_image(data->mlx, scene->res.x, scene->res.y);
	if (!data->img)
		internal_error("unable to create minilibx image");
	data->data = mlx_get_data_addr(data->img, &data->pixel_bits,
			&data->line_bytes, &data->endian);
}

void	set_img(t_data *data, t_scene *scene)
{
	init_mlx_events(data, scene);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_loop(data->mlx);
}

void	minirt(int argc, char **argv)
{
	t_data	data;
	t_scene	scene;

	data.save = false;
	if (argc == 3)
		data.save = true;
	scene = parsing(argv[1]);
	if (argc > 3 && is_dir(argv[3]))
		scene.video_dir = ft_strjoin(argv[3], "/");
	else if (is_dir("saves") || argc <= 3)
		scene.video_dir = ft_strdup("saves/");
	else
		internal_error("Can't find video directory");
	if (!scene.video_dir)
		internal_error("Malloc failed.");
	if (scene.cam == NULL)
		internal_error("You must provide a camera");
	init_mlx(&data, &scene);
	create_img(&data, scene);
	if (data.save == false)
		set_img(&data, &scene);
	else
		create_bmp(data, scene, &scene.frame_index, SAVE_DIR);
}

int	main(int argc, char **argv)
{
	check_arguments(argc, argv);
	init_area(NULL);
	minirt(argc, argv);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
