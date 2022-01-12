/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:14:07 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/11 20:38:23 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../lib/libft/includes/libft.h"
# include "../lib/minilibx/mlx.h"

# include "data.h"

# include "define.h"
# include "utils.h"
# include "lst.h"
# include "scene.h"
# include "image.h"
# include "maths.h"
# include "events.h"
# include "parsing.h"
# include "error.h"
# include "objects.h"
# include "key.h"
# include "light.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

void	minirt(int argc, char **argv);

#endif
