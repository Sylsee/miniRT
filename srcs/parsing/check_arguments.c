/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:24:20 by arguilla          #+#    #+#             */
/*   Updated: 2022/04/03 13:59:19 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_arguments(int argc, char **argv, t_scene *scene, t_data *data)
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
		internal_error("Save option does not support any arguments.");
	find_video_dir(argc, argv, scene);
	data->save = false;
	if (argc == 3)
		data->save = true;
}
