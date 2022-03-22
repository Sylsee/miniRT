/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_bar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 05:52:53 by arguilla          #+#    #+#             */
/*   Updated: 2022/03/20 21:06:13 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	display_progress_bar(int end)
{
	static int	counter = 0;

	printf("\r  |%.*s%.*s| %.2f%%", counter * 53 / end, PROGRESS_FULL,
		53 - counter * 53 / end, PROGRESS_EMPTY,
		(double)counter * 100 / end);
	fflush(stdout);
	++counter;
	if (counter == end)
		counter = 0;
}
