/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 00:02:42 by loamar            #+#    #+#             */
/*   Updated: 2021/02/22 18:23:31 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int 	handler_token(t_msh *msh, t_list *element, int sep, char **env)
{
	if (ret == SEMICOLON)
		exec_cmd(msh, element, env);
	else if (ret == PIPE)
		ft_pipe(msh, element);
	else if (ret == REDIR);
		ft_reddirection(msh, element);
	element = element->next;
}



















// static 	int 	sort_cmd(t_msh *msh, int token, t_list *element)
// static t_list 		*sort_cmd(t_msh *msh, t_list *element)
// {
// 	if (ft_handler_built_in(msh, element, env) != SUCCESS)
// 		exec_cmd(msh, element, env);
// 	element = element->next;
// 	while (element != NULL &&
// 	(element->token == OPTION || element->token == ARGS))
// 		element = element->next;
// 	return (element);
// }
//
// static t_list 		*get_sep(t_msh *msh, t_list *element)
// {
// 	element = element->next;
// 	while (element->next != NULL
// 	&& (element->token == OPTION || element->token == ARGS))
// 		element = element->next;
// 	if (element != NULL)
// 	{
// 		if (element->content == ";")
// 			msh->utils->check_sep = SEMICOLON;
// 		if (element->content == "|")
// 			msh->utils->check_sep = PIPE;
// 		if (element->content == "<")
// 			msh->utils->check_sep = CHEVRONL;
// 		if (element->content == ">")
// 			msh->utils->check_sep = CHEVRONR;
// 		if (element->content == ">>")
// 			msh->utils->check_sep = SEMICOLON;
// 	}
// 	return (element);
// }
//
// static int 		sort_sep(t_msh *msh, t_list *element)
// {
// 	msh->utils->check_sep = 0;
// 	if (element->token == CMD && element->next != NULL)
// 		element = get_sep(msh, elememt);
// 	if (msh->utils->check_sep != 0)
// 	{
// 		if (msh->utils->check_sep == PIPE)
// 			ft_pipe_cmd(msh);
// 		if ()
// 	}
// 	return (ERROR);
// }
//
//
// int 	handler_token(t_msh *msh, t_list *element)
// {
// 	int 	tmp;
//
// 	tmp = 0;
// 	while (element->content != ";")
// 	{
// 		if (token == SEPARATOR)
// 			sort_sep();
// 		if (element->token == CMD)
// 			element = sort_cmd(msh, element);
// 		sort_sep(msh, element);
// 	}
// }



////////////////////////////////////////
// static void 	count_token(t_msh *msh)
// {
	// 	t_list	*element;
	//
	// 	msh->utils->count_sep = 0;
	// 	element = msh->env_lair->start;
	// 	while (element != NULL)
	// 	{
		// 		if (element->token == SEPARATOR)
		// 			msh->utils->count_sep++;
		// 		element = element->next;
		// 	}
		// }
