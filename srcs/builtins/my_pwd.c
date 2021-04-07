/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:01:14 by tidminta          #+#    #+#             */
/*   Updated: 2021/04/07 12:13:06 by lorenzoamar      ###   ########.fr       */
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
	return (SUCCESS);
}
