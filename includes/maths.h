/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:57:14 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/04 14:05:52 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# define PI 3.1415926535897932

void	normalize(t_coord *v);
double	get_norm2(t_coord v);
double	prod_scalaire(t_coord v, t_coord u);
t_coord	v_add(t_coord v, t_coord u);
t_coord	v_sub(t_coord v, t_coord u);
t_coord	v_scale(t_coord v, double f);

#endif
