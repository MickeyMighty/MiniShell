/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:54:29 by loamar            #+#    #+#             */
/*   Updated: 2021/04/27 19:08:06 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void			end_loop(t_msh *msh, int free)
{
	g_return(SET, SUCCESS);
	g_error(SET, SUCCESS);
	g_error_msg(SET, SUCCESS);
	free_all(msh, free);
	signal(SIGINT, handler_signal);
}

static void			main_handler(t_msh *msh, char *buf, char **env)
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

int					exit_cmd(t_msh *msh)
{
	free_all(msh, EXIT);
	exit(g_status);
}

static void			shell_loop(char **env)
{
	t_msh	*msh;
	char	*buf;
	// int		loop;
	// int		ret;

	// loop = 1;
	// ret = 0;
	g_pid(SET, 0);
	g_loop(SET, LOOP);
	msh = NULL;
	buf = NULL;
	signal(SIGQUIT, handler_signal);
	signal(SIGINT, handler_signal);
	prompt();
	while (get_next_line(0, &buf) > 0)
	{
		handler_termcap(msh, buf);
		g_return(SET, SUCCESS);
		g_error(SET, SUCCESS);
		signal(SIGINT, handler_signal);
		msh = init_msh(msh);
		main_handler(msh, buf, env);
		end_loop(msh, ENDLOOP);
		prompt();
	}
	free_all(msh, CTRLD);
	exit(0);
}

int					main(int argc, char **argv, char **env)
{
	aff_welcome();
	(void)argc;
	(void)argv;
	shell_loop(env);
	return (0);
}
