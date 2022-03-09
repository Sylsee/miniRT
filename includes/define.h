/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:04:49 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/09 13:49:39 by spoliart         ###   ########.fr       */
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
#  define BASE_COLOR_IMPACT 1.7
# endif
# ifndef LIGHT_IMPACT
#  define LIGHT_IMPACT 500000
# endif
# ifndef LIGHT_COLOR_IMPACT
#  define LIGHT_COLOR_IMPACT 5.5
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
