/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 08:33:48 by arguilla          #+#    #+#             */
/*   Updated: 2022/02/05 21:56:32 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

typedef struct s_minirt t_minirt;

int		destroy_window(t_data *data);
int		exit_window(int keycode, t_data *data);
void	cameras_event(int keycode, t_minirt *minirt);
void	init_mlx_events(t_data *data, t_scene *scene);
void	update_window(t_minirt *minirt);
bool	is_movement_keycode(int keycode);
bool	is_object_movement_keycode(int keycode);
void	lights_event(int keycode, t_minirt *minirt);
void	objects_event(int keycode, t_minirt *minirt);
void	update_sphere_properties(int keycode, t_minirt *minirt, t_sphere *s);
void	update_cylinder_properties(int keycode, t_minirt *minirt,
			t_cylinder *c);
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
int		mouse_hook(int mouse_code, int x, int y, t_minirt *minirt);

#endif
