/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:27:38 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/11 20:43:51 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H


typedef struct s_lst
{
	int				id;
	void			*object;
	struct s_lst	*next;
}				t_lst;


typedef struct s_data
{
	bool		save;
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
}				t_data;

#include "scene.h"

typedef struct s_minirt
{
	t_data	*data;
	t_scene	*scene;
}				t_minirt;

#endif
