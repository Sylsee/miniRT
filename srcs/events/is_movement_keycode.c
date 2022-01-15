/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_movement_keycode.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:12:01 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/15 21:50:38 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_movement_keycode(int keycode)
{
	return (keycode == W_KEY || keycode == A_KEY || keycode == S_KEY
		|| keycode == D_KEY || keycode == R_KEY || keycode == T_KEY);
}

bool	is_object_movement_keycode(int keycode)
{
	return (keycode == UP_KEY || keycode == LEFT_KEY
		|| keycode == DOWN_KEY || keycode == RIGHT_KEY || keycode == O_KEY
		|| keycode == P_KEY);
}
