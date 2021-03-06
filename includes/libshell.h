/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:35:59 by loamar            #+#    #+#             */
/*   Updated: 2021/05/01 12:49:28 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSHELL_H
# define LIBSHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <fcntl.h>
# include <curses.h>

/*
** for my_global
*/

# define SET 1
# define GET 0

/*
** for msg error
*/

# define EMPTY_ENV -7
# define ERROR_DBLSEMICOLON -6
# define ERROR_MULTI -5
# define ERROR_MALLOC -4
# define ERROR_SEP -3
# define ERROR_BUILTINS -2
# define ERROR -1
# define SUCCESS 0
# define ERROR_QTE 1
# define ERROR_ARGS 2
# define ERROR_CMD 3
# define ERROR_TOKEN 4
# define ERROR_MSG 5
# define ERROR_ERRNO 6
# define ERROR_EXPORT 7

/*
** for return error
*/

# define EXIT 0
# define EXPORT 0
# define CTRLD 1
# define ENV 1
# define ENDLOOP 2
# define LOOP 3
// # define TRUE 0
// # define FALSE 1
# define PATH_MAX 4096
# define STDIN 0
# define STDOUT 1
# define STDERR 2

/*
** for token and check
*/

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
# define CMD_EMTPY 7

# include "termcap.h"
# include "struct.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"


char		*g_cm(int mode, char *value);
void		delete_char(t_msh *msh);

/*
** Variable Global
*/

int						g_status;

/*
** init/init_shell.c
*/

void			prompt(void);
void			aff_welcome(void);
t_utils			*init_utils(t_utils *utils);

/*
** init/init_struct.c
*/

t_msh			*init_msh(t_msh *msh);
t_history_lair	*init_history_lair(t_history_lair *term_lair);
t_lair_list		*init_lair_list(t_lair_list *lair_list);
t_env_lair		*init_env_lair(t_env_lair *env_lair);


/*
** termcap/create_list_termcap.c
*/

int				ft_fill_empty_history(t_history_lair *history_lair, char *content);
int				ft_fill_start_history(t_history_lair *history_lair, char *content);
int				clear_history(t_history_lair *history_lair);

/*
** termcap/delete_list_termcap.c
*/

int				pop_back_history(t_history_lair *history_lair);

/*
** termcap/handler_termcap.c
*/

int		handler_history(t_msh *msh, char *line);
void	get_cursor_pos(t_msh *msh, int *col, int *rows);
void	init_term(t_msh *msh);

/*
** main/minishell.c
*/

void			end_loop(t_msh *msh, int free);
void			main_handler(t_msh *msh, char *buf, char **env);

/*
** main/handler_signal.c
*/

void			handler_signal(int sign);

/*
** main/shell_loop.c
*/

void 	shell_loop(t_msh *msh, char **env);
void 	shell_loop_termcap(t_msh *msh, char **env);

/*
** main/my_global.c
*/

int				g_pid(int mode, int value);
int				g_loop(int mode, int value);
int				g_error(int mode, int value);
int				g_error_msg(int mode, int value);
int				g_return(int mode, int value);
/*
** main/my_global_two.c
*/

int				g_bytes(int mode, int value);

/*
** list/check_empty.c
*/

void			check_empty(t_msh *msh);

/*
** list/create_list.c
*/

int				clear_list(t_lair_list *lair_list);
int				ft_fill_empty_list(t_lair_list *lair_list, char *content);
int				ft_fill_end_list(t_lair_list *lair_list, char *content);

/*
** list/create_tab_args.c
*/

int				check_handler_list(t_msh *msh);
int				create_tab_args(t_msh *msh);

/*
** list/delete_list.c
*/

int				pop_back_list(t_lair_list *lair_list);
int				pop_choose_list(t_lair_list *lair_list, int pos);

/*
** list/handler_list.c
*/

int				check_pipe_multi(t_msh *msh);
int				check_token_list(t_msh *msh);
int				handler_list(t_msh *msh);

/*
** list/set_token_list.c
*/

void			set_token_list(t_msh *msh);

/*
** error_and_free/error_msg.c
*/

int				return_error(int type, char *cmd, char *arg, char *msg);

/*
** error_and_free/free_error.c
*/

void			free_tab_args(char **str);
void			free_split(char **str);
void			free_list(t_msh *msh, int key);
char			**ft_free_tab(char **tabs, int j, t_split_data *split_data);
int				exit_cmd(t_msh *msh);

/*
** handler_error/handler_error.c
*/

void			free_all(t_msh *msh, int free_key);
int				error_data(t_data *data, int token);

/*
** env/create_list_env.c
*/

int				ft_fill_empty_env(t_env_lair *env_lair, char *first_content,
				char *second_content);
int				ft_fill_end_env(t_env_lair *env_lair, char *first_content,
				char *second_content);
int				pop_back_env(t_env_lair *env_lair);

/*
** env/handler_env.c
*/

