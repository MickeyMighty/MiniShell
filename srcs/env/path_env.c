/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:31:47 by loamar            #+#    #+#             */
/*   Updated: 2021/03/29 16:28:45 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static char			*get_dir(char *name_dir, char *cmd)
{
	DIR				*folder;
	struct dirent	*entry;

	folder = opendir(name_dir);
	if (!folder)
		return (0);
	while ((entry = readdir(folder)))
	{
		if (!ft_strcmp(entry->d_name, cmd))
		{
			closedir(folder);
			return (name_dir);
		}
	}
	closedir(folder);
	return (0);
}

char				*get_exec_path(t_msh *msh, char *content)
{
	char	*exec_path;
	char	*tmp;
	int		index;

	index = -1;
	exec_path = NULL;
	if (!content || msh->utils->path == NULL)
		return (NULL);
	while (msh->utils->path[++index] && exec_path == NULL)
		exec_path = get_dir(msh->utils->path[index], content);
	if (exec_path)
	{
		tmp = ft_strjoin(exec_path, "/");
		exec_path = ft_strjoin(tmp, content);
		free(tmp);
	}
	return (exec_path);
}

int					get_path(t_msh *msh)
{
	t_env_list	*element;

	element = msh->env_lair->start;
	while (element != NULL)
	{
		if ((ft_strlen(element->first_content) >= 4)
		&& element->first_content[0] == 'P'
		&& element->first_content[1] == 'A'
		&& element->first_content[2] == 'T'
		&& element->first_content[3] == 'H')
		{
			msh->utils->path = ft_split(element->second_content, ':');
			return (SUCCESS);
		}
		else
			element = element->next;
	}
	msh->utils->path = NULL;
	return (EMPTY_ENV);
	// return (return_error(msh, NULL, "Empty path."));
}
