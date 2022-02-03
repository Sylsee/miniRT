/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:57:14 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/03 21:44:42 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

double	min(double a, double b);
double	max(double a, double b);
t_p3	new_p3(double x, double y, double z);
void	normalize(t_p3 *v);
t_p3	get_normalize(t_p3 v);
double	get_norm2(t_p3 v);
double	get_norm(t_p3 v);
double	v_dot(t_p3 v, t_p3 u);
t_p3	v_add(t_p3 v, t_p3 u);
t_p3	v_sub(t_p3 v, t_p3 u);
t_p3	v_scale(t_p3 v, double f);
t_p3	v_div(t_p3 v, double f);
t_p3	v_cross(t_p3 u, t_p3 v);

#endif
