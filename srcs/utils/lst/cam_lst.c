/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:58:09 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/11 17:36:11 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	link_cam_lst(t_cam *cam)
{
	t_cam	*tail;

	if (cam && cam->next)
	{
		tail = cam_lstlast(cam);
		tail->next = cam;
		cam->prev = tail;
	}
}

t_cam	*cam_lstlast(t_cam *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

void	cam_lstadd_back(t_cam **alst, t_cam *new)
{
	t_cam	*tmp;

	tmp = cam_lstlast(*alst);
	if (tmp)
	{
		tmp->next = new;
		new->prev = tmp;
		new->id = tmp->id + 1;
	}
	else
	{
		new->prev = NULL;
		new->next = NULL;
		new->id = 1;
		*alst = new;
	}
}
