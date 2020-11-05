/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:51:31 by loamar            #+#    #+#             */
/*   Updated: 2020/11/03 11:57:05 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

typedef struct s_trees
{
    int         value;
    struct s_trees *tleft;
    struct s_trees *tright;
    struct s_trees *parent;
}               t_trees;

t_trees    *new_tree(int x);

// permet de joindre deux noeux
t_trees		*join_tree(t_trees *left, t_trees *right, int node);

void 		clean_tree(t_trees *tree);

void 		print_tree_prefix(t_trees *tree);

int 		count_tree_nodes(t_trees *tree);

# endif
