/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 18:50:20 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/23 18:00:29 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_lst	*lstnew(void *object, int id)
{
	t_lst	*new;

	new = alloc(sizeof(t_lst), NULL);
	if (!new)
		return (NULL);
	new->id = id;
	new->object = object;
	new->next = NULL;
	return (new);
}

void	lst_addfront(t_lst **alst, t_lst *new)
{
	if (new)
	{
		new->next = *alst;
		*alst = new;
	}
}

void	lstclear(t_lst **lst, void (*del)(void *))
{
	t_lst	*next;
	t_lst	*curr;

	next = *lst;
	while (next)
	{
		curr = next;
		next = curr->next;
		lstdelone(curr, del);
	}
	*lst = NULL;
}

void	lstdelone(t_lst *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->object);
		free(lst);
		lst = NULL;
	}
}
