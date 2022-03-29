/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:48:22 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/29 23:38:26 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

t_scene		parse(char *file);

t_p3		parse_point(char *x, char *y, char *z);
t_color		parse_color(char *r, char *g, char *b);
int			check_color(t_color color);
int			check_orientation(t_p3 dir);

void		parse_resolution(t_scene *scene, char **data);
void		parse_ambient(t_scene *scene, char **data);
void		parse_camera(t_scene *scene, char **data);
void		parse_light(t_scene *scene, char **data);

void		parse_sphere(t_scene *scene, char **data);
void		parse_plane(t_scene *scene, char **data);
void		parse_square(t_scene *scene, char **data);
void		parse_cylinder(t_scene *scene, char **data);
void		parse_triangle(t_scene *scene, char **data);

void		parse_bonus(t_scene *scene, char **data);
void		manage_scene(t_scene *scene);

void		check_arguments(int argc, char **argv);

#endif
