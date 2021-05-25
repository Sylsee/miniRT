/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 23:55:57 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/26 00:25:44 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "minirt.h"

void	create_img(t_minirt *minirt, t_scene *scene);
void	put_color(t_minirt *minirt, t_scene *scene, int x, int y);

#endif
