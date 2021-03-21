/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:38:56 by loamar            #+#    #+#             */
/*   Updated: 2021/03/21 16:21:01 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

int 			return_error(t_msh *msh, char *cmd, char *msg);
void		free_tab_args(char **str);
char		**ft_free_tab(char **tab, int j, t_split_data *split_data);
# endif
