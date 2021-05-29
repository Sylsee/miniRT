/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:36:51 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/26 18:12:19 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
** mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->img, 0, 0);
*/

void	init_minirt(t_minirt *minirt, t_scene *scene)
{
	if (!(minirt->mlx = mlx_init()))
		print_err_and_exit("MinilibX error");
	if (minirt->save == 0)
		if (!(minirt->win = mlx_new_window(minirt->mlx, scene->res.x,
			scene->res.y, "MiniRT")))
			print_err_and_exit("MinilibX error");
	if (!(minirt->img = mlx_new_image(minirt->mlx, scene->res.x, scene->res.y)))
		print_err_and_exit("MinilibX error");
	minirt->data = mlx_get_data_addr(minirt->img, &(minirt->pixel_bits),
		&(minirt->line_bytes), &(minirt->endian));
}

void	set_img(t_minirt *minirt)
{
	mlx_put_image_to_window(minirt->mlx, minirt->win, minirt->data, 0, 0);
}

void	minirt(int argc, char **argv)
{
	t_minirt	*minirt;
	t_scene		*scene;

	if (!(minirt = (t_minirt *)malloc(sizeof(t_minirt))))
		print_err_and_exit("Malloc error");
	scene = parsing(argv[1]);
	if (argc == 3)
		minirt->save = 1;
	init_minirt(minirt, scene);
	create_img(minirt, scene);
	set_img(minirt);
	clean(minirt, scene);
}

int		main(int argc, char **argv)
{
	if (argc == 2 || (argc == 3 && ft_strict_strcmp(argv[2], "--save")))
		minirt(argc, argv);
	else if (argc < 2 || argc > 3)
		print_err_and_exit("Wrong number of arguments");
	else if (argc == 3)
		print_err_and_exit("Second argument must be '--save'");
	return (0);
}
