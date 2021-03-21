/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_dollar_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:38:00 by loamar            #+#    #+#             */
/*   Updated: 2021/03/17 00:53:15 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

// int      count_dollar_env(char *str)
// {
//     int     pos;
//
//     pos = 0;
//     if (!str)
//         return (0);
//     while (str[pos])
//     {
//         if (str[pos] == '$')
//             return (1);
//         pos++;
//     }
//     return (0);
// }
// //////////////////////////////////////////////
// static char     *return_dollar_value(t_msh *msh, char *str)
// {
//     t_env_list  *element;
//     int         len;
//
//     element = msh->env_lair->start;
//     // str = dollar_special_case(content, pos)
//     // if (tmp != NULL)
//     //     return (dollar_special_case(content, pos));
//     while (element)
//     {
//         if (ft_strcmp(str, element->first_content) == 0)
//         {
//             free(str);
//             return (element->second_content);
//         }
//         element = element->next;
//     }
//     if (str)
//         free(str);
//     return (ft_strdup("\0"));
// }
//
// static	char	*check_dollar_tab(t_msh *msh, char *content)
// {
//     char    *tmp;
//     int		pos;
//
//     pos = 0;
//     while (content[pos])
//     {
//         if (content[pos])
//         if (content[pos + 1] && content[pos] == '$')
//         {
//             msh->utils->check = 1;
//             msh->utils->pos2 = pos;
//             while (content[pos] && (content[pos + 1] != ' '
//             || content[pos + 1] != '\'' || content[pos + 1] != '\"'
//             || content[pos + 1] != '\\'))
//                 pos++;
//             tmp = ft_substr(content, msh->utils->pos2 + 1, pos);
//             tmp = return_dollar_value(msh, tmp);
//             msh->utils->tmp_utils = ft_substr(content, msh->utils->pos3, msh->utils->pos2);
//             tmp = ft_strjoin(msh->utils->tmp_utils, tmp);
//             free(msh->utils->tmp_utils);
//         }
//         if (content[pos] != '\0')
//             pos++;
//         msh->utils->pos3++;
//     }
//     if (msh->utils->check == 0)
//         return (content);
//     free(content);
//     return (tmp);
// }
//
// static	char	*check_dollar_cmd(t_msh *msh, char *content)
// {
//     char    *tmp;
//     int     pos;
//
// 	pos = 0;
// 	while (content[pos])
// 	{
//         if (content[pos + 1] && content[pos] == '$')
//         {
//             msh->utils->check = 1;
//             msh->utils->pos2 = pos;
//             while (content[pos] && (content[pos + 1] != ' '
//             || content[pos + 1] != '\'' || content[pos + 1] != '\"'
//             || content[pos + 1] != '\\'))
//                 pos++;
//             tmp = ft_substr(content, msh->utils->pos2 + 1, pos);
//             tmp = return_dollar_value(msh, tmp);
//             msh->utils->tmp_utils = ft_substr(content, msh->utils->pos3, msh->utils->pos2);
//             tmp = ft_strjoin(msh->utils->tmp_utils, tmp);
//             free(msh->utils->tmp_utils);
//         }
//         if (content[pos] != '\0')
//             pos++;
//         msh->utils->pos3++;
// 	}
//     if (msh->utils->check == 0)
//         return (content);
//     free(content);
//     return (tmp);
// }
//
// t_list          *handler_dollar_env(t_msh *msh, t_list *cmd)
// {
//     msh->utils->pos2 = 0;
//     msh->utils->pos3 = 0;
//     msh->utils->check = 0;
//     pos = 1;
// 	if (cmd->content && cmd->quote != 1)
// 		cmd->content = check_dollar_cmd(msh, cmd->content);
//     while (cmd->tab_args[pos])
//     {
//         msh->utils->pos2 = 0;
//         msh->utils->pos3 = 0;
//         msh->utils->check = 0;
//         cmd->tab_args[pos] = check_dollar_tab(msh, cmd->tab_args[pos]);
//         pos++;
//     }
//     return (cmd);
// }
// /////////////////////////////////////////
// #include "../../includes/libshell.h"
//
// int      count_dollar_env(char *str)
// {
//     int     pos;
//
//     pos = 0;
//     if (!str)
//         return (0);
//     while (str[pos])
//     {
//         if (str[pos] == '$')
//             return (1);
//         pos++;
//     }
//     return (0);
// }
//
// static int		get_len_dollar(char *str, int pos)
// {
//     int     len;
//
//     len = 0;
//     pos++;
//     while (str[pos])
//     {
//         len++;
//         if (str[pos] == ' ' || str[pos] == '#'
//         || str[pos] == '$' || str[pos] == '-' || str[pos] == '_'
//         || str[pos] == '\'' || str[pos] == '\"')
//             return (len);
//         pos++;
//     }
//     return (len);
// }
//
// static char     *return_dollar_env(t_msh *msh, char *str, int pos)
// {
//     t_env_list  *element;
//     char        *tmp;
//     int         len;
//
//     element = msh->env_lair->start;
//     pos++;
//     if (str[pos] == '$')
//         return ("76533");
//     else if (str[pos] == '#')
//         return ("0");
//     else if (str[pos] == '-' || str[pos] == '_')
//         return ("himBH");
//     while (element)
//     {
//         if (ft_strncmp(tmp, element->first_content,
//             get_len_dollar(str, pos)) == 0)
//             return (element->second_content);
//         element = element->next;
//     }
//     return ("\0");
// }
//
// char            *handler_dollar_env(t_msh *msh, char *str)
// {
//     char    *tmp;
//     char    *content;
//     int     pos;
//     int     pos2;
//     int     len;
//
//     pos = 0;
//     pos2 = 0;
//     content = NULL;
//     while (str)
//     {
//         if (str[pos] == DOLLAR && str[pos] != '\0')
//         {
//             tmp = ft_strjoin(ft_substr(str, pos2, pos),
//             ft_substr(return_dollar_env(msh, str, pos), pos,
//             get_len_dollar(str, pos)));
//             content = ft_strjoin(content, tmp);
//             pos2 = pos;
//         }
//         pos++;
//     }
//     return (content);
// }
