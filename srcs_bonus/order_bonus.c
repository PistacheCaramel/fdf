/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:33:24 by ybendavi          #+#    #+#             */
/*   Updated: 2022/05/16 10:33:26 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	order2(t_vars *vars, int i, int *tab, int c)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (tab[j] == c)
			return (0);
		j++;
	}
	return (1);
}

int	replace(int i, int *tab, t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->taby)
	{
		x = 0;
		while (x < vars->tabx)
		{
			if (vars->points[y][x] == tab[i])
				vars->points[y][x] = i;
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		if (tab[i] > tab[j])
		{
			ft_swap(tab + i, tab + j);
			while (j > 1)
			{
				if (tab[j - 1] < tab[j - 2])
				{
					ft_swap(tab + j - 1, tab + j - 2);
				}
				j--;
			}
		}
		i++;
	}
}

void	sort_and_replace(t_vars *vars, int *tab, int s)
{
	int	i;

	ft_sort_int_tab(tab, s);
	i = 0;
	while (i < s)
	{
		replace(i, tab, vars);
		i++;
	}
	free(tab);
}

void	order(t_vars *vars)
{
	int	y;
	int	x;
	int	i;
	int	*tab;

	tab = ft_calloc(vars->tabx * vars->taby + 1, sizeof(int));
	if (!tab)
		exits(vars, EXIT_FAILURE);
	y = 0;
	i = 0;
	while (y < vars->taby)
	{
		x = 0;
		while (x < vars->tabx)
		{
			if (order2(vars, i, tab, vars->points[y][x]) == 1)
			{
				tab[i] = vars->points[y][x];
				i++;
			}
			x++;
		}
		y++;
	}
	sort_and_replace(vars, tab, i);
}
