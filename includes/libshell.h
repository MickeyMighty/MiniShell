/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:35:59 by loamar            #+#    #+#             */
/*   Updated: 2021/03/22 12:04:31 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSHELL_H
# define LIBSHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <signal.h>
# include <sys/types.h>
# include <dirent.h>

# define TRUE 0
# define FALSE 1
# define PATH_MAX 4096
# define SUCCESS 0
# define ERROR -1
# define ERROR_BUILTINS -2
# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define NOQTE 0
# define YESQTE 1
# define PIPE 1
# define SEMICOLON 2
# define CHEVRONL 3
# define CHEVRONR 4
# define CHEVROND 5
# define AND 6
# define OR 7
# define VARIABLE 8
# define CMD 9
# define OPTION 10
# define ARGS 11
# define REDIR 12
# define BACKSLASH 92
# define SQUOTE 39
# define DQUOTE 34
# define DOLLAR 36
# define SEPARATOR 35

# include "./includes/struct.h"
# include "./includes/error_free.h"
# include "./includes/data.h"
# include "./includes/list.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "./includes/cmd.h"
# include "./includes/built.h"

/*
** Variable Global
*/

pid_t					global_pid;
int						global_error;
int						global_status;
int						global_return;
int						global_sign_info;

/*
** main/handler_signal.c
*/

void 			handler_signal(int sign);

/*
** init/init_shell.c
*/

t_msh 			*init_shell(t_msh *msh);
void 			aff_welcome(void);

int 			data_check(t_msh *msh);
void 			free_all(t_msh *msh, int free);
t_msh 			*init_msh(t_msh *msh);
t_env_lair		*init_env_lair(t_env_lair *env_lair);
void 			free_data(t_msh *msh);
void 			free_lair_list(t_msh *msh);
t_lair_list 	*init_lair_list(t_lair_list *lair_list);
int 			fill_separator_tab(t_msh *msh);
t_lair_list		*clear_list(t_lair_list *lair_list);
t_lair_list 	*pop_back_list(t_lair_list *lair_list);
void			set_token_list(t_msh *msh);


/*
** data/.c
*/

int 			handler_data(t_msh *msh, char *buf);
int 			check_data_separator(t_data *data);
int 			check_prompt(t_data *data);
t_lair_list 	*init_data_lair_list(t_lair_list *lair_list);

char		**ft_free_tab(char **tab, int j, t_split_data *split_data);

char			**ft_split_data(t_msh *msh, char *s, char c);
int				ft_count_separator(char *s, int pos);
int 	ft_check_word(t_msh *msh, t_split_data *split_data, char *str);
void 			ft_count_word(t_msh *msh, char *s, char c, t_split_data *split_data);



/*
** /.c
*/



void 			handler_env(t_msh *msh, char **env);
int 			ft_fill_empty_env(t_env_lair *env_lair, char *first_content,
char *second_content);
int 			ft_fill_end_env(t_env_lair *env_lair, char *first_content,
char *second_content);
t_env_lair		*clear_env(t_env_lair *env_lair);
t_env_lair 		*pop_back_env(t_env_lair *env_lair);


int				ft_handler_built_in(t_msh *msh, t_list *element, char **env);

# endif
