/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:04:49 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/14 19:18:12 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/* ********** Light ********** */

/* Ambient */
# ifndef AMBIENT_IMPACT
#  define AMBIENT_IMPACT 10
# endif
# ifndef AMBIENT_COLOR_IMPACT
#  define AMBIENT_COLOR_IMPACT 0.1
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
