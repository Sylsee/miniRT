/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:26:10 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/19 20:48:50 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_line(char *line)
{
	while (ft_isalnum(*line) || ft_isspace(*line) || *line == '.'
		|| *line == ',' || *line == '+' || *line == '-' || *line == '_')
		line++;
	if (*line)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	match_parse_function(char *line, char **data, t_scene *scene)
{
	int			i;
	const char	*obj_name[] = {"sp", "pl", "sq", "cy", "tr", "R", "A", "C",
		"L", "BONUS", NULL};
	static void	(*obj_func[])(t_scene *, char **) = {&parse_sphere,
		&parse_plane, &parse_square, &parse_cylinder, &parse_triangle,
		&parse_resolution, &parse_ambient, &parse_camera, &parse_light,
		&parse_bonus};

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

static int	parse_line(t_scene *scene, char *line)
{
	char		**data;

	if (!line || line[0] == '\0' || line[0] == '#')
		return (EXIT_SUCCESS);
	if (check_line(line) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data = ft_split(line, "\t\n\v\f ,");
	if (!data)
		internal_error("unable to allocate memory");
	return (match_parse_function(line, data, scene));
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
	scene->antialiasing = 1;
	scene->ray_max_bounces = 3;
	scene->bg_color = 0x000000;
	scene->do_reflection = 0;
	scene->frame_index = 0;
	scene->video_mode = false;
	scene->ambient.ratio = -1;
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
	manage_scene(&scene);
	return (scene);
}
