/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 18:57:59 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/13 18:51:47 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	internal_error(char *s)
{
	ft_putstr_fd("Minirt: ", STDERR_FILENO);
	ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
