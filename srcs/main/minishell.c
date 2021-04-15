/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:54:29 by loamar            #+#    #+#             */
/*   Updated: 2021/04/15 11:00:26 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void			end_loop(t_msh *msh, int free)
{
	g_return = SUCCESS;
	g_error = SUCCESS;
	g_error_msg = SUCCESS;
	free_all(msh, free);
}

static void			main_handler(t_msh *msh, char *buf, char **env)
{
	g_return = SUCCESS;
	if (g_return == SUCCESS && g_loop == LOOP)
		g_return = handler_env(msh, env);
	if (g_return == SUCCESS || g_return == EMPTY_ENV)
		g_return = get_path(msh);
	if (g_return == SUCCESS || g_return == EMPTY_ENV)
		g_return = handler_data(msh, buf);
	if (g_return == SUCCESS || g_return == EMPTY_ENV)
		g_return = handler_list(msh);
	if (g_return == SUCCESS || g_return == EMPTY_ENV)
		g_return = handler_cmd(msh, env);
	g_loop = ENDLOOP;
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

	g_pid = 1;
	g_loop = LOOP;
	msh = NULL;
	buf = NULL;
	signal(SIGQUIT, handler_signal);
	signal(SIGINT, handler_signal);
	prompt();
	while (get_next_line(0, &buf) > 0)
	{
		g_return = SUCCESS;
		g_error = SUCCESS;
		signal(SIGINT, handler_signal);
		msh = init_msh(msh);
		main_handler(msh, buf, env);
		end_loop(msh, ENDLOOP);
		prompt();
	}
	ft_putstr_fd("exit", 2);
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
