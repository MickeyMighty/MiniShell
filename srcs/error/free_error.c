/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 11:56:22 by loamar            #+#    #+#             */
/*   Updated: 2020/12/11 06:09:34 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static void		free_split(char **str)
{
	int		index;

	index = 0;
	while (str[index])
	{
		free(str[index]);
		index++;
	}
	free(str);
}

static int		free_list(t_lair_list *lair_list, int pos)
{
  int	i;
  t_list *supp_element;
  t_list *courant;

	i = 1;
  	if (lair_list->size == 0)
    	return -1;
  	if (pos == 1)
  	{ /* suppresion de 1er élément */
    	supp_element = lair_list->start;
    	lair_list->start = lair_list->start->next;
  		if (lair_list->start == NULL)
      		lair_list->end = NULL;
    	else
      		lair_list->start->previous = NULL;
  	}
  	else if(pos == lair_list->size)
  	{ /* suppression du dernier élément */
	  	supp_element = lair_list->end;
      	lair_list->end->previous->next = NULL;
	  	lair_list->end = lair_list->end->previous;
  	}
  	else
  	{ /* suppression ailleurs */
	  	courant = lair_list->start;
	  	if (i < pos)
	  	{
		  	i++;
		  	courant = courant->next;
	  	}
	  	supp_element = courant;
      	courant->previous->next = courant->next;
      	courant->next->previous = courant->previous;
  	}
  	free(supp_element->content);
  	free(supp_element);
  	lair_list->size--;
  	return 0;
}

// static void	free_list(t_msh *msh)
// {
// 	t_list *list;
//
// 	while (msh->list->next)
// 	{
// 		next = msh->list->next;
// 		if (msh->list)
// 			free(msh->list);
// 		msh->list = next;
// 	}
// 	free(msh->list);
// }

void 	free_error(t_msh *msh)
{
	if (msh)
	{
		if (msh->utils)
			free(msh->utils);
		if (msh->data)
		{
			if (msh->data->prompt_data)
				free_split(msh->data->prompt_data);
			free(msh->data);
		}
		if (msh->lair_list)
		{
			while(msh->lair_list->size > 0)
				free_list(msh->lair_list, 1);
			free(msh->lair_list);
		}
		if (msh->list)
			free(msh->list);
		free(msh);
	}
}
