/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:24:20 by arguilla          #+#    #+#             */
/*   Updated: 2022/03/04 18:53:26 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_arguments(int argc, char **argv)
{
	if (argc < 2)
		internal_error("missing file operand");
	else if (argc > 4)
		internal_error("too many arguments");
	else if (ft_strend(argv[1], ".rt") == 0)
		internal_error("First argument must be a `.rt' file");
	else if (argc > 2 && ft_strequ(argv[2], "--save") == 0
		&& ft_strequ(argv[2], "--video") == 0)
		internal_error("Second argument must be `--save' or `--video'");
	else if (argc == 3 && ft_strequ(argv[2], "--video"))
		internal_error("Video option must be have one argument.");
	else if (argc > 3 && ft_strequ(argv[2], "--save"))
		internal_error("Save option does not have a argument.");
}
