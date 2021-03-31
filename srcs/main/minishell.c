/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:54:29 by loamar            #+#    #+#             */
/*   Updated: 2021/03/30 22:24:40 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void 		end_loop(t_msh *msh, char *buf, int free)
{
	global_return = SUCCESS;
	global_error = SUCCESS;
	global_error_msg = SUCCESS;
	free_all(msh, free);
}

static void 		main_handler(t_msh *msh, char *buf, char **env)
{
	global_return = SUCCESS;
	if (global_return == SUCCESS && global_loop == LOOP)
		global_return = handler_env(msh, env);
	if (global_return == SUCCESS || global_return == EMPTY_ENV)
		global_return = get_path(msh);
	if (global_return == SUCCESS || global_return == EMPTY_ENV)
		global_return = handler_data(msh, buf);
	if (global_return == SUCCESS || global_return == EMPTY_ENV)
		global_return = handler_list(msh);
	if (global_return == SUCCESS || global_return == EMPTY_ENV)
		global_return = handler_cmd(msh, env);
	global_loop = ENDLOOP;
}

void 				prompt(void)
{
	ft_putstr_fd("\e[0;36m", 1);
	ft_putstr_fd("minishell$ ", 1);
	ft_putstr_fd("\e[0;37m", 1);
}

static void     	shell_loop(t_msh *msh, char **env)
{
	char	*buf;

	global_pid = 1;
	global_loop = LOOP;
	signal(SIGQUIT, handler_signal);
	signal(SIGINT, handler_signal);
	prompt();
    while (get_next_line(0, &buf) > 0)
    {
		global_return = SUCCESS;
		signal(SIGINT, handler_signal);
		msh = init_msh(msh, global_loop);
		main_handler(msh, buf, env);
		end_loop(msh, buf, ENDLOOP);
		prompt();
    }
	if (buf)
		free(buf);
	free_all(msh, CTRLD);
	exit(0);
}

int     main(int argc, char **argv, char **env)
{
	t_msh			*msh;

	aff_welcome();
	(void)argc;
	(void)argv;
	msh = NULL;
    shell_loop(msh, env);
    return (0);
}
