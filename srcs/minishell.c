/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:26:49 by loamar            #+#    #+#             */
/*   Updated: 2020/11/05 18:58:51 by loamar           ###   ########.fr       */
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


#include "../lib/libshell.h"

int make_tree()
{
	t_trees		*bigtree;

	bigtree = join_tree(join_tree(new_tree(8), new_tree(3), 2), new_tree(4), 6);
	print_tree_prefix(bigtree);
	printf("Nombre de noeuds : %d\n", count_tree_nodes(bigtree));
	clean_tree(bigtree);
	return (1);
}

int     shell_loop()
{
	int 	loop;
	char	*buf;
	char	*user;

	loop = 1;
	signal(SIGINT, signal_handler);
    while (loop)
    {
		write(1, "\n>", 2);
		read(0, buf, 1);
    }
}

int     main(int argc, char **argv)
{
	init_shell();
    shell_loop();
    return (0);
}
