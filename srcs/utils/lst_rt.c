/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_rt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 18:50:20 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/30 13:22:29 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_list_rt	*ft_lstnew_rt(void *content, int id)
{
	t_list_rt *new;

	if (!(new = malloc(sizeof(new))))
		return (NULL);
	new->id = id;
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front_rt(t_list_rt **alst, t_list_rt *new)
{
	if (new)
		new->next = *alst;
	*alst = new;
}

void	ft_lstclear_rt(t_list_rt **lst, void (*del)(void *))
{
	t_list_rt *next;
	t_list_rt *curr;

	next = *lst;
	while (next)
	{
		curr = next;
		next = curr->next;
		ft_lstdelone_rt(curr, del);
	}
	*lst = NULL;
}

void	ft_lstdelone_rt(t_list_rt *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}
