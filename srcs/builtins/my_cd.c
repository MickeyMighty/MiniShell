/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:23:10 by loamar            #+#    #+#             */
/*   Updated: 2021/04/07 12:11:43 by lorenzoamar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static char			*create_home(t_msh *msh, char *path)
{
	char		*tmp;
	char		*tmp2;

	if (!ft_strncmp(path, "~/", 2))
	{
		if ((tmp = get_env(msh, "HOME")))
		{
			tmp2 = ft_substr(path, 1, ft_strlen(path));
			free(path);
			path = ft_strjoin(tmp, tmp2);
			free(tmp2);
			free(tmp);
			return (path);
		}
	}
	return (path);
}

static int			change_home_directory(t_msh *msh, char *path)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!chdir(path))
	{
		if (pwd)
		{
			set_env(msh, "OLDPWD", pwd);
			free(pwd);
		}
		if ((pwd = getcwd(NULL, 0)))
		{
			set_env(msh, "PWD", pwd);
			free(pwd);
		}
		return (1);
	}
	free(pwd);
	return (0);
}

static int			set_directory(t_msh *msh, t_list *element, char *tmp,
int home)
{
	struct stat	st;

	if (change_home_directory(msh, tmp))
		return (SUCCESS);
	g_status = 1;
	if (stat(tmp, &st) == -1)
	{
		return_error(ERROR_ARGS, element->content, tmp,
		": No such file or directory");
		g_status = 127;
	}
	else if (!(st.st_mode & S_IXUSR))
		return_error(ERROR_ARGS, element->content, tmp, ": Permission denied");
	else
		return_error(ERROR_ARGS, element->content, tmp, ": Not a directory");
	if (home)
		free(tmp);
	return (ERROR);
}

static int			get_cd_path(t_msh *msh, t_list *element)
{
	char *tmp;

	if (ft_strcmp(element->tab_args[1], "-") == 0)
	{
		if ((tmp = get_env(msh, "OLDPWD")))
		{
			set_directory(msh, element, tmp, 0);
			free(tmp);
		}
		if ((tmp = get_env(msh, "PWD")))
		{
			ft_putstr_fd(tmp, 1);
			free(tmp);
			ft_putchar_fd('\n', 1);
		}
		return (1);
	}
	return (set_directory(msh, element, element->tab_args[1], 0));
}

int					my_cd(t_msh *msh, t_list *element)
{
	char	*home;

	g_status = 0;
	home = NULL;
	if (element->tab_args[1] != NULL && element->tab_args[2] != NULL)
	{
		return_error(ERROR_CMD, element->content, NULL, "too many arguments");
		return (ERROR);
	}
	if (element->tab_args[1] == NULL || element->tab_args[1][0] == '\0'
	|| (ft_strcmp(element->tab_args[1], "~") == 0)
	|| (ft_strcmp(element->tab_args[1], "--") == 0))
	{
		if (!(home = get_env(msh, "HOME")))
		{
			return_error(ERROR_CMD, element->content, NULL, "HOME not set");
			return (ERROR);
		}
		return (set_directory(msh, element, home, 1));
	}
	element->tab_args[1] = create_home(msh, element->tab_args[1]);
	return (get_cd_path(msh, element));
}
