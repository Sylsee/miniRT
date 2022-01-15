/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_movement_keycode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:12:01 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/15 20:25:11 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_movement_keycode(int keycode)
{
	return (keycode == W_KEY || keycode == A_KEY || keycode == S_KEY
		|| keycode == D_KEY || keycode == R_KEY || keycode == T_KEY);
}
