/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:55:57 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/19 18:03:16 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

enum
{
	NONE = 0,
	REFLECTION = 1,
	REFRACTION = 2,
	CHECKBOARD = 3
};

typedef struct s_data	t_data;

typedef struct s_hit
{
	double				dist;
	union
	{
		struct
		{
			t_vector	normal;
			t_color		color;
			int			material_type;
			double		ior;
		};
		struct
		{
			int			type;
			void		*object;
		};
	};
}			t_hit;

t_hit		intersection(t_scene scene, t_vector ray, int mode);
void		set_img(t_data *data, t_scene *scene);
void		create_img(t_data *data, t_scene scene);
t_color		get_color(t_scene scene, t_vector ray, int nb_rebound);
void		put_color(t_data *data, int x, int y, int color);

/* cam */
void		param_cam(t_cam *cam, t_couple res);

/*	ray	*/
t_vector	new_ray(t_cam *cam, t_scene scene, double x, double y);

/*	color	*/
int			create_rgb(int r, int g, int b);
void		put_color(t_data *data, int x, int y, int color);
int			get_opposite(int color);
t_color		new_color(int color);

#endif
