/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:14:07 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/14 01:09:54 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../lib/libft/includes/libft.h"
# include "../lib/minilibx/mlx.h"

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

# include "define.h"
# include "utils.h"
# include "lst.h"
# include "scene.h"
# include "image.h"
# include "maths.h"
# include "parsing.h"
# include "error.h"
# include "objects.h"
# include "key.h"
# include "raytrace.h"
# include "events.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

void	minirt(int argc, char **argv);

#endif
