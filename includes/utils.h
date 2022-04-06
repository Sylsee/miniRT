/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:17:53 by spoliart          #+#    #+#             */
/*   Updated: 2022/04/06 18:48:26 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	internal_error(char *s);
void	free_mlx(t_data data);
void	get_video_dir(int argc, char **argv, t_scene *scene, t_data *data);
void	check_arguments(int argc, char **argv);

#endif
