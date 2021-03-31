/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 09:12:18 by loamar            #+#    #+#             */
/*   Updated: 2021/03/30 19:17:17 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libshell.h"

static	long long	ft_atoi_exit(const char *str, int i, int *pbm)
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

static	void		exit_error_numeric(t_msh *msh, char *arg, t_list *element)
{
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	global_status = 2;
	free_all(msh, EXIT);
	exit(global_status);
}

static	void		exit_arg(t_msh *msh, char *str, t_list *element)
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
				exit_error_numeric(msh, str, element);
		}
		pos++;
	}
}

int		my_exit(t_msh *msh, t_list *element)
{
	int 	i;
	int			pbm;
	long long	code2;

	i = 1;
	if (element->tab_args[1] != NULL)
	{
		exit_arg(msh, element->tab_args[1], element);
		while (element->tab_args[i])
			i++;
		if (i > 2)
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			global_status = 1;
		}
		else
		{
			code2 = ft_atoi_exit(element->tab_args[1], 0, &pbm);
			if (pbm == 1)
				exit_error_numeric(msh, element->tab_args[1], element);
			global_status = code2 % 256;
		}
	}
	else
	{
		global_status = 0;
		free_all(msh, EXIT);
		exit(global_status);
	}
	return (SUCCESS);
}
