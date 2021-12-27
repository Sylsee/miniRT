/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:57:14 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/23 18:10:30 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# define PI 3.1415926535897932

void	normalize(t_coord *v);
double	get_norm2(t_coord v);
double	prod_scalaire(t_coord v, t_coord u);
t_coord	vec_add(t_coord v, t_coord u);
t_coord	vec_minus(t_coord v, t_coord u);

#endif
