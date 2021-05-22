/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:26:10 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/22 23:10:21 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		parse_line(t_scene *scene, char **data)
{
	if (data && data[0][0])
	{
		if (ft_strcmp(data[0], "sp") && ft_tablen(data) == NB_SPHERE)
			parse_sphere(&scene, data);
		else if (ft_strcmp(data[0], "pl") && ft_tablen(data) == NB_PLANE)
			parse_plane(&scene, data);
		else if (ft_strcmp(data[0], "sq") && ft_tablen(data) == NB_SQUARE)
			parse_square(&scene, data);
		else if (ft_strcmp(data[0], "cy") && ft_tablen(data) == NB_CYLINDER)
			parse_cylinder(&scene, data);
		else if (ft_strcmp(data[0], "tr") && ft_tablen(data) == NB_TRIANGLE)
			parse_triangle(&scene, data);
		else if (data[0][0] == 'R' && ft_tablen(data) == NB_RES)
			parse_resolution(&scene, data);
		else if (data[0][0] == 'A' && ft_tablen(data) == NB_AL)
			parse_ambient(&scene, data);
		else if (data[0][0] == 'c' && ft_tablen(data) == NB_CAM)
			parse_camera(&scene, data);
		else if (data[0][0] == 'l' && ft_tablen(data) == NB_LIGHT)
			parse_light(&scene, data);
		return (0);
	}
	return (1);
}

int		init_scene(t_scene *scene)
{
	scene->res.x = 0;
	scene->res.y = 0;
	scene->ambient.ratio = 0;
	scene->ambient.color.r = 0;
	scene->ambient.color.g = 0;
	scene->ambient.color.b = 0;
	if (!(scene->light = ft_lstnew(NULL)))
		print_err_and_exit("Malloc error");
	if (!(scene->cam = ft_lstnew(NULL)))
		print_err_and_exit("Malloc error");
	if (!(scene->obj = ft_lstnew(NULL)))
		print_err_and_exit("Malloc error");
	return (1);
}

t_scene	*parsing(char *file)
{
	int		fd;
	int		ret;
	char	*line;
	char	**data;

	if (!(ft_str_end(file, ".rt")))
		print_err_and_exit("First argument must be a '.rt' file");
	if ((fd = open(file, O_RDONLY)) == -1)
		print_err_and_exit("Open error");
	init_scene(&scene);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (!(parse_line(&scene, data = ft_split(line, " \t\n,"))))
		{
			ft_free_tab(&data);
			print_err_and_exit("GNL error");
		}
		ft_free_tab(&data);
	}
	close(fd);
	if (ret < 0 || !(parse_line(&scene, data = ft_split(line, " \t\n,"))))
		print_err_and_exit("GNL error");
	ft_free_tab(&data);
}
