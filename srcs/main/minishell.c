/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:54:29 by loamar            #+#    #+#             */
/*   Updated: 2021/03/21 17:18:33 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
   Votre shell doit :
   • Afficher un prompt en l’attente d’une nouvelle commande
   • Chercher et lancer le bon executable (basé sur une variable d’environnement PATH
   ou en utilisant un path absolu), comme dans bash
   • Vous devez implémenter les builtins suivants :
   ◦ echo et l’option ’-n’
   ◦ cd uniquement avec un chemin absolu ou relatif
   ◦ pwd sans aucune option
   ◦ export sans aucune option
   ◦ unset sans aucune option
   ◦ env sans aucune option ni argument
   [DONE ?]◦ exit sans aucune option
	AUTORISED FUNCTIONS
	malloc, free, write, open, read, close, fork, wait,
	waitpid, wait3, wait4, signal, kill, exit, getcwd,
	chdir, stat, lstat, fstat, execve, dup, dup2, pipe,
	opendir, readdir, closedir, strerror, errno
   • ; dans la ligne de commande doit séparer les commandes
   • ’ et " doivent marcher comme dans bash, à l’exception du multiligne.
   • Les redirections <, > et “>>” doivent marcher comme dans bash, à l’exception des
   aggrégations de fd
   • Pipes | doivent marcher comme dans bash
   • Les variables d’environnement ($ suivi de caractères) doivent marcher comme dans
   bash.
   • $? doit marcher comme dans bash
   • ctrl-C, ctrl-D et ctrl-\ doivent afficher le même résultat que dans bash.
   */


#include "../../includes/libshell.h"

static void 		end_loop(t_msh *msh, char *buf, int free)
{
	// if (buf)
	// 	free(buf);
	free_all(msh, FALSE);
	ft_putstr_fd("\n", 1);
}

static void 		main_handler(t_msh *msh, char *buf, char **env)
{
	global_return = SUCCESS;
	if (global_return == SUCCESS)
		handler_env(msh, env); // cas d'erreur a gerer;
	if (global_return == SUCCESS)
		handler_data(msh, buf);
	if (global_return == SUCCESS)
	{
		if (handler_list(msh) == ERROR)
		{
			global_return = ERROR;
			return_error(msh, NULL, "Error malloc.");
		}
	}
	if (global_return == SUCCESS)
		handler_cmd(msh, env);
}

static void 		prompt(void)
{
	ft_putstr_fd("\e[0;36m", 1);
	write(2, "minishell$ ", 11);
	ft_putstr_fd("\e[0;37m", 1);
}

static void     	shell_loop(t_msh *msh, char **env)
{
	char	*buf;

	// signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, handler_signal);
	signal(SIGINT, handler_signal);
    while (get_next_line(0, &buf) > 0)
    {
		global_return = SUCCESS;
		signal(SIGINT, handler_signal);
		msh = init_msh(msh);
		prompt();
		main_handler(msh, buf, env);
		end_loop(msh, buf, FALSE);
    }
	if (buf)
		free(buf);
	// ft_exit
}

int     main(int argc, char **argv, char **env)
{
	t_msh			*msh;

	aff_welcome();
	// msh = init_msh(msh);
	(void)argc;
	(void)argv;
	msh = NULL;
    shell_loop(msh, env);
    return (0);
}
