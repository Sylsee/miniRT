/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:36:51 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/22 23:13:16 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_minirt(t_minirt *minirt)
{
	if (!(minirt = (t_minirt *)malloc(sizeof(t_minirt))))
		print_err_and_exit("Malloc error");
	minirt->save = 0;;
	minirt-> = ;
}

void	minirt(int argc, char **argv)
{
	t_minirt	*minirt;
	t_scene		*scene;

	scene = parsing(argv[1]);
	init_minirt(&minirt);
	if (argc == 3)
		minirt.save = 1;

}

int		main(int argc, char **argv)
{
	if (argc == 2 || (argc == 3 && ft_strict_strcmp(argv[2], "--save")))
		minirt(argc, argv);
	else if (argc < 2 || argc > 3)
		print_err_and_exit("Wrong number of arguments");
	else
		print_err_and_exit("Second argument must be '--save'");
	return (0);
}
