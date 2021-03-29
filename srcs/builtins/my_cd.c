/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:23:10 by loamar            #+#    #+#             */
/*   Updated: 2021/03/29 17:40:24 by loamar           ###   ########.fr       */
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

static int			change_home_directory(t_msh *msh, char *path, int home)
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
		if (home)
			free(path);
		return (1);
	}
	free(pwd);
	return (0);
}

static int			set_directory(t_msh *msh, char *path, int home)
{
	struct stat	st;

	if (change_home_directory(msh, path, home))
		return (SUCCESS);
	ft_putstr_fd("minishell: cd: ", 2);
	ft_putstr_fd(path, 2);
	global_status = 1;
	if (stat(path, &st) == -1)
	{
		ft_putstr_fd(": No such file or directory", 2);
		global_status = 127;
	}
	else if (!(st.st_mode & S_IXUSR))
		ft_putstr_fd(": Permission denied", 2);
	else
		ft_putstr_fd(": Not a directory", 2);
	ft_putchar_fd('\n', 2);
	// if (path)
	// if (path && (home != 0))
	// 	free(path);
	return (SUCCESS);
}

static int			get_cd_path(t_msh *msh, t_list *element)
{
	char *tmp;

	if (ft_strcmp(element->tab_args[1], "-") == 0)
	{
		if ((tmp = get_env(msh, "OLDPWD")))
		{
			set_directory(msh, tmp, 0);
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
	return (set_directory(msh, element->tab_args[1], 0));
}

int					my_cd(t_msh *msh, t_list *element)
{
	char	*home;

	global_status = 0;
	home = NULL;
	if (element->tab_args[1] != NULL && element->tab_args[2] != NULL)
	{
		ft_putstr_fd("minishell: cd: too many arguments\n", 2);
		global_error = ERROR;
		return (ERROR);
	}
	if (!element->tab_args[1]
	|| (ft_strcmp(element->tab_args[1], "~") == 0)
	|| (ft_strcmp(element->tab_args[1], "--") == 0))
	{
		if (!(home = get_env(msh, "HOME")))
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return (ERROR);
		}
		return (set_directory(msh, home, 1));
	}
	element->tab_args[1] = create_home(msh, element->tab_args[1]);
	return (get_cd_path(msh, element));
}
