/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:13:36 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/29 16:19:01 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clean_minirt(t_minirt *minirt)
{
	mlx_destroy(minirt->mlx);
}

void	clean(t_minirt *minirt, t_scene *scene)
{
	clean_minirt(minirt);
	free(minirt);
	clean_scene(scene);
	free(scene);
}
