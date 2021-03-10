/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:13:55 by loamar            #+#    #+#             */
/*   Updated: 2021/03/10 12:12:12 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

int 	handler_cmd(t_msh *msh, char **env);
int 	sort_cmd(t_msh *msh, t_list *element, char **env);
int 	exec_cmd(t_msh *msh, t_list *element, char **env);
int 	get_value_sep(char *str);

int 	ft_pipe(t_msh *msh, t_list *element, char **env, int fd);

int     redirection_left(t_msh *msh, t_list *element);
int     redirection_right(t_msh *msh, t_list *element);
int     redirection_double_right(t_msh *msh, t_list *element);
int     create_file(t_msh *msh, t_list *element);
void    redirection(t_msh *msh, t_list *element);

char            *handler_dollar_env(t_msh *msh, char *str);
int      count_dollar_env(char *str);
# endif
