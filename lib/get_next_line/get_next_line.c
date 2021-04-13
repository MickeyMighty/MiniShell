/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loamar <loamar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 00:37:54 by loamar            #+#    #+#             */
/*   Updated: 2021/04/13 15:05:36 by loamar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_free(char **str, int ret)
{
	free(*str);
	*str = NULL;
	return (ret);
}

static int		ft_check(char **str, char **line)
{
	char	*tmp;
	int		i;

	i = -1;
	while ((*str)[++i])
		if ((*str)[i] == '\n')
		{
			if (i == 0)
			{
				if (!(*line = ft_strdup("")))
					return (-1);
			}
			else if (!(*line = ft_substr(*str, 0, i)))
				return (-1);
			tmp = *str;
			if (!(*str = ft_substr(*str, (i + 1), ft_strlen(*str))))
				return (-1);
			free(tmp);
			return (1);
		}
	return (0);
}

static int		ft_read(int fd, char *buf, char **str, char **line)
{
	int		bytes;
	char	*tmp;

	if ((bytes = (ft_check(str, line))) == -1)
		return (ft_free(str, -1));
	if (bytes)
		return (1);
	if (ft_strcmp(*line, "\0") == 0)
		free(*line);
	while ((bytes = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[bytes] = '\0';
		if (buf[0] == '\0' && ft_strlen(*str))
			continue;
		else if (buf[0] == '\0' && ft_strlen(*str) <= 0)
			return (ft_free(str, 0));
		tmp = *str;
		*str = ft_strjoin(*str, buf);
		free(tmp);
		if ((bytes = ft_check(str, line)) == -1)
			return (ft_free(str, -1));
		if (bytes)
			return (ft_free(str, 1));
	}
	if (bytes == -1 || !(*line = ft_substr(*str, 0, ft_strlen(*str))))
		return (ft_free(str, -1));
	return (ft_free(str, 0));
}

int				get_next_line(int fd, char **line)
{
	static char *str;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (!str)
		if (!(str = ft_calloc(1, sizeof(char))))
			return (-1);
	return (ft_read(fd, buf, &str, line));
}
// static int	ft_next_line(char *buf)
// {
// 	int	i;
//
// 	i = 0;
// 	while (buf[i] != '\n')
// 		i++;
// 	return (i);
// }
//
// char		*ft_line(char *line, char **hold)
// {
// 	char *tmp;
//
// 	if (ft_strchr_gnl(*hold, '\n'))
// 	{
// 		if (!(line = ft_substr_gnl(*hold, 0, ft_next_line(*hold))))
// 			return (NULL);
// 		tmp = *hold;
// 		if (!(*hold = ft_substr_gnl(tmp, ft_next_line(tmp) + 1,
// 		ft_strlen_gnl(tmp))))
// 		{
// 			if (hold)
// 				free(hold);
// 			return (NULL);
// 		}
// 		free(tmp);
// 	}
// 	else
// 	{
// 		if (!(line = ft_strdup_gnl(*hold)))
// 			return (NULL);
// 		free(*hold);
// 		*hold = NULL;
// 	}
// 	return (line);
// }
//
// int			get_next_line(int fd, char **line)
// {
// 	char		buf[BUFFER_SIZE + 1];
// 	int			ret;
// 	static char	*hold = NULL;
// 	char		*tmp;
//
// 	if (fd == -1 || !line || BUFFER_SIZE <= 0)
// 		return (-1);
// 	ret = 0;
// 	while (!(ft_strchr_gnl(hold, '\n')) && (ret =
// 		read(fd, buf, BUFFER_SIZE)) > 0)
// 	{
// 		buf[ret] = '\0';
// 		tmp = hold;
// 		hold = ft_strjoin_gnl(tmp, buf);
// 		free(tmp);
// 	}
// 	if ((ret == -1) || (!(*line = ft_line(*line, &hold))))
// 		return (-1);
// 	if (!(hold))
// 		return (0);
// 	return (1);
// }
