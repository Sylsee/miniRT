/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:17:53 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/22 04:31:38 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	internal_error(char *s);
void	free_mlx(t_data data);
void	find_video_dir(int argc, char **argv, t_scene *scene);

#endif
