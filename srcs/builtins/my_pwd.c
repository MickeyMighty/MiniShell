/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:01:14 by tidminta          #+#    #+#             */
/*   Updated: 2021/01/12 17:58:23 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int			ft_my_pwd(void)
{
	char *pwd;

	if (!(pwd = getcwd(NULL, PATH_MAX)))
		return (ERROR);
	ft_putendl_fd(pwd, 1);
	return (SUCCESS);
}
