/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_built_ins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:59:38 by tidminta          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/01/12 16:43:13 by tidminta         ###   ########.fr       */
=======
/*   Updated: 2021/01/11 23:00:25 by loamar           ###   ########.fr       */
>>>>>>> c8ec11bffb595572481e83de4a1dea6d2e25fbc5
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int		ft_built_in_check(char *s)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = ft_strlen(s);
	while (++i < len)
		s[i] = ft_tolower(s[i]);
	if ((ft_strncmp(s, "echo", len) == 0)
	|| (ft_strncmp(s, "cd", len) == 0)
	|| (ft_strncmp(s, "pwd", len) == 0)
	|| (ft_strncmp(s, "export", len) == 0)
	|| (ft_strncmp(s, "unset", len) == 0)
	|| (ft_strncmp(s, "env", len) == 0)
	|| (ft_strncmp(s, "exit", len) == 0))
		return (SUCCESS);
	else
		return (ERROR);
}

// detect args & options
// exec cmd + args & options
static int				ft_exec_built_in(t_msh *msh, t_list *element, char **env)
{
	char	*content;
	size_t	len;
	int		i;

	content = element->content;
	len = ft_strlen(content);
	i = -1;
	if ((ft_strncmp(content, "pwd", len) == 0))
	{
		ft_putendl_fd(getcwd(NULL, PATH_MAX), 1);
		return (SUCCESS);
	}
	else if (ft_strncmp(content, "env", len) == 0)
		return (ft_my_env(msh->env_lair));
	else if (ft_strncmp(content, "export", len) == 0)
		return (ft_my_export(msh->env_lair));
	return (ERROR);
}

int				ft_handler_built_in(t_msh *msh, t_list *element, char **env)
{
	char *content;

	content = element->content;
	if (ft_built_in_check(content) != SUCCESS)
		return (ERROR);
	//builtin executiuon by ptr_func_tab
	ft_exec_built_in(msh, element, env);
	return (SUCCESS);
}
