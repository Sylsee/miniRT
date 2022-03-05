/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:14:07 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/19 19:03:06 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../lib/libft/includes/libft.h"
# include "../lib/minilibx/mlx.h"
# include "scene.h"
# include "define.h"
# include "utils.h"
# include "lst.h"
# include "scene.h"
# include "image.h"
# include "save.h"
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

typedef struct s_lst
{
	int				id;
	void			*object;
	struct s_lst	*next;
}				t_object_list;

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

typedef struct s_minirt
{
	t_data	*data;
	t_scene	*scene;
}				t_minirt;

void	minirt(int argc, char **argv);

#endif
