/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:28:13 by ybendavi          #+#    #+#             */
/*   Updated: 2022/05/16 10:28:16 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	diff_count(t_vars *vars, int y)
{
	int	x;

	x = 0;
	while (x < vars->tabx)
	{
		calculate_point(vars, y, x);
		if (vars->x1 > vars->maxx)
			vars->maxx = vars->x1;
		if (vars->y1 > vars->maxy)
			vars->maxy = vars->y1;
		if (vars->x1 < vars->minx)
			vars->minx = vars->x1;
		if (vars->y1 < vars->miny)
			vars->miny = vars->y1;
		x++;
	}
}

void	rescale_condition(t_vars *vars)
{
	if (vars->maxx >= vars->sizex || vars->maxy >= vars->sizey
		|| vars->minx <= 0 || vars->miny <= 0)
	{
		vars->zoom--;
		vars->resc++;
		scale(vars);
	}
	if (vars->maxx - vars->minx <= vars->sizex / 4
		&& vars->maxy - vars->miny <= vars->sizey / 4)
	{
		vars->resc1++;
		vars->zoom++;
		scale(vars);
	}
}

int	scale(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	if (vars->taby == 0 || (vars->taby <= 1 && vars->tabx <= 1))
		return (0);
	calculate_point(vars, y, x);
	vars->minx = vars->x1;
	vars->miny = vars->y1;
	vars->maxy = vars->y1;
	vars->maxx = vars->x1;
	while (y < vars->taby)
	{
		diff_count(vars, y);
		y++;
	}
	if (vars->resc == 0 || vars->resc1 == 0)
		rescale_condition(vars);
	return (0);
}
