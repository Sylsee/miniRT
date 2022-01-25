/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:36:51 by spoliart          #+#    #+#             */
/*   Updated: 2022/01/14 01:12:50 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void free_leaks(void) __attribute__((destructor));

void free_leaks(void)
{
	free_area(NULL);
}

/*
**	Initialize minilibx utilities
*/

void init_mlx(t_data *data, t_scene scene)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		internal_error("unable to initialize minilibx");
	if (data->save == false)
	{
		data->win = mlx_new_window(data->mlx, scene.res.x,
								   scene.res.y, "MiniRT");
		if (!data->win)
			internal_error("unable to create minilibx window");
	}
	data->img = mlx_new_image(data->mlx, scene.res.x, scene.res.y);
	if (!data->img)
		internal_error("unable to create minilibx image");
	data->data = mlx_get_data_addr(data->img, &data->pixel_bits,
								   &data->line_bytes, &data->endian);
}

void set_img(t_data *data, t_scene *scene)
{
	init_mlx_events(data, scene);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_loop(data->mlx);
}

# define HEADER_SIZE  54
typedef struct s_bmpheader
{
	char bytes_signature[2];
	unsigned int sizeof_bitmap_file;
	unsigned int reserved_bytes;
	unsigned int pixeldata_offset;
} t_bmpheader;

typedef struct s_bmpinfoheader
{
	unsigned int sizeof_thisheader;
	unsigned int width;
	unsigned int height;
	unsigned short number_of_color_planes;
	unsigned short color_depth;
	unsigned int method_compression;
	unsigned int raw_bitmap_datasize;
	unsigned int hresolution;
	unsigned int vresolution;
	unsigned int colortable_entries;
	unsigned int important_colors;
} t_bmpinfoheader;

void fill_header(t_bmpheader *header, t_bmpinfoheader *dib_header, int x, int y)
{
	header->bytes_signature[0] = 'B';
	header->bytes_signature[1] = 'M';
	header->sizeof_bitmap_file = (x * y * 3) + 54;
	header->reserved_bytes = 0;
	header->pixeldata_offset = 54;
	dib_header->sizeof_thisheader = 40;
	dib_header->width = x;
	dib_header->height = y;
	dib_header->number_of_color_planes = 1;
	dib_header->color_depth = 24;
	dib_header->method_compression = 0;
	dib_header->hresolution = 3780;
	dib_header->vresolution = 3780;
	dib_header->colortable_entries = 0;
	dib_header->important_colors = 0;
}

void bmp_header(char **buffer, int x, int y, unsigned int size)
{
	/*
	t_bmpheader header;
	t_bmpinfoheader dib_header;

	fill_header(&header, &dib_header, x, y);
	*/*(unsigned int *)*buffer = *(const unsigned int *)(unsigned long)"BM";
	*(unsigned int *)(*buffer + 2) = (size + HEADER_SIZE);
	*(unsigned int *)(*buffer + 6) = 0u;
	*(unsigned int *)(*buffer + 10) = HEADER_SIZE;
	*(unsigned int *)(*buffer + 14) = HEADER_SIZE - 14;
	*(unsigned int *)(*buffer + 18) = x;
	*(unsigned int *)(*buffer + 22) = y;
	*(unsigned int *)(*buffer + 26) = 1;
	*(unsigned int *)(*buffer + 28) = 24;
	*(unsigned int *)(*buffer + 30) = 0;
	*(unsigned int *)(*buffer + 34) = (unsigned int)size;
	*(unsigned int *)(*buffer + 38) = 3780;
	*(unsigned int *)(*buffer + 42) = 3780;
	*(int *)(*buffer + 46) = 0;
	*(int *)(*buffer + 50) = 0;
/*	

	if (write(fd, &(header.bytes_signature), 2) < 0)
		exit (1);
	if (write(fd, &(header.sizeof_bitmap_file), 4) < 0)
		exit (1);
	if (write(fd, &(header.reserved_bytes), 4) < 0)
		exit (1);
	if (write(fd, &(header.pixeldata_offset), 4) < 0)
		exit (1);
	if (write(fd, &(dib_header.sizeof_thisheader), 4) < 0)
		exit (1);
	if (write(fd, &(dib_header.width), 4) < 0)
		exit (1);
	if (write(fd, &(dib_header.height), 4) < 0)
		exit (1);
	if (write(fd, &(dib_header.number_of_color_planes), 2) < 0)
		exit (1);
	if (write(fd, &(dib_header.color_depth), 2) < 0)
		exit (1);
	if (write(fd, &(dib_header.method_compression), 4) < 0)
		exit (1);
	if (write(fd, &(dib_header.raw_bitmap_datasize), 4) < 0)
		exit (1);
	if (write(fd, &(dib_header.hresolution), 4) < 0)
		exit (1);
	if (write(fd, &(dib_header.vresolution), 4) < 0)
		exit (1);
	if (write(fd, &(dib_header.colortable_entries), 4) < 0)
		exit (1);
	if (write(fd, &(dib_header.important_colors), 4) < 0)
		exit (1);*/
}

void bmp_data(char **buffer, t_scene scene, t_data data)
{
	int x;
	int y;
	int i;
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
			*(*buffer + i++) = *(data.data + j);
			x++;
		}
	}
}


void create_bmp(t_data data, t_scene scene)
{
	int fd;
	char *buffer;
	unsigned int	size;
	unsigned int	i;

	i = 0;
	size = scene.res.x * scene.res.y * 3;
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

void minirt(int argc, char **argv)
{
	t_data data;
	t_scene scene;

	data.save = false;
	if (argc == 3)
		data.save = true;
	scene = parsing(argv[1]);

	(void)data;
	(void)scene;

	init_mlx(&data, scene);
	create_img(&data, scene);
	if (data.save == false)
		set_img(&data, &scene);
	else
		create_bmp(data, scene);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		internal_error("missing file operand\n");
	else if (argc > 3)
		internal_error("too many arguments");
	else if (argc == 3 && ft_strequ(argv[2], "--save") == 0)
		internal_error("Second argument must be `--save'");
	else if (ft_strend(argv[1], ".rt") == 0)
		internal_error("First argument must be a `.rt' file");
	init_area(NULL);
	minirt(argc, argv);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
