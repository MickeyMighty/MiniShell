/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 05:35:00 by loamar            #+#    #+#             */
/*   Updated: 2020/12/11 04:23:42 by tidminta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static int 	check_if_option(t_msh *msh, int count)
{
	// probleme pour echo
	if (msh->data->prompt_data[count][0] == '-'
	|| (((msh->data->prompt_data[count][0] == '\'')
	|| (msh->data->prompt_data[count][0] == '\"'))
	&& msh->data->prompt_data[count][1] == '-'))
		return (1);
	else
		return (0);
}

// static int 	check_if_argument(t_msh *msh, int count)
// {
// 	if (msh->data->prompt_data[count] ==)
// 	return (1);
// }

static int 	linked_list_data(t_msh *msh)
{
	int 	count;

	count = 0;
	msh->list = NULL;
	msh->lair_list = init_data_lair_list(msh->lair_list);
	ft_fill_empty_list(msh->lair_list, msh->data->prompt_data[count]);
	while (count < msh->data->size_data)
	{
		count++;
		msh->utils->check_opt = 0;
		msh->utils->check_arg = 0;
		// while (check_if_option(msh, count) == 1)
		// {
		// 	count++;
		// 	msh->utils->check_opt = 1;
		// }
		ft_fill_end_list(msh->lair_list, msh->data->prompt_data[count]);
	}
	// printf("\nLIST CHAINEE\n");
	// print_list(msh->lair_list);
	return (1);
}

/*
** commandes?
** echo -n
** pwd
** export
** unset
** env
** exit
*/


static int				separator_check(t_msh *msh, char *s)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = msh->utils->separator_tab;
	while (tmp[i])
	{
		if (!ft_strncmp(s, tmp[i], ft_strlen(s))
			&& ft_strlen(s) == ft_strlen(tmp[i]))
			return (1);
		i++;
	}
	return (0);
}

// static int				option_check(char *s)
// {
// }

/*
** token recognition a finir, bon pour cmd separator et args
** d'autres tests sont a prevoirs, relancer l'op qd on est sur un sep
** implementer/finir option_check(s);
** lors des test 
*/
static int		token_recognition(t_msh *msh, char *s, int indice)
{
	if (indice == 0)
		return (CMD);
	// else if (indice =! 0 && option_check(s))
	// 	return (OPTION);
	else if (indice != 0 && separator_check(msh, s))
		return (SEPARATOR);
	else
	{
		msh->utils->check_arg = 1;
		return (ARGS);
	}
	
}

static int		set_token(t_msh *msh)
{
	t_list	*lst;
	int		i;
	
	lst = msh->lair_list->start;
	i = 0;
	while (lst->content)
	{
		printf("avant token[%s] = %i\n", lst->content, lst->token);
		lst->token = token_recognition(msh, lst->content, i);
		printf("apres token[%s] = %i\n", lst->content, lst->token);
		lst = lst->next;
		i++;
	}
	return (0);
}

int 	handler_list(t_msh *msh)
{
	// printf("debut de chaine -> %s\n", data->prompt_data[0]);
	linked_list_data(msh);
	set_token(msh);
	return (1);
}
