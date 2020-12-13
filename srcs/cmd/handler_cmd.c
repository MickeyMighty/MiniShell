/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:46:01 by loamar            #+#    #+#             */
/*   Updated: 2020/12/13 04:38:42 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	handler_cmd(t_msh *msh)
{
	get_absolute_path(msh);
	printf("ok\n");
	exit(0);
	// int 	count;
	// char 	*path;
	// t_list 	*element;

	// path = NULL;
	// count = 0;
	// element = msh->lair_list->start;
	// while (count < msh->lair_list->size)
	// {
	// 	if (element->token == CMD)
	// 	{
	// 		path = get_absolute_path(msh);
	// 		break;
	// 	}
	// 	element = element->next;
	// 	count++;
	// }
	// while (msh->list->content != NULL)
	// {
	// 	msh->utils->pid = fork();
	// 	// return (0); // besoin de return errno
	// 	if (pid < 0)
	// 	{
	// 		printf("ok no\n");
	// 		perror("fork");
	// 	}
	// 	else if (pid > 0)
	// 	{
	// 		// printf("pid > 0\n");
	// 		wpid = waitpid(pid, &status, 0);
	// 		while (wpid <= 0)
	// 		wpid = waitpid(pid, &status, 0);
	// 		kill(pid, SIGTERM);
	// 		handler_cmd(msh);
	// 		// printf("-> %s\n", msh->data->prompt_data[0]);
	// 	}
	// }
}
