/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 23:26:10 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/18 21:33:34 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_tablen(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return (-1);
	while (tab[i])
		i++;
	return (i);
}

void	parse_coord(char *x, char *y, char *z)
{
	t_coord	coord;

	coord = (t_coord)malloc(sizeof(coord));
	if (!coord)
		print_err_and_exit("Malloc error");
	coord.x = ft_atof(x);
	coord.y = ft_atof(y);
	coord.z = ft_atof(z);
	return (coord);
}

void	parse_color(char *r, char *g, char *b)
{
	t_color	color;

	color = (t_color)malloc(sizeof(color));
	if (!color)
		print_err_and_exit("Malloc error");
	color.r = ft_atof(r);
	color.g = ft_atof(g);
	color.b = ft_atof(b);
	return (color);
}

void	parse_resolution(t_scene *scene, char **data)
{
	t_coord	res;

	res = (t_coord)malloc(sizeof(res));
	if (!res)
		print_err_and_exit("Malloc error");
	res.x = ft_atoi(data[1]);
	res.y = ft_atoi(data[2]);
	scene->res = res;
}

void	parse_ambient(t_scene *cene, char **data)
{
	t_light	ambient;

	ambient = (t_light)malloc(sizeof(ambient));
	if (!ambient)
		print_err_and_exit("Malloc error");
	ambient.ratio = ft_atof(data[1]);
	ambient.color = parse_color(data[2], data[3], data[4]);
	scene->ambient = ambient;
}

void	parse_camera(t_scene *scene, char **data)
{
	t_cam	*cam;

	cam = (t_cam *)malloc(sizeof(cam));
	if (!cam)
		print_err_and_exit("Malloc error");
	cam->vector = vector;
	cam->vector.origin = parse_coord(data[1], data[2], data[3]);
	cam->vector.direction = parse_coord(data[4], data[5], data[6]);
	cam->fov = ft_atof(data[7]);
	ft_lstadd_front(&(scene->cam), ft_lstnew(cam));
}

void	parse_light(t_scene *scene, char **data)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(light));
	if (!light)
		print_err_and_exit("Malloc error");
	light->pos = parse_coord(data[1], data[2], data[3]);
	light->ratio = ft_atof(data[4]);
	light->color = parse_color(data[5], data[6], data[7]);
	ft_lstadd_front(&(scene->light), ft_lstnew(light));
}

void	parse_sphere(t_scene *scene, char **data)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(sphere));
	if (!sphere)
		print_err_and_exit("Malloc error");
	sphere->id = SPHERE;
	sphere->pos = parse_coord(data[1], data[2], data[3]);
	sphere->diameter = ft_atof(data[4]);
	sphere->color = parse_color(data[5], data[6], data[7]);
	ft_lstadd_front(&(scene->obj), ft_lstnew(sphere));
}

void	parse_plane(t_scene *scene, char **data)
{
	t_plane	plane;

	plane = (t_plane *)malloc(sizeof(plane));
	if (!plane)
		print_err_and_exit("Malloc error");
	plane->id = PLANE;
	plane->pos = parse_coord(data[1], data[2], data[3]);
	plane->orientation = parse_coord(data[4], data[5], data[6]);
	plane->color = parse_color(data[7], data[8], data[9]);
	ft_lstadd_front(&(scene->obj), ft_lstnew(plane));
}

void	parse_square(t_scene *scene, char **data)
{
	t_square	square;

	square = (t_square *)malloc(sizeof(square));
	if (!square)
		print_err_and_exit("Malloc error");
	square->id = SQUARE;
	square->pos = parse_coord(data[1], data[2], data[3]);
	square->orientation = parse_coord(data[4], data[5], data[6]);
	square->size = ft_atof(data[7]);
	square->color = parse_color(data[8], data[9], data[10]);
	ft_lstadd_front(&(scene->obj), ft_lstnew(square));
}

void	parse_cylinder(t_scene *scene, char **data)
{
	t_cylinder	cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(cylinder));
	if (!cylinder)
		print_err_and_exit("malloc error");
	cylinder->id = CYLINDER;
	cylinder->pos = parse_coord(data[1], data[2], data[3]);
	cylinder->orientation = parse_coord(data[4], data[5], data[6]);
	cylinder->diameter = ft_atof(data[7]);
	cylinder->height = ft_atof(data[8]);
	cylinder->color = parse_color(data[9], data[10], data[11]);
	ft_lstadd_front(&(scene->obj), ft_lstnew(cylinder));
}

void	parse_triangle(t_scene *scene, char **data)
{
	t_triangle	triangle;

	triangle = (t_triangle *)malloc(sizeof(triangle));
	if (!triangle)
		print_err_and_exit("malloc error");
	triangle->id = TRIANGLE;
	triangle->first = parse_coord(data[1], data[2], data[3]);
	triangle->second = parse_coord(data[4], data[5], data[6]);
	triangle->third = parse_coord(data[7], data[8], data[9]);
	triangle->color = parse_color(data[10], data[11], data[12]);
	ft_lstadd_front(&(scene->obj), ft_lstnew(triangle));
}

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

void	*init_scene()
{
}

t_scene	*parsing(char *file)
{
	int		fd;
	int		ret;
	char	*line;
	char	**data;
	t_scene	*scene;

	if (ft_str_end(file, ".rt"))
		print_err_and_exit("First argument must be a '.rt' file");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_err_and_exit("Open error");
	while (get_next_line(fd, &line, &ret) == 1)
	{
		data = ft_split(line, " \t,");
		if (!(parse_line(&scene, data)))
		{
			ft_free_tab(&data);
			print_err_and_exit("GNL error");
		}
		ft_free_tab(&data);
	}
	data = ft_split(line, " \t,");
	if (ret < 0 || !(parse_line(&scene, data)))
		print_err_and_exit("GNL error");
	return (scene);
}
/*
	t_list *list;
	t_oui *oui;
	t_oui *v;
	t_non non;

	oui = (t_oui *)malloc(sizeof(oui));
	oui->non.x = 42;
	printf("%d\n", oui->non.x);
	fflush(stdout);
	list = ft_lstnew(NULL);
	ft_lstadd_front(&list, ft_lstnew(oui));
	while (list->next)
	{
		v = (t_oui *)(list->content);
		printf("%d\n", v->non.x);
		fflush(stdout);
		list = list->next;
	}
*/
