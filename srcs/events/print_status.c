/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 23:42:46 by arguilla          #+#    #+#             */
/*   Updated: 2022/01/16 00:22:57 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define RESET		"\033[0m"
#define BLACK		"\033[30m"      /* Black */
#define RED			"\033[31m"      /* Red */
#define GREEN		"\033[32m"      /* Green */
#define YELLOW		"\033[33m"      /* Yellow */
#define BLUE		"\033[34m"      /* Blue */
#define MAGENTA		"\033[35m"      /* Magenta */
#define CYAN		"\033[36m"      /* Cyan */
#define WHITE		"\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

static char	*return_string(bool value, char *s1, char *s2)
{
	if (value)
		return (s1);
	return (s2);
}

void	print_status(t_minirt *minirt)
{
	static int	i = 1;
	
	printf(RED"|-------| "RESET);
	printf(BOLDCYAN"%s"RESET GREEN"%d ", "MINIRT STATUS ", i);
	printf(RED"|-------| "RESET"\n");
	
	printf(RED"|"RESET);
	printf(YELLOW "%s", "Camera mode: "RESET);
	printf("%s\n", return_string(minirt->scene->camera_mode, "translation", "rotation"));		
	
	printf(RED"|"RESET);
	printf(YELLOW "%s", "Object type: "RESET);
	printf("%s\n", return_string(minirt->scene->object_type, "camera", "light"));		

	printf(RED"|"RESET);
	printf(YELLOW "%s", "Object mode: "RESET);
	printf("%s\n", return_string(minirt->scene->object_mode, "translation", "rotation"));		
	
	printf(RED"|"RESET);
	printf(YELLOW "%s"RESET, "Camera property: \n");

	if (minirt->scene->cam)
	{
		printf(RED"|"RESET);
		printf(GREEN"%s"RESET, "\tOrigin: \n");
		
		printf(RED"|"RESET);
		printf("\t\t%s%f\n", "x: ", minirt->scene->cam->origin.x);
		
		printf(RED"|"RESET);
		printf("\t\t%s%f\n", "y: ", minirt->scene->cam->origin.y);
		
		printf(RED"|"RESET);
		printf("\t\t%s%f\n", "z: ", minirt->scene->cam->origin.z);
		
		printf(RED"|"RESET);
		printf(GREEN"%s"RESET, "\tDirection: \n");
		
		printf(RED"|"RESET);
		printf("\t\t%s%f\n", "x: ", minirt->scene->cam->dir.x);
		
		printf(RED"|"RESET);
		printf("\t\t%s%f\n", "y: ", minirt->scene->cam->dir.y);
		
		printf(RED"|"RESET);
		printf("\t\t%s%f\n", "z: ", minirt->scene->cam->dir.z);
	}
	else
	{
		printf(RED"|"RESET);
		printf(RED"%s"RESET, "\tNone\n");
	}
	printf(RED"|---------------------------------|"RESET"\n");

	// TODO SEGFAULT QUAND PAS DE CAMS DANS SCENES>RT
	i++;
}
