/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 22:50:29 by spoliart          #+#    #+#             */
/*   Updated: 2021/03/26 23:25:57 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	minirt(int argc, char **argv)
{
	if (argc == 3)
	{
		if (ft_strcmp(argv[2], "--save"))
			minirt.save = 1;
		else
			exit("Wrong arguments\n");
	}
}
