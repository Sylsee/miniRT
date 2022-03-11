/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_video.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:42:10 by arguilla          #+#    #+#             */
/*   Updated: 2022/03/11 00:30:07 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_video(t_minirt *minirt)
{
	char		*buffer;
	const char	*dir = minirt->scene->video_dir;

	buffer = alloc(sizeof(char) * (91 + ft_strlen(dir)), NULL);
	if (!buffer)
		return ;
	sprintf(buffer, "ffmpeg -y -f image2 -r 30 -i "
		"%ssave%%d.bmp -b 100000k %s/video.mov > /dev/null 2>&1", "saves/tmp/", dir);
	if (system(buffer))
		printf("minirt: system() call: %s\n", strerror(errno));
	free_one(buffer, NULL);
}
