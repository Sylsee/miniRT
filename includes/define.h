/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:04:49 by spoliart          #+#    #+#             */
/*   Updated: 2022/02/12 22:36:38 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

#ifndef AIR_REFRACTIVE_IMPACT
# define AIR_REFRACTIVE_IMPACT 1.000129
#endif

# define SPHERE_DIAMETER_SIZE 1
# define CYLINDER_WIDTH_SIZE 1
# define CYLINDER_HEIGHT_SIZE 1

# define TRANSLATION 1
# define ROTATION 0
# define CAMERA 1
# define LIGHT	0

# define RESET   "\033[0m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define CYAN    "\033[36m"
# define BOLDCYAN   "\033[1m\033[36m"

# define MOVE_SIZE 1
# define X_TRANSLATION_SIZE MOVE_SIZE
# define Y_TRANSLATION_SIZE MOVE_SIZE
# define Z_TRANSLATION_SIZE MOVE_SIZE
# define X_ROTATION_SIZE 0.1
# define Y_ROTATION_SIZE 0.1
# define Z_ROTATION_SIZE 0.1
# define X_MOVE_LIGHT 1
# define Y_MOVE_LIGHT 1
# define Z_MOVE_LIGHT 1

#endif
