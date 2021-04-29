/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:26:10 by spoliart          #+#    #+#             */
/*   Updated: 2021/04/29 20:08:28 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tablen(char **tab)
{
	size_t	i;

	i = 0;
	if (tab)
		while (tab[i])
			i++;
	return (i);
}

int		parsing_resolution(t_scene **scene, char **data)
{
}

int		parsing_ambient(t_scene **scene, char **data)
{
}

int		parsing_cylinder(t_scene **scene, char **data)
{
}

t_color	parse_color(char *data)
{
	t_color	color;

	color = (t_color)malloc(sizeof(color));
	if (!color)
		return (0);
	color.r = ft_atoc(&data[i]);
	if (data[i] == ',')
		i++;
	color.g = ft_atoc(&data[i]);
	if (data[i] == ',')
		i++;
	color.b = ft_atoc(&data[i]);
	if (data[i] == ',')
		i++;
	return (color);
}

int		parse_line(t_scene **scene, char **data)
{
	if (data && data[0] && data[1])
	{
		if (data[0] == 's' && data[1] == 'p' && ft_tablen(data) == NB_SPHERE)
			return (parsing_sphere(&scene, data));
		if (data[0] == 'p' && data[1] == 'l' && ft_tablen(data) == NB_PLANE)
			return (parsing_plane(&scene, data));
		if (data[0] == 's' && data[1] == 'q' && ft_tablen(data) == NB_SQUARE)
			return (parsing_square(&scene, data));
		if (data[0] == 'c' && data[1] == 'y' && ft_tablen(data) == NB_CYLINDER)
			return (parsing_cylinder(&scene, data));
		if (data[0] == 't' && data[1] == 'r' && ft_tablen(data) == NB_TRIANGLE)
			return (parsing_triangle(&scene, data));
		if (data[0] == 'R' && ft_tablen(data) == NB_RES)
			return (parsing_resolution(&scene, data));
		if (data[0] == 'A' && ft_tablen(data) == NB_AL)
			return (parsing_ambient(&scene, data));
		if (data[0] == 'c' && ft_tablen(data) == NB_CAM)
			return (parsing_camera(&scene, data));
		if (data[0] == 'l' && ft_tablen(data) == NB_LIGHT)
			return (parsing_light(&scene, data));
		return (0);
	}
	return (1);
}

void	parsing(char *file)
{
	int		fd;
	int		ret;
	char	*line;
	char	**data;
	t_scene	scene;

	if (ft_str_end(file, ".rt"))
		print_error_and_exit("", 1);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error_and_exit("", 1);
	while (get_next_line(fd, &line, &ret) == 1)
	{
		split(line, WHITE_SPACES);
		if (!(parsing_line(&scene, data)))
		{
			ft_free_tab(&data);
			print_error_and_exit("", 1);
		}
		ft_free_tab(&data);
	}
	data = ft_split(line, WHITE_SPACES);
	if (ret < 0 || !(parsing_line(&scene, data)))
		print_error_and_exit("", 1);
}
