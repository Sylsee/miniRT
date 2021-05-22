/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:36:51 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/22 20:32:26 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	minirt(char **argv)
{
	t_scene	*scene;

	parsing(argv[1], scene);
}

int		main(int argc, char **argv)
{
	if (argc == 2 || argc == 3)
		minirt(argv);
	else
		print_error_and_exit("Wrong number of arguments");
	return (0);
}
