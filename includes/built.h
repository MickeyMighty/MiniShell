/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidminta <tidminta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:47:40 by tidminta          #+#    #+#             */
/*   Updated: 2021/03/04 10:35:34 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_H
# define BUILT_H

int			ft_my_export(t_msh *msh, t_list *element);

int			ft_my_env(t_msh *msh, t_list *element);

int			ft_my_pwd(void);

int         ft_my_exit(t_msh *msh, t_list *element);
int 		ft_handler_builtins(t_msh *msh, t_list *element, char **env);
# endif
