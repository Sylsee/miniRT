/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_video.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 10:42:10 by arguilla          #+#    #+#             */
/*   Updated: 2022/02/27 11:42:51 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_video(t_minirt *minirt)
{
	char		*buffer;
	char		*dir;
	size_t		size;
	static char	*ffmpeg = "/mnt/nfs/homes/arguilla/Documents/"
		"ffmpeg_4.4.1.orig/ffmpeg-4.4.1/ffmpeg";

	dir = minirt->scene->video_dir;
	size = 144 + (ft_strlen(dir) * 2);
	if (access(ffmpeg, F_OK | X_OK) != 0)
		return ;
	buffer = alloc(sizeof(char) * size, NULL);
	if (!buffer)
		return ;
	snprintf(buffer, size, "/mnt/nfs/homes/arguilla/Documents/"
		"ffmpeg_4.4.1.orig/ffmpeg-4.4.1/ffmpeg -y -f image2 -r 30 -i "
		"%ssave%%d.bmp -b 100000k %s/video.mov > /dev/null 2>&1", dir, dir);
	if (system(buffer))
		return ;
}
