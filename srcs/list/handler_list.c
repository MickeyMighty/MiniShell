/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 04:42:10 by loamar            #+#    #+#             */
/*   Updated: 2021/01/19 16:24:27 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static 		int 	pop_list(t_msh *msh, int pos)
{
	t_list	*delete_element;
	t_list	*now_element;
	int i;

	i = 1;
  	if(msh->lair_list->size == 0)
    	return -1;
	printf("poet\n");
	if(pos == msh->lair_list->size)
	{ /* suppression du dernier élément */
    	delete_element = msh->lair_list->end;
    	msh->lair_list->end->previous->next = NULL;
    	msh->lair_list->end = msh->lair_list->end->previous;
  	}
	else
	{ /* suppression ailleurs */
		printf("poet 2\n");
    	now_element = msh->lair_list->start;
		while (i < pos)
		{
			printf("poet 3\n");
			now_element = now_element->next;
			i++;
		}
    	delete_element = now_element;
		printf("poet 4\n");
    	now_element->previous->next = now_element->next;
		now_element->next->previous = now_element->previous;
		printf("poet 44\n");
		printf("poet 444\n");
  	}
	printf("poet 5\n");
  	free(delete_element->content);
  	free(delete_element);
  	msh->lair_list->size--;
	printf("poet 6\n");
  	return (0);
}

// static t_list 	*ft_put_args(t_msh *msh, t_list *cmd)
static void 	ft_put_args(t_msh *msh, t_list *cmd)
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
	printf("msh->utils->size_opt_arg = %d\n", msh->utils->size_opt_arg);
	cmd = tmp;
	if (!(cmd->tab_args = malloc(sizeof(char *) * (msh->utils->size_opt_arg + 2))))
		handler_error(msh);
	while (++pos <= msh->utils->size_opt_arg)
	{
		tmp = tmp->next;
		cmd->tab_args[pos] = ft_strdup(tmp->content);
	}
	cmd->tab_args[0] = ft_strdup("/cmd"); // TEST
    cmd->tab_args[msh->utils->size_opt_arg + 1] = NULL;
	// return (cmd);
}

static void    create_tab_args(t_msh *msh)
{
	t_list		*cmd;
	t_list		*tmp;

	msh->utils->pos_list = 1;
	cmd = msh->lair_list->start;
	if (cmd->token == CMD)
	{
		printf("ok\n");
		while (cmd != NULL)
		{
			printf("ok2\n");
			ft_put_args(msh, cmd);
			// cmd = ft_put_args(msh, cmd);
			printf("ok3\n");
			cmd = cmd->next;
			if (cmd == NULL)
				break;
			msh->utils->pos_list++;
			while (cmd != NULL && (cmd->token == OPTION || cmd->token == ARGS))
			{
				tmp = cmd->next;
				printf("tmp avant pop list -> %s\n", tmp->content);
				printf("cmd avant pop list -> %s\n", cmd->content);
				printf("ok4\n");
				printf("size list = %d\n", msh->lair_list->size);
				pop_list(msh, msh->utils->pos_list);
				msh->utils->pos_list++;
				printf("ntm\n");
				cmd = tmp;
				printf("tmp apres pop list -> %s\n", tmp->content);
				printf("tmp apres pop list -> %s\n", tmp->previous->content);
				printf("cmd apres pop list -> %s\n", cmd->previous->content);
				printf("tab[0] de cmd -> %s\n", cmd->previous->tab_args[0]);
				printf("tab[1] de cmd -> %s\n", cmd->previous->tab_args[1]);
				printf("tab[2] de cmd -> %s\n", cmd->previous->tab_args[2]);
				printf("ok5\n");
				// exit(0);
			}
			if (cmd->token == SEPARATOR)
				cmd = cmd->next;
			printf("ok5\n");
		}
	}
	printf("ok6\n");
}

static void 	print_list(t_lair_list *lair_list)
{
	int 	test; // pour le printf
	int 	test2; // pour le printf

	test = 1; // pour le printf
	test2 = 0; // pour le printf
	t_list *current;

	current = lair_list->start;
	printf("| DEBUT | \n");
	while (current != NULL)
	{
		printf(" -test 0- ");
		printf("%d-> %s\n", test, current->content);
		printf(" -test 0.5- ");
		if (current->tab_args != NULL)
		{
			printf(" -test 1- ");
			while (current->tab_args[test2] != NULL)
			{
				printf("(%d)[%s]\n", test2, current->tab_args[test2]);
				printf(" -test 2- ");
				test2++;
			}
		}
		printf(" -test 3- ");
		if (current->next != NULL)
		{
			printf("\ncurrent = %s\n", current->content);
			printf("\ncurrent->next = %s\n", current->next->content);
			current = current->next;
		}
		printf(" -test 4- ");
		test++; // pour le printf
		printf(" -test 5- ");
	}
	printf("| FIN |\n");
	printf("size lair_list -> %d\n", lair_list->size);
	printf("first lair_list -> %s\n", lair_list->start->content);
	printf("end  lair_list -> %s\n", lair_list->end->content);
}

static int 	linked_list_data(t_msh *msh)
{
	int 	count;

	count = 0;
	msh->list = NULL;
	msh->lair_list = init_lair_list(msh->lair_list);
	if (msh->lair_list == NULL)
		return (ERROR);
	ft_fill_empty_list(msh->lair_list, msh->data->prompt_data[count]);
	while (count < msh->data->size_data)
	{
		count++;
		ft_fill_end_list(msh->lair_list, msh->data->prompt_data[count]);
	}
	// print_list(msh->lair_list);
	return (SUCCESS);
}

int 	handler_list(t_msh *msh)
{
	int 	ret;

	ret = 0;
	ret = linked_list_data(msh);
	if (ret == ERROR)
		return (ERROR);
	set_token_list(msh);
	print_list(msh->lair_list);
	printf("\n\n========= apres create tab args ===============\n\n");
	create_tab_args(msh);
	print_list(msh->lair_list);
	exit(0);
	// free_data(msh);
	return (SUCCESS);
}
