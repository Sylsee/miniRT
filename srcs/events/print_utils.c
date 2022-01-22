/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:07:21 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/18 22:08:37 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*return_string(bool value, char *s1, char *s2)
{
	if (value)
		return (s1);
	return (s2);
}

void	print_p3(t_p3 coord, char *title)
{
	if (title)
		printf(GREEN"\t%s\n"RESET, title);
	printf("\t\t%s%f\n", "x: ", coord.x);
	printf("\t\t%s%f\n", "y: ", coord.y);
	printf("\t\t%s%f\n", "z: ", coord.z);
}
