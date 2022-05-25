/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:27:41 by ybendavi          #+#    #+#             */
/*   Updated: 2022/05/16 10:38:17 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	count2(char *line, t_vars *vars)
{
	int	i;

	i = 0;
	vars->tabx = 0;
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			vars->tabx++;
			while (line[i] && line[i] != ' ')
				i++;
		}
		else
			i++;
	}
	return (i);
}

int	count(char **av, t_vars *vars)
{
	int		fd;
	char	*line;
	int		i;
	int		buffer;

	fd = open(av[0], O_RDONLY);
	if (fd < 0)
		exits(vars, EXIT_FAILURE);
	vars->taby = 0;
	buffer = 10;
	while (get_next_line(fd, &line, buffer, vars) > 0)
	{
		buffer = count2(line, vars);
		free(line);
		vars->taby++;
	}
	close(fd);
	gnl_freer(&vars->gnl);
	return (0);
}

int	check_splitted(char **splitted, t_vars *vars, int y)
{
	int	i;

	i = 0;
	if (splitted[y][i] == '-')
		i++;
	while (splitted[y][i] && splitted[y][i] != ',' && splitted[y][i] >= '0'
		&&splitted[y][i] <= '9')
		i++;
	if (i > 11 || (splitted[y][i] != ',' && splitted[y][i] != 0))
	{
		free_split(splitted);
		exits(vars, EXIT_FAILURE);
		return (1);
	}
	return (0);
}

void	splitter(int y, char *line, t_vars *vars, int y2)
{
	int		i;
	int		x;
	char	**splitted;

	splitted = ft_split(line, ' ');
	vars->points[y2] = ft_calloc(vars->tabx + 2, sizeof(int));
	i = 0;
	if (vars->points[y2] == NULL)
	{
		free_split(splitted);
		exits(vars, EXIT_FAILURE);
	}
	x = vars->tabx - 1;
	while (splitted[i])
	{
		check_splitted(splitted, vars, i);
		vars->points[y2][x] = (ft_atoi(splitted[i]));
		i++;
		x--;
	}
	free_split(splitted);
}

int	parse(char **av, t_vars *vars)
{
	int		fd;
	char	*line;
	int		y;
	int		y2;

	count(av, vars);
	if (vars->taby == 0 || vars->tabx == 0)
		return (0);
	vars->points = ft_calloc(vars->taby + 1, sizeof(int *));
	if (!vars->points)
		exits(vars, EXIT_FAILURE);
	fd = open(av[0], O_RDONLY);
	if (fd < 0)
		exits(vars, EXIT_FAILURE);
	y = 0;
	y2 = vars->taby - 1;
	while (get_next_line(fd, &line, vars->tabx, vars))
	{
		splitter(y, line, vars, y2);
		free(line);
		y2--;
		y++;
	}
	return (0);
}
