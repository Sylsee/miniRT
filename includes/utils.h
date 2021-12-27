/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 18:17:53 by spoliart          #+#    #+#             */
/*   Updated: 2021/12/23 17:56:02 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

typedef struct s_lst
{
	int				id;
	void			*object;
	struct s_lst	*next;
}				t_lst;

t_lst	*lstnew(void *content, int id);
void	lst_addfront(t_lst **alst, t_lst *new);
void	lstdelone(t_lst *lst, void (*del)(void *));
void	lstclear(t_lst **lst, void (*del)(void *));

void	internal_error(char *s);

#endif
