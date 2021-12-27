/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:50:12 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/23 17:53:30 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

typedef struct s_lst
{
	int				id;
	void			*object;
	struct s_list	*next;
}				t_lst;

t_lst	*lstnew(void *object, int id);
void	lst_addfront(t_lst **alst, t_lst *new);
void	lstclear(t_lst **alst, void (*del)(void *));
void	lstdelone(t_lst *lst, void (*del)(void *));

#endif
