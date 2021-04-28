/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:09:50 by loamar            #+#    #+#             */
/*   Updated: 2021/04/28 12:25:14 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct				s_msh
{
	struct s_utils		*utils;
	struct s_data		*data;
	struct s_term_list	*term_list;
	struct s_term_lair	*term_lair;
	struct s_list		*list;
	struct s_lair_list	*lair_list;
	struct s_env_list	*env_list;
	struct s_env_lair	*env_lair;
}							t_msh;

typedef struct				s_utils
{
	int					pos_echo;
	int					option_n;
	int					size_opt_arg;
	int					check;
	int					pos;
	int					pos_args;
	int					args_pos;
	char				quote;
	int					no_space;
	int					check_arg;
	int					key;
	int					loop;
	int					loop2;
	int					loop3;
	int					backup_fd;
	int					backslash_dollar;
	int					pos_list;
	int					multi_pipe;
	int					pipe;
	int					export_check;
	int					redirection;
	int					i;
	int					fd;
	int					size_tab;
	int					*tab_specase;
	char				**path;
}							t_utils;

typedef struct				s_split_data
{
	int					nb_word;
	int					nb;
	int					pos;
	int					pos_index;
	int					size;
	int					error;
	int					double_semicolon;

}							t_split_data;

typedef struct				s_data
{
	char				**prompt_data;
	int					size_data;
	int					check;
}							t_data;

typedef struct				s_term_list
{
	char					*content;
	struct s_term_list		*next;
	struct s_term_list		*previous;
}							t_term_list;

typedef struct				s_term_lair
{
	t_term_list				*start;
	t_term_list				*end;
	int					size;
}							t_term_lair;

typedef struct				s_list
{
	char				*content;
	char				**tab_args;
	int					token;
	struct s_list		*next;
	struct s_list		*previous;
}							t_list;

typedef struct				s_lair_list
{
	t_list				*start;
	t_list				*end;
	int					size;
}							t_lair_list;

typedef struct				s_env_list
{
	char				*first_content;
	char				*second_content;
	struct s_env_list	*next;
	struct s_env_list	*previous;
}							t_env_list;

typedef struct				s_env_lair
{
	t_env_list			*start;
	t_env_list			*end;
	int					size;
}							t_env_lair;

#endif
