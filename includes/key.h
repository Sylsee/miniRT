/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 17:10:27 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/29 17:30:14 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# if defined(_WIN64) || defined(_WIN32)
#  define

# elif __APPLE__
#  define

# elif __linux
#  define

# else
#  error "Unknown compiler"

# endif

#endif
