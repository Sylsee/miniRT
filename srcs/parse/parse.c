/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:26:10 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/03 21:40:15 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_line(char *line)
{
	while (ft_isalnum(*line) || ft_isspace(*line) || *line == '.'
		|| *line == ',' || *line == '+' || *line == '-')
		line++;
	if (*line)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	parse_line(t_scene *scene, char *line)
{
	int			i;
	char		**data;
	const char	*obj_name[] = {"sp", "pl", "sq", "cy", "tr", "R", "A", "C",
		"L", NULL};
	void		(*obj_func[])(t_scene *, char **) = {&parse_sphere,
		&parse_plane, &parse_square, &parse_cylinder, &parse_triangle,
		&parse_resolution, &parse_ambient, &parse_camera, &parse_light};

	if (!line || line[0] == '\0')
		return (EXIT_SUCCESS);
	if (check_line(line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data = ft_split(line, "\t\n\v\f ,");
	if (!data)
		internal_error("unable to allocate memory");
	i = 0;
	while (obj_name[i] && !(line[0] == obj_name[i][0]
		&& (!obj_name[i][1] || line[1] == obj_name[i][1])))
		i++;
	if (obj_name[i])
		obj_func[i](scene, data);
	ft_free_tab(data, NULL);
	if (obj_name[i] == NULL && line && line[0])
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	init_scene(t_scene *scene)
{
	scene->camera_mode = TRANSLATION;
	scene->object_mode = TRANSLATION;
	scene->object_type = CAMERA;
	scene->current_light = NULL;
	scene->res.x = 1080;
	scene->res.y = 720;
	scene->ambient.ratio = 0;
	scene->ambient.color.r = 0;
	scene->ambient.color.g = 0;
	scene->ambient.color.b = 0;
	scene->light = NULL;
	scene->cam = NULL;
	scene->obj = NULL;
}

t_scene	parsing(char *file)
{
	int		fd;
	int		ret;
	char	*line;
	t_scene	scene;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		internal_error("unable to open `.rt' file");
	init_scene(&scene);
	while (true)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			internal_error("get_next_line error");
		if (parse_line(&scene, line) == EXIT_FAILURE)
			internal_error("File format error");
		free(line);
		if (ret == 0)
			break ;
	}
	close(fd);
	link_cam_lst(scene.cam);
	if (scene.light && scene.light->content)
		scene.current_light = scene.light;
	if (scene.obj)
	{
		scene.id_current_obj = ((t_lst *)scene.obj)->id;
		scene.current_obj = ((t_lst *)scene.obj)->object;
	}
	else
		scene.id_current_obj = -1;
	return (scene);
}
