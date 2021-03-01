/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 19:54:29 by loamar            #+#    #+#             */
/*   Updated: 2021/03/01 11:03:26 by loamar           ###   ########.fr       */
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


#include "../includes/libshell.h"

static void     	shell_prompt(t_msh *msh, char **env)
{
	int 	loop;
	int 	ret;
	char	*buf;

	loop = 1;
	signal(SIGINT, SIG_IGN);
	// signal(SIGINT, signal_handler);
    while (loop)
    {
		ret = 0;
		ft_putstr_fd("\e[0;36m", 1);
		write(2, "minishell$ ", 11);
		ft_putstr_fd("\e[0;37m", 1);
		ret = get_next_line(0, &buf);
		if (ret == -1)
			handler_error(msh, "Bad read.\n");
		if ((handler_data(msh, buf) == -1) || (handler_list(msh) == -1))
			handler_error(msh, NULL);
		handler_cmd(msh, env);
    }
}

int     main(int argc, char **argv, char **env)
{
	t_msh			*msh;

	(void)argc;
	(void)argv;
	msh = NULL;
	msh = init_shell(msh);
	handler_env(msh, env); // cas d'erreur a gerer;
    shell_prompt(msh, env);
	// if (end == SUCCESS)
	// 	exit(EXIT_SUCCESS);
	// if (end == ERROR)
	// 	exit(EXIT_FAILURE);
    return (0);
}
