/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <spoliart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 17:59:26 by spoliart          #+#    #+#             */
/*   Updated: 2021/05/22 18:14:29 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char *s;

	if (!(s = (char *)malloc(sizeof(s) * 15)))
		return (1);
	s = "LOOOL";
	printf("%s\n", s);
	return (0);
}
