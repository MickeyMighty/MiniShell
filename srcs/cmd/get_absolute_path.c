/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 05:19:10 by loamar            #+#    #+#             */
/*   Updated: 2020/12/13 05:09:10 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

char 	*get_absolute_path(t_msh *msh, char *cmd)
{
	DIR 			*folder;
	struct dirent	*entry;

	folder = opendir(cmd);
	if (!folder)
	{
		printf("error folder\n"); // mauvais chemin
		return (0);
	}

	printf("folder -> %s\n", );
	// char 	bin[6];
	// char 	*tmp;
	//
	// bin = "/bin/\0"
	// msh->utils->path = ft_strdup(ft_strjoin(bin, msh->list->content));
	return (NULL);
}
