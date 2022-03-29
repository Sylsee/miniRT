/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 00:59:14 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/30 00:59:20 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	video_mode(t_minirt *minirt)
{
	minirt->scene->video_mode = !minirt->scene->video_mode;
	if (minirt->scene->video_mode)
		create_bmp(*(minirt->data), *(minirt->scene),
			&(minirt->scene->frame_index), TMP_DIR);
	print_status(minirt);
}
