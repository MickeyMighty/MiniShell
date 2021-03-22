/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:01:14 by tidminta          #+#    #+#             */
/*   Updated: 2021/03/22 09:46:47 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int			my_pwd(t_msh *msh)
{
	char *pwd;

	if (!(pwd = getcwd(NULL, PATH_MAX)))
		return (ERROR);
	ft_putendl_fd(pwd, 1);
	free(pwd);
	pwd = NULL;
	return (SUCCESS);
}