int				clear_env(t_env_lair *env_lair);
void			set_env(t_msh *msh, char *first_content, char *second_content);
char			*get_env(t_msh *msh, char *str);
char			*sep_env(char *str, int prt, int type);
int				handler_env(t_msh *msh, char **env);

/*
** env/path_env.c
*/

char			*get_exec_path(t_msh *msh, char *content);
int				get_path(t_msh *msh);

/*
** data/split_data/get_len_split_data.c
*/

int				ft_size_quote(t_split_data *split_data, char *str, int index);
int				get_split_pos(char *str, t_split_data *split_data, int index);
int				ft_get_len_word(t_split_data *split_data, char *str);

/*
** data/split_data/split_data_utils.c
*/

int				check_word(char *s, char c);
t_split_data	*init_split_data(t_split_data *split_data);
int				ft_count_separator(t_split_data *split_data, char *s, int pos);
int				check_word_qte(t_split_data *split_data, char *str);

/*
** data/split_data/split_data.c
*/

char			**ft_word_to_tab(char *str,
				t_split_data *split_data, char **res);
void			ft_count_word(t_msh *msh, char *s, char c,
				t_split_data *split_data);

/*
** data/handler_data.c
*/

char			**ft_split_data(t_msh *msh, char *s, char c);
int				get_value_sep(char *str);
int				handler_data(t_msh *msh, char *buf);

/*
** cmd/check/check_block_cmd.c
*/

int				put_pos_check(t_msh *msh, char *str, int start, int flag);
int				check_no_space(t_msh *msh, char *str);
char			*check_content(t_msh *msh, char *str, int key);
int				data_check(t_msh *msh);
t_list			*check_block_cmd(t_msh *msh, t_list *element);

/*
** cmd/check/check_quoteanddollar.c
*/

int				data_check_qte(t_msh *msh, int count, int pos, int flag);
char			*check_dollar_case(t_msh *msh, char *str);
int				check_backslash(t_msh *msh, char *str);

/*
** cmd/check/fill_second_step.c
*/

char			*get_tmp_value(t_msh *msh, char *str, int len);
char			*fill_step_qte(t_msh *msh, char *str, char *second_step);
char			*fill_second_step_quote(t_msh *msh, char *str,
				char *second_step);
char			*fill_second_step_content(t_msh *msh, char *str,
				char *second_step);

/*
** cmd/check/return_check.c
*/

char			*return_element(t_msh *msh, char *tmp, int key);
char			*return_dollar(t_msh *msh, char *str, int key);
char			*return_quote(t_msh *msh, char *str);
char			*return_all_content(t_msh *msh, char *str, int check);

/*
** cmd/check/special_case_cmd.c
*/

int				check_end(char *str, int pos);
int				return_pos(t_msh *msh, char *str, int pos);
int				*add_empty_dollar(t_msh *msh, int add);
int				check_specase(t_msh *msh, int pos);

/*
** cmd/exec_cmd.c
*/

void			status_child(void);
int				exec_cmd(t_msh *msh, t_list *cmd, char **env, int pipe);

/*
** cmd/handler_cmd.c
*/

int				error_cmd(t_list *element);
int				handler_cmd(t_msh *msh, char **env);

/*
** cmd/handler_exec_cmd.c
*/

int				check_permission(char *cmd);
void			child_process(t_msh *msh, t_list *cmd, char **env,
				char *exec_path);
void			parent_process(void);

/*
** cmd/pipe_cmd.c
*/

t_list			*multi_pipe(t_msh *msh, t_list *element, char **env);
int				ft_pipe(t_msh *msh, t_list *element, char **env, int backup_fd);

/*
** cmd/redir_cmd.c
*/

int				return_redir_error(t_list *element, int fd, int i);
t_list			*redirections(t_msh *msh, t_list *element, char **env);

/*
** cmd/redir_file_cmd.c
*/

int				create_file(t_list *element, int type);

/*
** builtins/export/export_check.c
*/

char			*export_secondcontent(char *str, int start);
char			*check_export_env(t_msh *msh, char *str);
int				check_arg(t_msh *msh, char *str);

/*
** builtins/export/my_export.c
*/

int				add_back(t_msh *msh, t_env_list *element, char *str);
int				check_first_content(char *content, char *str);
int				my_export(t_msh *msh, t_list *element);

/*
** builtins/export/print_export.c
*/

void			push_to_env(t_msh *msh, char *str);
void			print_env(t_msh *msh);

/*
** builtins/ft_handler_builtins.c
*/

int				ft_handler_builtins(t_msh *msh, t_list *element);

/*
** builtins/my_cd.c
*/

int				my_cd(t_msh *msh, t_list *element);

/*
** builtins/my_echo.c
*/

int				my_echo(t_msh *msh, t_list *element);

/*
** builtins/my_env.c
*/

int				my_env(t_msh *msh);

/*
** builtins/my_exit.c
*/

int				my_exit(t_msh *msh, t_list *element);

/*
** builtins/my_pwd.c
*/

int				my_pwd(void);

/*
** builtins/my_unset.c
*/

int				my_unset(t_msh *msh, t_list *element);


#endif
