/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 21:57:14 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/26 01:07:48 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# include "minirt.h"

# define PI 3.1415926535897932

void	normalize(t_coord *v);
double	norma2(t_coord v);
double	prod_scalaire(t_coord v, t_coord u);
t_coord	vec_add(t_coord v, t_coord u);
t_coord	vec_minus(t_coord v, t_coord u);

#endif
