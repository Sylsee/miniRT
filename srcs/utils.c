/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 03:21:56 by spoliart          #+#    #+#             */
/*   Updated: 2021/03/29 03:25:56 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	add_back(t_elem *elem)
{
	t_elem tmp;

	tmp = *elem;
	if (tmp)
		while (tmp->next)
			tmp = tmp->next;
	tmp->
}
