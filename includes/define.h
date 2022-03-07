/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:04:49 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/07 19:12:04 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/* ********** Light ********** */
# ifndef DIFFUSE_COEF
#  define DIFFUSE_COEF 0.9
# endif
# ifndef SPECULAR_COEF
#  define SPECULAR_COEF 0.1
# endif

# ifndef BASE_COLOR_IMPACT
#  define BASE_COLOR_IMPACT 1.5
# endif
# ifndef LIGHT_IMPACT
#  define LIGHT_IMPACT 500000
# endif
# ifndef LIGHT_COLOR_IMPACT
#  define LIGHT_COLOR_IMPACT 4.5
# endif
# ifndef AMBIENT_IMPACT
#  define AMBIENT_IMPACT 0.5
# endif
# ifndef AMBIENT_COLOR_IMPACT
#  define AMBIENT_COLOR_IMPACT 0.1
# endif
# ifndef INTENSITY_IMPACT
#  define INTENSITY_IMPACT 0.9
# endif

/* ********** Color computation ********** */
# ifndef AIR_REFRACTIVE_IMPACT
#  define AIR_REFRACTIVE_IMPACT 1.000129
# endif

/* ********** User modification ********** */
# define SPHERE_DIAMETER_SIZE 1
# define CYLINDER_WIDTH_SIZE 1
# define CYLINDER_HEIGHT_SIZE 1

# define TRANSLATION 1
# define ROTATION 0
# define CAMERA 1
# define LIGHT	0

# define MOVE_SIZE 100
# define X_TRANSLATION_SIZE MOVE_SIZE
# define Y_TRANSLATION_SIZE MOVE_SIZE
# define Z_TRANSLATION_SIZE MOVE_SIZE
# define X_ROTATION_SIZE 0.1
# define Y_ROTATION_SIZE 0.1
# define Z_ROTATION_SIZE 0.1
# define X_MOVE_LIGHT 1
# define Y_MOVE_LIGHT 1
# define Z_MOVE_LIGHT 1

/* ********** Print color ********** */
# define RESET   "\033[0m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define CYAN    "\033[36m"
# define BOLDCYAN   "\033[1m\033[36m"

/* ********** Progress bar ********** */
# define PROGRESS_EMPTY "------------------------------------------------------"
# define PROGRESS_FULL  "######################################################"

#endif
