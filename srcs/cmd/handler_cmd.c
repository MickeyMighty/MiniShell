/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:46:01 by loamar            #+#    #+#             */
/*   Updated: 2020/12/12 05:12:44 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// int 	handler_cmd(t_msh *msh)
// {
// 	return (1);
// 	// while (msh->list->content != NULL)
// 	// {
// 	// 	msh->utils->pid = fork();
// 	// 	// return (0); // besoin de return errno
// 	// 	if (pid < 0)
// 	// 	{
// 	// 		printf("ok no\n");
// 	// 		perror("fork");
// 	// 	}
// 	// 	else if (pid > 0)
// 	// 	{
// 	// 		// printf("pid > 0\n");
// 	// 		wpid = waitpid(pid, &status, 0);
// 	// 		while (wpid <= 0)
// 	// 		wpid = waitpid(pid, &status, 0);
// 	// 		kill(pid, SIGTERM);
// 	// 		handler_cmd(msh);
// 	// 		// printf("-> %s\n", msh->data->prompt_data[0]);
// 	// 	}
// 	// }
// }
