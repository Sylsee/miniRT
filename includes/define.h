/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:04:49 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/18 17:59:54 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/* ********** Light ********** */

# define INTENSITY_IMPACT 5000000

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

/* ********** Bmp Directories ********** */
# define TMP_DIR	"saves/tmp/"	
# define SAVE_DIR	"saves/"
#endif
