/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 12:11:26 by loamar            #+#    #+#             */
/*   Updated: 2021/01/29 12:21:48 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

void 	ft_pipe_cmd(t_msh *msh, t_list *element)
{
	int 	fd[2];
	int 	pid;

	if (pipe(fd) == -1)
		ft_error(msh);
	if ((pid = fork()) == 0)
	{
		dup2(, 0);

	}
}
