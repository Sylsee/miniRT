/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:53:04 by spoliart          #+#    #+#             */
/*   Updated: 2021/03/20 15:18:03 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>

int main()
{
	int y = 249;
	int x = 249;
	void *ptr = mlx_init();
	void *win = mlx_new_window(ptr, 600, 600, "This is a test !");
	while (++y <= 350)
	{
		x = 249;
		while (++x <= 350)
			mlx_pixel_put(ptr, win, x, y, 0);
	}
	mlx_loop(ptr);
}
