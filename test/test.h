
#ifndef TEST_H
# define TEST_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <sys/wait.h>
# include <errno.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <fcntl.h>
# include "libft.h"

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

# define EXIT 0
# define EXPORT 0
# define CTRLD 1
# define ENV 1
# define ENDLOOP 2
# define LOOP 3
# define TRUE 0
# define FALSE 1
# define PATH_MAX 4096
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

int				ft_size_quote(t_split_data *split_data, char *str, int index);
char			**ft_word_to_tab(char *str,
				t_split_data *split_data, char **res);
void			ft_count_word(char *s, char c,
				t_split_data *split_data);

/*
** data/handler_data.c
*/

int				get_split_pos(char *str, t_split_data *split_data, int index);
char			**ft_split_data(t_split_data *split_data, char *s, char c);
int				get_value_sep(char *str);
int				handler_data(char *buf);

#endif
