/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:55:57 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/12 22:50:44 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_hit
{
	double		dist;
	t_vector	normal;
	t_color		color;
	bool		mirror;
}			t_hit;

t_hit	intersection(t_scene scene, t_vector ray);
void	set_img(t_data data);
void	create_img(t_data *data, t_scene scene);
int		get_color(t_scene scene, t_vector ray, int nb_rebound);
void	put_color(t_data *data, int x, int y, int color);

/*	ray	*/
t_vector	new_ray(t_cam *cam, t_scene scene, int x, int y);

/*	color	*/
int		create_rgb(int r, int g, int b);
void	put_color(t_data *data, int x, int y, int color);
int		get_opposite(int color);

#endif
