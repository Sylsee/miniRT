/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 08:33:48 by arguilla          #+#    #+#             */
/*   Updated: 2022/03/30 00:59:29 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

/* ********** Key event ********** */
# define ESC 65307

# define RIGHT_CLICK 1
# define LEFT_CLICK 3
# define ROLL_UP 4
# define ROLL_DOWN 5

/* ********** User modification ********** */
# define SPHERE_DIAMETER_SIZE 100
# define CYLINDER_WIDTH_SIZE 100
# define CYLINDER_HEIGHT_SIZE 100

# define TRANSLATION 1
# define ROTATION 0
# define CAMERA 1
# define LIGHT	0

# define MOVE_SIZE 100
# define X_TRANSLATION_SIZE MOVE_SIZE
# define Y_TRANSLATION_SIZE MOVE_SIZE
# define Z_TRANSLATION_SIZE MOVE_SIZE
# define X_ROTATION_SIZE 0.1
# define Y_ROTATION_SIZE 0.1
# define Z_ROTATION_SIZE 0.1
# define X_MOVE_LIGHT 1000
# define Y_MOVE_LIGHT 1000
# define Z_MOVE_LIGHT 1000

typedef struct s_minirt	t_minirt;

int		key_events(int keycode, t_minirt *minirt);
void	init_mlx_events(t_data *data, t_scene *scene);

void	video_mode(t_minirt *minirt);
int		exit_minirt(t_minirt *minirt);
void	cameras_event(int keycode, t_minirt *minirt);
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
