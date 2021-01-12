/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_built_ins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2021/01/12 17:43:24 by loamar            #+#    #+#             */
/*   Updated: 2021/01/12 17:43:29 by loamar           ###   ########.fr       */
=======
/*   Created: 2021/01/11 20:59:38 by tidminta          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/01/12 18:00:10 by tidminta         ###   ########.fr       */
=======
/*   Updated: 2021/01/12 17:44:59 by tidminta         ###   ########.fr       */
>>>>>>> d21b0b4226a8ece337be73f36d9e46a2220bb28e
>>>>>>> 4c41625e409899813c5a95bebd1e7071009d2b91
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
		return (ft_my_pwd());
	else if (ft_strncmp(content, "env", len) == 0)
		return (ft_my_env(msh->env_lair));
	else if (ft_strncmp(content, "exit", len) == 0)
		exit (0);
	// else if (ft_strncmp(content, "export", len) == 0)
	// 	return (ft_my_export(msh->env_lair));
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
