/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:48:22 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/24 14:30:15 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

t_scene			parsing(char *file);

t_coord			parse_coord(char *x, char *y, char *z);
t_color			parse_color(char *r, char *g, char *b);
int				check_color(t_color color);
int				check_orientation(t_coord orientation);

void			parse_resolution(t_scene *scene, char **data);
void			parse_ambient(t_scene *scene, char **data);
void			parse_camera(t_scene *scene, char **data);
void			parse_light(t_scene *scene, char **data);

void			parse_sphere(t_scene *scene, char **data);
void			parse_plane(t_scene *scene, char **data);
void			parse_square(t_scene *scene, char **data);
void			parse_cylinder(t_scene *scene, char **data);
void			parse_triangle(t_scene *scene, char **data);

#endif
