/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:38:56 by loamar            #+#    #+#             */
/*   Updated: 2021/04/04 01:14:43 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

int 			return_error(int type, char *cmd, char *path, char *msg);
void		free_split(char **str);
void		free_tab_args(t_msh *msh, char **str);
char		**ft_free_tab(char **tab, int j, t_split_data *split_data);
void 	free_list(t_msh *msh, int key);
void 	free_data(t_msh *msh);
void 	free_env_lair(t_msh *msh);
# endif
