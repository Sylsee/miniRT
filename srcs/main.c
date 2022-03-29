/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:36:51 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/29 23:55:14 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_leaks(void) __attribute__((destructor));

void	free_leaks(void)
{
	free_area(NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_scene	scene;

	init_area(NULL);
	check_arguments(argc, argv);
	data.save = false;
	if (argc == 3)
		data.save = true;
	scene = parse(argv[1]);
	find_video_dir(argc, argv, &scene);
	init_mlx(&data, &scene);
	create_img(&data, scene);
	if (data.save == false)
		set_img(&data, &scene);
	else
		create_bmp(data, scene, &scene.frame_index, SAVE_DIR);
	free_mlx(data);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
