/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:05:49 by loamar            #+#    #+#             */
/*   Updated: 2020/11/05 18:17:07 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libshell.h"

t_trees		*new_tree(int x)
{
	t_trees 	*tree = malloc(sizeof(*tree));

	if (tree == NULL)
		exit(EXIT_FAILURE);

	tree->value = x;
	tree->tleft = NULL;
	tree->tright = NULL;
	tree->parent = NULL;

	printf("Création de %d\n", tree->value);
	return (tree);
}

void 		clean_tree(t_trees *tree)
{
	if (tree == NULL)
		return ;

	printf("Suppression de %d\n", tree->value);

	clean_tree(tree->tleft);
	clean_tree(tree->tright);

	free(tree);
}

t_trees 	*join_tree(t_trees *left, t_trees *right, int node)
{
	t_trees *tree = new_tree(node);

	tree->tleft = left;
	tree->tright = right;

	if (left != NULL)
		left->parent = tree;
	if (right != NULL)
		right->parent = tree;
	return (tree);
}

void 	print_tree_prefix(t_trees *tree)
{
	if (tree == NULL)
		return ;
	if (tree->parent != NULL)
		printf("(%d) -> (%d)\n", tree->parent->value, tree->value);
	else
		printf("(%d)\n", tree->value);
	if (tree->tleft != NULL)
		print_tree_prefix(tree->tleft);
	if (tree->tright != NULL)
		print_tree_prefix(tree->tright);
}

int 	count_tree_nodes(t_trees *tree)
{
	if (tree == NULL)
		return (0);
	// le + 1 pour compter la racine
	return (count_tree_nodes(tree->tleft) + count_tree_nodes(tree->tright) + 1);
}
