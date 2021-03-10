/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backslash_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 09:52:27 by loamar            #+#    #+#             */
/*   Updated: 2021/03/10 12:17:38 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// renvoyer la string en changant le \" par "
#include "../../includes/libshell.h"

static int 	count_backslash(char *str, int qte)
{
	int		count;
	int		pos;

	count = 0;
	pos = 0;
	if (!str)
		return (0);
	while (str[pos])
	{
		if (str[pos] == BACKSLASH && str[pos + 1] == BACKSLASH && qte == YESQTE)
		{
			count++;
			pos++;
		}
		else if (str[pos] == BACKSLASH && qte == NOQTE)
		{
			count++;
			pos++;
		}
		if (str[pos])
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
	(ft_strlen(str) - count_backslash(str, NOQTE) + 1))))
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
	(ft_strlen(str) - count_backslash(str, YESQTE) + 1))))
		return (NULL);
	while (str[pos])
	{
		if (str[pos] == BACKSLASH && str[pos + 1] == '\0')
			handler_error(msh, "syntax error multiligne.");
		if (str[pos] == BACKSLASH && str[pos + 1] != '\0'
		&& str[pos + 1] == '\\')
			pos++;
		tmp[pos2] = str[pos];
		pos++;
		pos2++;
	}
	tmp[pos2] = '\0';
	free(str);
	return (tmp);
}

void 			handler_backslash_list(t_msh *msh)
{
	t_list *element;

	element = msh->lair_list->start;
	while (element)
	{
		if (count_backslash(element->content, NOQTE) != 0 && element->quote != 1
		&& element->quote != 2 && count_dollar_env(element->content) == 0)
			element->content = create_backslash(msh, element->content);
		else if (count_backslash(element->content, NOQTE) != 0 && element->quote != 1
		&& element->quote == 2)
			element->content = create_backslash_quote(msh, element->content);
		if (element->content == NULL)
			handler_error(msh, "Error malloc.");
		element = element->next;
	}
}
