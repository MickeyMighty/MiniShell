/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 04:38:25 by loamar            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/12/11 16:39:27 by loamar           ###   ########.fr       */
=======
/*   Updated: 2020/12/11 17:01:44 by tidminta         ###   ########.fr       */
>>>>>>> 967ca27fc6c5b040c6e76706eee82819cd2f0aa4
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
	if (getcwd(msh->utils->cwd, sizeof(msh->utils->cwd)) != NULL)
		return (1);
	return (handler_error(msh));
}

static int     	shell_prompt(t_msh *msh)
{
	int 	loop;
	int 	ret;
	char	*buf;

	loop = 1;
	ret = 0;
	signal(SIGINT, SIG_IGN);
	// signal(SIGINT, signal_handler);
	if (get_path(msh) == -1)
		return (-1);
    while (loop)
    {
		write(1, "minishell$ ", 11);
		ret = get_next_line(0, &buf);
		// printf("=====READ=======\n");
		// printf("buf -> %s\n", buf);  // A NE PAS SUPPRIMER
		// printf("ret -> %d\n", ret);
		// printf("================\n\n");
		if (ret == -1)
			return (-1);
		if (handler_data(msh, buf) == -1)
			return (-1);
		if (handler_list(msh) == -1)
			return (-1);
		// exec_cmd(msh);
		// else
		// {
		// 	// free_data(msh);
		// 	// free_lair_list(msh);
		// }
    }
	return (1);
}

int     main(int argc, char **argv)
{
	int 			end;
	t_msh			*msh;

	(void)argc;
	(void)argv;
	end = 0;
	msh = NULL;
	msh = init_shell(msh);
    end = shell_prompt(msh);
	if (end == 1)
		exit(EXIT_SUCCESS);
	if (end == -1)
		exit(EXIT_FAILURE);
    return (0);
}
