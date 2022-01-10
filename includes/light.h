/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:27:50 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/10 15:23:59 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADOW_H
# define SHADOW_H

t_color	light(t_scene scene, t_hit hit);
int		is_shaded(t_scene scene, t_hit hit, t_light *light);

#endif
