/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 04:30:49 by arguilla          #+#    #+#             */
/*   Updated: 2022/03/29 23:59:08 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	find_video_dir(int argc, char **argv, t_scene *scene)
{
	if (argc > 3 && is_dir(argv[3]))
		scene->video_dir = ft_strjoin(argv[3], "/");
	else if (is_dir("saves") || argc <= 3)
		scene->video_dir = ft_strdup("saves/");
	else
		internal_error("Can't find video directory");
	if (!scene->video_dir)
		internal_error("Malloc failed.");
	if (scene->cam == NULL)
		internal_error("You must provide a camera");
}
