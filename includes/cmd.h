/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 19:13:55 by loamar            #+#    #+#             */
/*   Updated: 2021/01/11 15:22:30 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

int 	handler_cmd(t_msh *msh, char **env);
int 	exec_cmd(t_msh *msh, t_list *element, char **env);
# endif
