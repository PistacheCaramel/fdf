/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:31:52 by ybendavi          #+#    #+#             */
/*   Updated: 2022/05/16 10:31:54 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = s;
	while (i < n)
	{
		s1[i] = 0;
		i++;
	}
}

char	*line_set(char *buffer, char *str, t_vars *vars)
{
	char	*ptr;

	free(buffer);
	vars->gnl.buffer = NULL;
	if (ft_strchr(str, '\n') != NULL)
	{
		ptr = str;
		ft_strchr(str, '\n')[0] = 0;
		str = ft_strdup(str, vars);
		free(ptr);
	}
	return (str);
}

char	*saved(char *str, char *rst)
{
	int	i;

	i = 0;
	if (rst != NULL)
	{
		while (rst != NULL && rst[i])
		{
			str[i] = rst[i];
			i++;
		}
	}
	if (rst != NULL)
		free(rst);
	return (str);
}

int	return_conditions(t_vars *vars, int res, char **line)
{
	if (res == -1)
	{
		free(vars->gnl.buffer);
		free(vars->gnl.str);
		vars->gnl.buffer = NULL;
		vars->gnl.str = NULL;
		return (res);
	}
	if (ft_strchr(vars->gnl.str, '\n') != NULL
		&& ft_strchr(vars->gnl.str, '\n')[1] != 0)
		res = 1;
	(*line) = line_set(vars->gnl.buffer, vars->gnl.str, vars);
	if (res == -1 || res == 0)
		return (res);
	else
		return (1);
}

int	get_next_line(int fd, char **line, int buffer_size, t_vars *vars)
{
	char		*str;
	int			res;

	if (line == NULL || fd < 0)
		return (-1);
	res = 3;
	vars->gnl.buffer = ft_calloc(buffer_size + 1, 1);
	if (!(vars->gnl.buffer))
		exits(vars, EXIT_FAILURE);
	vars->gnl.str = ft_calloc(ft_strlen(vars->gnl.rst) + 1, 1);
	if (!(vars->gnl.str))
		exits(vars, EXIT_FAILURE);
	str = saved(vars->gnl.str, vars->gnl.rst);
	vars->gnl.rst = NULL;
	while (res != 0 && res != -1 && ft_strchr(vars->gnl.str, '\n') == NULL)
	{
		res = read(fd, vars->gnl.buffer, buffer_size);
		vars->gnl.str = ft_strjoin_free(vars->gnl.str, vars->gnl.buffer, vars);
		ft_bzero(vars->gnl.buffer, res + 1);
	}
	if (ft_strchr(vars->gnl.str, '\n') != NULL)
		vars->gnl.rst = ft_strdup(&ft_strchr(vars->gnl.str, '\n')[1], vars);
	return (return_conditions(vars, res, line));
}
