/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 04:42:10 by loamar            #+#    #+#             */
/*   Updated: 2021/03/22 17:46:15 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static 		int 	pop_list(t_msh *msh, int pos)
{
	t_list	*delete_element;
	t_list	*now_element;
	int		i;

	i = 1;
  	if(msh->lair_list->size == 0)
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

static int	ft_put_args(t_msh *msh, t_list *cmd)
{
	t_list 	*tmp;
	int 	pos;

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
	if (!(cmd->tab_args = malloc(sizeof(char *) * (msh->utils->size_opt_arg + 2))))
		return (ERROR);
	while (++pos <= msh->utils->size_opt_arg)
	{
		tmp = tmp->next;
		cmd->tab_args[pos] = ft_strdup(tmp->content);
	}
	cmd->tab_args[0] = NULL;
    cmd->tab_args[msh->utils->size_opt_arg + 1] = NULL;
	return (SUCCESS);
	// return (cmd);
}

static void 	print_list(t_lair_list *lair_list)
{
	int 	test; // pour le printf
	int 	test2; // pour le printf

	test = 1; // pour le printf
	test2 = 0; // pour le printf
	t_list *current;

	current = lair_list->start;
	printf("\n\n| DEBUT | \n");
	while (current != NULL)
	{
		test2 = 1;
		printf("-{%d}[%s]\n", test, current->content);
		if (current->tab_args != NULL)
		{
			while (current->tab_args[test2] != NULL)
			{
				printf("(%d)[%s]\n", test2, current->tab_args[test2]);
				test2++;
			}
		}
		if (current != NULL)
			current = current->next;
		test++; // pour le printf
	}
	printf("size lair_list -> %d\n", lair_list->size);
	printf("first lair_list -> %s\n", lair_list->start->content);
	printf("end  lair_list -> %s\n", lair_list->end->content);
	printf("| FIN |\n\n");
}

static int    create_tab_args(t_msh *msh)
{
	t_list		*cmd;
	t_list		*tmp;
	int 		ret;

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
				break;
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
		}
	}
	return (SUCCESS);
}

// quote " flag qte = 2
// quote ' flag qte = 1

int 	handler_list(t_msh *msh)
{
	int 	count;
	int 	pos;
	int		qte;
	char 	*tmp;

	count = 0;
	msh->lair_list = init_lair_list(msh->lair_list);
	if (msh->lair_list == NULL)
	{
		global_error = ERROR;
		return (ERROR);
	}
	ft_fill_empty_list(msh->lair_list, msh->data->prompt_data[count]);
	while (++count < msh->data->size_data)
		ft_fill_end_list(msh->lair_list, msh->data->prompt_data[count]);
	set_token_list(msh);
	if (create_tab_args(msh) == ERROR)
		return (ERROR);
	print_list(msh->lair_list); // a supp
	return (SUCCESS);
}
