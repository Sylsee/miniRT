/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:50:12 by spoliart          #+#    #+#             */
/*   Updated: 2022/03/04 17:46:05 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LST_H
# define LST_H

t_object_list	*lstnew(void *object, int id);
void			lst_addfront(t_object_list **alst, t_object_list *new);
void			lstclear(t_object_list **alst, void (*del)(void *));
void			lstdelone(t_object_list *lst, void (*del)(void *));
void			cam_lstadd_back(t_cam **alst, t_cam *new);
t_cam			*cam_lstlast(t_cam *lst);
void			link_cam_lst(t_cam *cam);

#endif
