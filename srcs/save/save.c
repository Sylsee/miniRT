/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <arguilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:07:10 by arguilla          #+#    #+#             */
/*   Updated: 2022/03/11 00:27:28 by spoliart         ###   ########.fr       */
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
	*(unsigned int *)(*buffer + 28) = 32;
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
	y = scene.res.y;
	while (y--)
	{
		x = 0;
		while (x < scene.res.x)
		{
			j = (x * (data.pixel_bits / 8)) + (y * data.line_bytes);
			*(*buffer + i++) = *(data.data + j++);
			*(*buffer + i++) = *(data.data + j++);
			*(*buffer + i++) = *(data.data + j++);
			*(*buffer + i++) = *(data.data + j);
			x++;
		}
	}
}

static char	*get_bmp_name(char *dir, int id)
{
	char	*name;

	name = ft_strjoin("save", ft_itoa(id));
	name = ft_strjoin(name, ".bmp");
	name = ft_strjoin(dir, name);
	if (!name)
		internal_error("unable to allocate memory");
	return (name);
}

void	create_bmp(t_data data, t_scene scene, int *id)
{
	int				fd;
	char			*buffer;
	unsigned int	size;
	unsigned int	i;

	i = 0;
	size = (unsigned int)(scene.res.x * scene.res.y * 4);
	buffer = alloc(sizeof(char) * (size + HEADER_SIZE), NULL);
	if (!buffer)
		exit(1);
	i = 0;
	while (i < size + HEADER_SIZE)
		buffer[i++] = 0;
	bmp_header(&buffer, scene.res.x, scene.res.y, size);
	bmp_data(&buffer, scene, data);
	fd = open(get_bmp_name("saves/tmp/", ++(*id)),
			O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (fd < 0)
		exit(1);
	if (!write(fd, buffer, (size + HEADER_SIZE)))
		exit (1);
	close(fd);
}
