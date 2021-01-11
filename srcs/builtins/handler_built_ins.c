/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_built_ins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 20:59:38 by tidminta          #+#    #+#             */
/*   Updated: 2021/01/11 21:04:22 by tidminta         ###   ########.fr       */
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
	if ((ft_strncmp(s, "echo", len) == 0) ||
		(ft_strncmp(s, "cd", len) == 0) ||
		(ft_strncmp(s, "pwd", len) == 0) ||
		(ft_strncmp(s, "export", len) == 0) || 
		(ft_strncmp(s, "unset", len) == 0) || 
		(ft_strncmp(s, "env", len) == 0) || 
		(ft_strncmp(s, "exit", len) == 0))
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
		while (env[++i])
		{
			if (ft_strncmp(env[i], "PWD=", 4) == 0)
			{
				env[i] += 4;
				ft_putendl_fd(env[i], 1);
				return (SUCCESS);
			}
		}
	}
	else if (ft_strncmp(content, "env", len) == 0)
	{
		while (env[++i])
			ft_putendl_fd(env[i], 1);
		return (SUCCESS);
	}
	return (ERROR);
}

int				ft_handler_built_in(t_msh *msh, t_list *element, char **env)
{
	char *content;

	content = element->content;
	if (ft_built_in_check(content) != SUCCESS)
		return (ERROR);
	ft_exec_built_in(msh, element, env);
	return (SUCCESS);
}
