/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:01:14 by tidminta          #+#    #+#             */
/*   Updated: 2021/04/16 11:10:47 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int			my_pwd(void)
{
	char *pwd;

	if (!(pwd = getcwd(NULL, PATH_MAX)))
		return (SUCCESS);
	ft_putendl_fd(pwd, 1);
	free(pwd);
	pwd = NULL;
	if (msh->utils->pipe == 1)
		free_all(msh, EXIT);
	return (SUCCESS);
}
