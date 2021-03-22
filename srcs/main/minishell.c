/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:54:29 by loamar            #+#    #+#             */
/*   Updated: 2021/03/22 17:59:41 by loamar           ###   ########.fr       */
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
	printf("end loop\n");
	free_all(msh, FALSE);
	ft_putstr_fd("\n", 1);
	printf("end loop\n");
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
	printf("fin handler\n");
}

static void 		prompt(void)
{
	ft_putstr_fd("\e[0;36m", 1);
	ft_putstr_fd("minishell$ ", 1);
	ft_putstr_fd("\e[0;37m", 1);
}

static void     	shell_loop(t_msh *msh, char **env)
{
	char	*buf;

	// signal(SIGINT, SIG_IGN);
	printf("2\n");
	signal(SIGQUIT, handler_signal);
	signal(SIGINT, handler_signal);
	printf("3\n");
	prompt();
    while (get_next_line(0, &buf) > 0)
    {
		printf("4\n");
		global_return = SUCCESS;
		msh = init_msh(msh);
		prompt();
		signal(SIGINT, handler_signal);
		main_handler(msh, buf, env);
		end_loop(msh, buf, FALSE);
		prompt();
		printf("5\n");
    }
	if (buf)
		free(buf);
	// ft_exit()
	exit(0);
}

int     main(int argc, char **argv, char **env)
{
	t_msh			*msh;

	aff_welcome();
	// if (!(msh = (t_msh*)malloc(sizeof(t_msh))))
	// 	exit(EXIT_FAILURE);
	global_pid = 0;
	(void)argc;
	(void)argv;
	msh = NULL;
	printf("1\n");
    shell_loop(msh, env);
    return (0);
}
