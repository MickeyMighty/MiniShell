/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslash_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:52:27 by loamar            #+#    #+#             */
/*   Updated: 2021/03/09 23:15:36 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// renvoyer la string en changant le \" par "
#include "../../includes/libshell.h"

static int 	count_backslash(char *str)
{
	int		count;
	int		pos;

	count = 0;
	pos = 0;
	while (str[pos])
	{
		if (str[pos] == BACKSLASH)
		{
			count++;
			pos++;
		}
		pos++;
	}
	return (count);
}

static char		*create_backslash(t_msh *msh, char *str)
{
	char	*tmp;
	int 	pos;
	int 	pos2;

	pos = 0;
	pos2 = 0;
	if (!(tmp = (char*)malloc(sizeof(char) *
	(ft_strlen(str) - count_backslash(str) + 1))))
		return (NULL);
	while (str[pos])
	{
		if (str[pos] == BACKSLASH && str[pos++] == '\0')
			handler_error(msh, "syntax error multiligne.");
		if (str[pos] == BACKSLASH && str[pos++] != '\0')
			pos++;
		tmp[pos2] = str[pos];
		pos2++;
		pos++;
	}
	tmp[pos2] = '\0';
	free(str);
	return (tmp);
}

static char		*create_backslash_quote(t_msh *msh, char *str)
{
	char	*tmp;
	int 	pos;
	int 	pos2;

	pos = 0;
	pos2 = 0;
	if (!(tmp = (char*)malloc(sizeof(char) *
	(ft_strlen(str) - count_backslash(str) + 1))))
		return (NULL);
	while (str[pos])
	{
		if (str[pos] == BACKSLASH && str[pos++] == '\0')
			handler_error(msh, "syntax error multiligne.");
		if (str[pos] == BACKSLASH && str[pos++] != '\0')
			pos++;
		tmp[pos2] = str[pos];
		pos2++;
		pos++;
	}
	tmp[pos2] = '\0';
	free(str);
	return (tmp);
}

static char		*handler_back_slash(t_msh *msh, char *str, int ticket)
{
	if (ticket == NOQTE)
		return (create_backslash(msh, str));
	else if (ticket == YESQTE)
		return (create_backslash_quote(msh, str));
	else
		return (NULL);
}

void 			handler_backslash_list(t_msh *msh)
{
	t_list *element;

	element = msh->lair_list->start;
	while (element)
	{
		if (count_backslash(element->content) != 0 && element->quote != 1
		&& element->quote != 2)
			element->content = handler_backslash(msh, element->content, NOQTE);
		if (count_backslash(element->content) != 0 && element->quote != 1
		&& element->quote == 2)
			element->content = handler_backslash(msh, element->content, YESQTE);
		if (element->content == NULL)
			handler_error(msh, "Error malloc.");
		element = element->next;
	}
}
