/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 08:33:48 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/18 22:08:02 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

int		destroy_window(t_data *data);
int		exit_window(int keycode, t_data *data);
void	cameras_event(int keycode, t_minirt *minirt);
void	init_mlx_events(t_minirt *minirt);
void	update_window(t_minirt *minirt);
bool	is_movement_keycode(int keycode);
bool	is_object_movement_keycode(int keycode);
void	lights_event(int keycode, t_minirt *minirt);
void	objects_event(int keycode, t_minirt *minirt);
void	update_sphere_properties(int keycode, t_minirt *minirt);
void	update_cylinder_properties(int keycode, t_minirt *minirt);
void	update_object_properties(int keycode, t_minirt *minirt);
bool	is_object_properties_keycode(int keycode);
void	print_status(t_minirt *minirt);
void	print_sphere(t_sphere *sphere);
void	print_plane(t_plane *plane);
void	print_p3(t_p3 coord, char *title);
void	print_square(t_square *square);
void	print_cylinder(t_cylinder *cylinder);
void	print_triangle(t_triangle *triangle);
char	*return_string(bool value, char *s1, char *s2);

#endif
