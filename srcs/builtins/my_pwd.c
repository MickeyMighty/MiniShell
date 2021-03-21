/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:01:14 by tidminta          #+#    #+#             */
/*   Updated: 2021/03/18 12:53:23 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

void			ft_my_pwd(t_msh *msh)
{
	char *pwd;

	if (!(pwd = getcwd(NULL, PATH_MAX)))
		handler_error(msh, NULL);
	ft_putendl_fd(pwd, 1);
	free(pwd);
	pwd = NULL;
}
