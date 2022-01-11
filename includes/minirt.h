/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:14:07 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/11 16:38:16 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../lib/libft/includes/libft.h"
# include "../lib/minilibx/mlx.h"

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

# include "define.h"
# include "utils.h"
# include "scene.h"
# include "image.h"
# include "maths.h"
# include "events.h"
# include "parsing.h"
# include "error.h"
# include "objects.h"
# include "key.h"
# include "light.h"
# include "lst.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

void	minirt(int argc, char **argv);

#endif
