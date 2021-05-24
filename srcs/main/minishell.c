/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:54:29 by loamar            #+#    #+#             */
/*   Updated: 2021/04/30 12:41:41 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

void			end_loop(t_msh *msh, int free)
{
	g_return(SET, SUCCESS);
	g_error(SET, SUCCESS);
	g_error_msg(SET, SUCCESS);
	free_all(msh, free);
	signal(SIGINT, handler_signal);
}

void			main_handler(t_msh *msh, char *buf, char **env)
{
	g_return(SET, SUCCESS);
	if (g_return(GET, 0) == SUCCESS && g_loop(GET, 0) == LOOP)
		g_return(SET, handler_env(msh, env));
	if (g_return(GET, 0) == SUCCESS || g_return(GET, 0) == EMPTY_ENV)
		g_return(SET, get_path(msh));
	if (g_return(GET, 0) == SUCCESS || g_return(GET, 0) == EMPTY_ENV)
		g_return(SET, handler_data(msh, buf));
	g_loop(SET, ENDLOOP);
	if (g_return(GET, 0) == SUCCESS || g_return(GET, 0) == EMPTY_ENV)
		g_return(SET, handler_list(msh));
	if (g_return(GET, 0) == SUCCESS || g_return(GET, 0) == EMPTY_ENV)
		g_return(SET, handler_cmd(msh, env));
}

static void			choose_shell(char **env)
{
	t_msh	*msh;
	// int		loop;
	// int		ret;

	// loop = 1;
	// ret = 0;
	msh = NULL;
	g_loop(SET, LOOP);
	g_pid(SET, 0);
	signal(SIGQUIT, handler_signal);
	signal(SIGINT, handler_signal);
	printf("yeyo\n");
	if (isatty(0))
	{
		printf("yeyo 1\n");
		// printf("yeyo 1 2\n");
		shell_loop_termcap(msh, env);
	}
	else
	{
		printf("yeyo 2\n");
		prompt();
		shell_loop(msh, env);
	}
}

int					main(int argc, char **argv, char **env)
{
	aff_welcome();
	(void)argc;
	(void)argv;
	choose_shell(env);
	return (0);
}
