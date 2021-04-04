/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:47:40 by tidminta          #+#    #+#             */
/*   Updated: 2021/04/04 03:17:20 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_H
# define BUILT_H

int     	my_echo(t_msh *msh, t_list *element);
int			my_env(t_msh *msh, t_list *element);
int			check_arg(t_msh *msh, char *str);
int         my_exit(t_msh *msh, t_list *element);
int			my_export(t_msh *msh, t_list *element);
int 	    my_pwd(t_msh *msh);
int		 	my_cd(t_msh *msh, t_list *element);
int 	    my_unset(t_msh *msh, t_list *element);
void		print_env(t_msh *msh, t_list *element);
int 		ft_handler_builtins(t_msh *msh, t_list *element, char **env);
char		*check_export_env(t_msh *msh, char *str);
void		print_second_env(char *str);
# endif
