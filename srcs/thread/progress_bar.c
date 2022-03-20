/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress_bar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 05:52:53 by arguilla          #+#    #+#             */
/*   Updated: 2022/03/20 05:53:10 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	display_progress_bar(int id, int end)
{
	static int	counter = 0;

	if (id != MAX_THREADS - 1)
		return ;
	printf("\r  |%.*s%.*s| %.2f%%", counter * 53 / end, PROGRESS_FULL,
		53 - counter * 53 / end, PROGRESS_EMPTY,
		(double)counter * 100 / end);
	fflush(stdout);
	++counter;
	if (counter == end)
		counter = 0;
}
