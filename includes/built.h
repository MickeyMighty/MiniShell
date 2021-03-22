/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:47:40 by tidminta          #+#    #+#             */
/*   Updated: 2021/03/22 09:41:45 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_H
# define BUILT_H

int     	my_echo(t_msh *msh, t_list *element);
int			my_env(t_msh *msh, t_list *element);
int         my_exit(t_msh *msh, t_list *element);
int			my_export(t_msh *msh, t_list *element);
int 	    my_pwd(t_msh *msh);
int 		ft_handler_builtins(t_msh *msh, t_list *element, char **env);
# endif
