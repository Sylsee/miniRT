/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:26:23 by arguilla          #+#    #+#             */
/*   Updated: 2022/02/26 17:31:51 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	is_dir(char *dir)
{
	struct stat	s;
	int			err;

	err = stat(dir, &s);
	if (err == -1)
		return (false);
	else if (S_ISDIR(s.st_mode) && (access(dir, F_OK | W_OK | R_OK) == 0))
		return (true);
	return (false);
}
