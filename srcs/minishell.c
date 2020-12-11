/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:26:49 by loamar            #+#    #+#             */
/*   Updated: 2020/12/11 03:31:40 by loamar           ###   ########.fr       */
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

static int		get_path(t_msh *msh)
{
	// char	cwd[PATH_MAX + 1];
	// if (getcwd(cwd, sizeof(cwd) != NULL))
	// 	printf("Current Working dir : %s\n");
	// else
	// {
	// 	perror("getcwd() error");
	// 	return (0);
	// }
	return (1);
}

static int     	shell_prompt(t_msh *msh)
{
	int 	loop;
	int 	ret;
	char	*buf;
	char	*user;

	loop = 1;
	ret = 0;
	signal(SIGINT, SIG_IGN);
	// signal(SIGINT, signal_handler);
    while (loop)
    {
		write(1, "minishell$ ", 11);
		ret = get_next_line(0, &buf);
		// printf("=====READ=======\n");
		// printf("buf -> %s\n", buf);  // A NE PAS SUPPRIMER
		// printf("ret -> %d\n", ret);
		// printf("================\n\n");
		if (ret == -1)
			return (0);
		if ((handler_data(msh, buf) == -1) || (handler_list(msh) == -1))
			return (-1); // error.c ?
		if (get_path(msh) == -1) || (exec_cmd(msh) == -1))
			return (-1);
    }
	return (1);
}

int     main(int argc, char **argv)
{
	int 			end;
	t_msh			*msh;

	end = 0;
	msh = init_shell(msh);
    end = shell_prompt(msh);
	if (end == 1)
		exit(EXIT_SUCCESS);
	if (end == 0)
		exit(EXIT_FAILURE);
    return (0);
}
