/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:13:55 by loamar            #+#    #+#             */
/*   Updated: 2021/03/25 13:34:30 by loamar           ###   ########.fr       */
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

int 	check_end(char *str, int pos);
int 	check_no_space(t_msh *msh, char *str);
char 	*return_element(t_msh *msh, char *tmp, int key);
char		*return_content(t_msh *msh, char *str);
int 	check_no_space(t_msh *msh, char *str);
t_list			*check_block_cmd(t_msh *msh, t_list *element);
char 	*check_content(t_msh *msh, char *str);
char		*return_all_content(t_msh *msh, char *str);
int 		error_cmd(t_msh *msh, t_list *element);
# endif
