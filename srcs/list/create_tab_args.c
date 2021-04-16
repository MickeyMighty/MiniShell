/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 23:20:47 by loamar            #+#    #+#             */
/*   Updated: 2021/04/16 12:49:26 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int				clear_list(t_lair_list *lair_list)
{
	int		loop;

	loop = 0;
	while (loop == 0)
	{
		if (pop_back_list(lair_list) == ERROR)
			loop = 1;
	}
	return (SUCCESS);
}

static	int		pop_list(t_msh *msh, int pos)
{
	t_list	*delete_element;
	t_list	*now_element;
	int		i;

	i = 1;
	if (msh->lair_list->size == 0)
		return (-1);
	now_element = msh->lair_list->start;
	while (i < pos)
	{
		now_element = now_element->next;
		i++;
	}
	delete_element = now_element;
	if (now_element->next != NULL)
		now_element->next->previous = now_element->previous;
	else
		msh->lair_list->end = now_element->previous;
	if (now_element->previous != NULL)
		now_element->previous->next = now_element->next;
	free(delete_element->content);
	free(delete_element);
	msh->lair_list->size--;
	return (0);
}

static	int		ft_put_args(t_msh *msh, t_list *cmd)
{
	t_list	*tmp;
	int		pos;

	pos = 0;
	tmp = cmd;
	cmd = cmd->next;
	msh->utils->size_opt_arg = 0;
	while (cmd != NULL && (cmd->token == OPTION || cmd->token == ARGS))
	{
		cmd = cmd->next;
		msh->utils->size_opt_arg++;
	}
	cmd = tmp;
	if (!(cmd->tab_args = malloc(sizeof(char *) *
	(msh->utils->size_opt_arg + 2))))
		return (ERROR);
	while (++pos <= msh->utils->size_opt_arg)
	{
		tmp = tmp->next;
		cmd->tab_args[pos] = ft_strdup(tmp->content);
	}
	cmd->tab_args[0] = NULL;
	cmd->tab_args[msh->utils->size_opt_arg + 1] = NULL;
	return (SUCCESS);
}

static t_list	*get_args_to_pop(t_msh *msh, t_list *cmd, t_list *tmp)
{
	msh->utils->pos_list++;
	while (cmd != NULL && (cmd->token == OPTION || cmd->token == ARGS))
	{
		pop_list(msh, msh->utils->pos_list);
		cmd = tmp;
		cmd = cmd->next;
	}
	if (cmd != NULL && cmd->token == SEPARATOR)
	{
		msh->utils->pos_list++;
		cmd = cmd->next;
	}
	return (cmd);
}

int				create_tab_args(t_msh *msh)
{
	t_list		*cmd;
	t_list		*tmp;
	int			ret;

	msh->utils->pos_list = 1;
	cmd = msh->lair_list->start;
	if (cmd->token == CMD)
	{
		while (cmd != NULL)
		{
			ret = ft_put_args(msh, cmd);
			if (ret == ERROR)
				return (ERROR);
			tmp = cmd;
			cmd = cmd->next;
			if (cmd == NULL)
				break ;
			cmd = get_args_to_pop(msh, cmd, tmp);
		}
	}
	return (SUCCESS);
}
