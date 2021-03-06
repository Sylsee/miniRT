/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 17:35:24 by arguilla          #+#    #+#             */
/*   Updated: 2022/03/18 20:15:45 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_H
# define SAVE_H

# define HEADER_SIZE  54

typedef struct s_minirt	t_minirt;

void	create_bmp(t_data data, t_scene scene, int *id, char *dir);
void	create_video(t_minirt *minirt);
#endif