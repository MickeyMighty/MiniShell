/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 05:19:10 by loamar            #+#    #+#             */
/*   Updated: 2020/12/14 15:50:07 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static char 	*get_dir(char *path, char *cmd)
{
	DIR 			*dir;
	struct dirent	*entry;

	dir = opendir(cmd);
	if (!dir)
		return (0);
	while (entry = readdir(dir))
	{
		if (!ft_strcmp(dir->d_name, path))
		{
			closedir(dir);
			return (cmd);
		}
	}
	closedir(folder);
	return (NULL);
}

char 	*get_absolute_path(char *path, char *cmd)
{
	;
}
