/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:26:49 by loamar            #+#    #+#             */
/*   Updated: 2020/12/07 14:28:08 by loamar           ###   ########.fr       */
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

static int     shell_prompt(t_data *data, t_prompt_list *prompt_list, t_lair_list *lair_list)
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
		printf("=====TEST=======\n");
		printf("buf -> %s\n", buf);
		printf("ret -> %d\n", ret);
		printf("================\n\n");
		if (ret == -1)
			return (0);
		sort_data(data, buf);
		exit(0);
		// check_prompt(data); // mieux de faire un check a la fin plutot que plein de check a chaque fois
		// handler_data(data, prompt_list, lair_list);
		// if (exec_cmd(data, prompt_list, lair_list) == 0)
			// return (0);
    }
	return (1);
}

int     main(int argc, char **argv)
{
	int 			end;
	t_data			*data;
	t_prompt_list  		*prompt_list;
	t_lair_list  	*lair_list;

	end = 0;
	init_shell();
    end = shell_prompt(data, prompt_list, lair_list);
	if (end == 1)
		exit(EXIT_SUCCESS);
	if (end == 0)
		exit(EXIT_FAILURE);
    return (0);
}
