/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:38:00 by loamar            #+#    #+#             */
/*   Updated: 2021/03/10 12:40:18 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

int      count_dollar_env(char *str)
{
    int     pos;

    pos = 0;
    if (!str)
        return (0);
    while (str[pos])
    {
        if (str[pos] == '$')
            return (1);
        pos++;
    }
    return (0);
}

static int		get_len_dollar(char *str, int pos)
{
    int     len;

    len = 0;
    pos++;
    while (str[pos])
    {
        len++;
        if (str[pos] == ' ' || str[pos] == '#'
        || str[pos] == '$' || str[pos] == '-' || str[pos] == '_'
        || str[pos] == '\'' || str[pos] == '\"')
            return (len);
        pos++;
    }
    return (len);
}

static char     *return_dollar_env(t_msh *msh, char *str, int pos)
{
    t_env_list  *element;
    char        *tmp;
    int         len;

    element = msh->env_lair->start;
    pos++;
    if (str[pos] == '$')
        return ("76533");
    else if (str[pos] == '#')
        return ("0");
    else if (str[pos] == '-' || str[pos] == '_')
        return ("himBH");
    while (element)
    {
        if (ft_strncmp(tmp, element->first_content,
            get_len_dollar(str, pos)) == 0)
            return (element->second_content);
        element = element->next;
    }
    return ("\0");
}

char            *handler_dollar_env(t_msh *msh, char *str)
{
    char    *tmp;
    char    *content;
    int     pos;
    int     pos2;
    int     len;

    pos = 0;
    pos2 = 0;
    content = NULL;
    while (str)
    {
        if (str[pos] == DOLLAR && str[pos] != '\0')
        {
            tmp = ft_strjoin(ft_substr(str, pos2, pos),
            ft_substr(return_dollar_env(msh, str, pos), pos,
            get_len_dollar(str, pos)));
            content = ft_strjoin(content, tmp);
            pos2 = pos;
        }
        pos++;
    }
    return (content);
}
