/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:09:24 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/10 23:04:55 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_bonus(t_scene *scene, char **data)
{
	if (ft_tablen(data) < 3)
		return ;
	if (ft_strequ("ANTIALIASING", data[1]))
		scene->antialiasing = ft_atoi(data[2]);
	else if (ft_strequ("RAY_MAX_BOUNCES", data[1]))
		scene->ray_max_bounces = ft_atoi(data[2]);
	else if (ft_strequ("BACKGROUND_COLOR", data[1]))
		scene->bg_color = ft_xtoi(data[2]);
}

/*
	else if (ft_strequ("", data[1]))
		scene-> = ft_atoi(data[2]);
*/
