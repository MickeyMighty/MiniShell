/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 02:24:43 by loamar            #+#    #+#             */
/*   Updated: 2021/03/10 12:15:52 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

int 	handler_list(t_msh *msh);
int 	ft_fill_empty_list(t_lair_list *lair_list, char *content, int qte, int dollar);
int 	ft_fill_end_list(t_lair_list *lair_list, char *content, int qte, int dollar);
int 					get_quote(char *str);

char	*sep_env(char *str, int prt);

void 			handler_backslash_list(t_msh *msh);
# endif
