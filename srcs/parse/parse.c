/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:26:10 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/07 00:58:59 by spoliart         ###   ########.fr       */
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
	const char	*obj_name[] = {"sp", "pl", "sq", "cy", "tr", "R", "A", "c",
		"l"};
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
	while (i < 9 && !(line[0] == obj_name[i][0]
		&& (!obj_name[i][1] || line[1] == obj_name[i][1])))
		i++;
	if (i < 9)
		obj_func[i](scene, data);
	ft_free_tab(data, NULL);
	if (i >= 9 && line && line[0])
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	init_scene(t_scene *scene)
{
	scene->res.x = 0;
	scene->res.y = 0;
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
	return (scene);
}
