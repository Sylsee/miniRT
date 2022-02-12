/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:07:10 by arguilla          #+#    #+#             */
/*   Updated: 2022/02/13 00:42:39 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	bmp_header(char **buffer, int x, int y, unsigned int size)
{
	*(unsigned int *)*buffer = *(const unsigned int *)(unsigned long)"BM";
	*(unsigned int *)(*buffer + 2) = (size + HEADER_SIZE);
	*(unsigned int *)(*buffer + 6) = 0u;
	*(unsigned int *)(*buffer + 10) = HEADER_SIZE;
	*(unsigned int *)(*buffer + 14) = HEADER_SIZE - 14;
	*(unsigned int *)(*buffer + 18) = (unsigned int)x;
	*(unsigned int *)(*buffer + 22) = (unsigned int)y;
	*(unsigned int *)(*buffer + 26) = 1;
	*(unsigned int *)(*buffer + 28) = 24;
	*(unsigned int *)(*buffer + 30) = 0;
	*(unsigned int *)(*buffer + 34) = (unsigned int)size;
	*(unsigned int *)(*buffer + 38) = 3780;
	*(unsigned int *)(*buffer + 42) = 3780;
	*(int *)(*buffer + 46) = 0;
	*(int *)(*buffer + 50) = 0;
}

static void	bmp_data(char **buffer, t_scene scene, t_data data)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = HEADER_SIZE;
	y = scene.res.y + 1;
	while (--y)
	{
		x = 0;
		while (x <= scene.res.x)
		{
			j = (x * (data.pixel_bits / 8)) + (y * data.line_bytes);
			*(*buffer + i++) = *(data.data + j++);
			*(*buffer + i++) = *(data.data + j++);
			*(*buffer + i++) = *(data.data + j);
			x++;
		}
	}
}

void	create_bmp(t_data data, t_scene scene)
{
	int				fd;
	char			*buffer;
	unsigned int	size;
	unsigned int	i;

	i = 0;
	size = (unsigned int)(scene.res.x * scene.res.y * 3);
	buffer = alloc(sizeof(char) * (size + HEADER_SIZE), NULL);
	if (!buffer)
		exit(1);
	i = 0;
	while (i < size + HEADER_SIZE)
		buffer[i++] = 0;
	bmp_header(&buffer, scene.res.x, scene.res.y, size);
	bmp_data(&buffer, scene, data);
	fd = open("save.bmp", O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd < 0)
		exit(1);
	if (!write(fd, buffer, (size + HEADER_SIZE)))
		exit (1);
	close(fd);
}
