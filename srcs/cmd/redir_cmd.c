/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 07:42:13 by loamar            #+#    #+#             */
/*   Updated: 2021/03/25 23:35:30 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int     redirection_left(t_msh *msh, t_list *element)
{
    int     ret;

    ret = open(element, R_ONLY);
    return (ret);
}

int     redirection_right(t_msh *msh, t_list *element)
{
    int     ret;

    ret = open(element, O_CREAT |  O_RDWR | O_TRUNC, 0644);
    return (ret);
}

int     redirection_double_right(t_msh *msh, t_list *element)
{
    int     ret;

    ret = open(element, O_CREAT |  O_RDWR | O_APPEND, 0644);
    return (ret);
}

int     create_file(t_msh *msh, t_list *element)
{
    int     ret;

    if (element->next->token == CHEVRONL)
        ret = redirection_left(msh, element);
    else if (element->next->token == CHEVRONR)
        ret = redirection_right(msh, element);
    else if (element->next->token == CHEVROND)
        ret = redirection_double_right(msh, element);
    return (ret);
}

void    redirection(t_msh *msh, t_list *element)
{
    int     fd;
    t_list  *tmp;

    tmp = element;
    if (element->token == CMD)
    {
        element = element->next;
        if (element->token == SEPARATOR && element->next->token == CMD)
            element = element->next->next;
    }
    fd = create_file(msh, element);
}
