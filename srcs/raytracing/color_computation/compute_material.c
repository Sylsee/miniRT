/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_material.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:40:45 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/04 18:47:25 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	compute_material(t_scene scene, t_vector ray, t_hit hit, int nb_rebound)
{
	if (hit.material_type == REFLECTION)
		return (mirror(scene, ray, hit, nb_rebound));
	else
		return (refraction(scene, ray, hit, nb_rebound));
}
