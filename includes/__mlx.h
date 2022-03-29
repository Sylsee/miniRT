/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __mlx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 23:45:24 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/30 00:00:27 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MLX_H
# define __MLX_H

void	init_mlx(t_data *data, t_scene *scene);
void	free_mlx(t_data data);
void	set_img(t_data *data, t_scene *scene);

#endif /* __MLX_H */
