/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:12:18 by loamar            #+#    #+#             */
/*   Updated: 2021/04/10 11:45:11 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static	long long	atoi_exit(const char *str, int i, int *pbm)
{
	int			j;
	long		neg;
	long long	sum;

	neg = 1;
	sum = 0;
	j = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			neg *= -1;
	while (str[i] && ((str[i] == ' ') || str[i] == '0'))
		i++;
	while (str[i] >= '0' && str[i] <= '9' && ++j)
	{
		sum = (sum * 10) + (str[i] - 48);
		if (((i == 18 && neg == 1) && (str[i] > '7' && str[i] <= '9'))
			|| ((i == 19 && neg == -1) && (str[i] == '9')))
			*pbm = 1;
		i++;
	}
	while (str[i++])
		j++;
	if ((j > 19 && neg == 1) || (j > 20 && neg == -1))
		*pbm = 1;
	return (sum * neg);
}

static	void		exit_error_numeric(t_msh *msh, char *arg)
{
	return_error(ERROR_CMD, "exit", arg, ": numeric argument required");
	g_status = 2;
	exit_cmd(msh);
}

static	void		exit_arg(t_msh *msh, char *str)
{
	int		pos;

	pos = 0;
	if (str[pos] == '-' || str[pos] == '+')
		pos++;
	while (str[pos])
	{
		if (str[pos] != '\f' && str[pos] != '\t' && str[pos] != '\r'
			&& str[pos] != '\v' && str[pos] != ' ')
		{
			if (str[pos] < 48 || str[pos] > 57)
				exit_error_numeric(msh, str);
		}
		pos++;
	}
}

static	void		exit_numeric(t_msh *msh, t_list *element, int pbm,
int code2)
{
	code2 = atoi_exit(element->tab_args[1], 0, &pbm);
	if (pbm == 1)
		exit_error_numeric(msh, element->tab_args[1]);
	g_status = code2 % 256;
}

int					my_exit(t_msh *msh, t_list *element)
{
	size_t		i;
	int			pbm;
	long long	code2;

	pbm = 0;
	code2 = 0;
	i = 1;
	g_status = 0;
	if (element->tab_args[1] == NULL)
		exit_cmd(msh);
	exit_arg(msh, element->tab_args[1]);
	while (element->tab_args[i])
		i++;
	if (i > 2)
	{
		return_error(ERROR_CMD, "exit", NULL, "too many arguments");
		g_status = 1;
	}
	else
		exit_numeric(msh, element, pbm, code2);
	exit_cmd(msh);
	return (SUCCESS);
}
