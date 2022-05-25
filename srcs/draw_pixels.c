/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:21:43 by ybendavi          #+#    #+#             */
/*   Updated: 2022/05/16 10:21:45 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	setup(t_vars *vars)
{
	vars->draw.x1 = vars->x1;
	vars->draw.y1 = vars->y1;
	vars->draw.x2 = vars->x2;
	vars->draw.y2 = vars->y2;
	vars->draw.dyy = vars->draw.y2 - vars->draw.y1;
	vars->draw.dxx = vars->draw.x2 - vars->draw.x1;
	if (vars->draw.dyy < 0)
		vars->draw.dyy = vars->draw.dyy * -1;
	if (vars->draw.dxx < 0)
		vars->draw.dxx = vars->draw.dxx * -1;
	if (vars->draw.y1 > vars->draw.y2)
		vars->draw.iy = -1;
	else
		vars->draw.iy = 1;
	if (vars->draw.x1 > vars->draw.x2)
		vars->draw.ix = -1;
	else
		vars->draw.ix = 1;
	return (0);
}

int	bres1(t_vars *vars, int e)
{
	int	i;

	i = 0;
	while (i <= vars->draw.dxx)
	{
		if (vars->draw.x1 <= vars->sizex && vars->draw.y1 <= vars->sizey
			&& vars->draw.x1 >= 0 && vars->draw.y1 >= 0)
			my_mlx_pixel_put(&(vars->img), vars->draw.x1,
				vars->draw.y1, 0x00FFFFFF);
		i++;
		vars->draw.x1 += vars->draw.ix;
		e -= vars->draw.dy;
		if (e < 0)
		{
			vars->draw.y1 += vars->draw.iy;
			e += vars->draw.dx;
		}
	}
	return (0);
}

int	bres2(t_vars *vars, int e)
{
	int	i;

	i = 0;
	while (i <= vars->draw.dyy)
	{
		if (vars->draw.x1 <= vars->sizex
			&& vars->draw.y1 <= vars->sizey
			&& vars->draw.x1 >= 0
			&& vars->draw.y1 >= 0)
			my_mlx_pixel_put(&(vars->img), vars->draw.x1,
				vars->draw.y1, 0x00FFFFFF);
		i++;
		vars->draw.y1 += vars->draw.iy;
		e -= vars->draw.dx;
		if (e < 0)
		{
			vars->draw.x1 += vars->draw.ix;
			e += vars->draw.dy;
		}
	}
	return (0);
}

int	pixel_drawing(t_vars *vars)
{
	int	ex;
	int	ey;

	if (vars->x2 - vars->x1 < 0)
		ex = (vars->x2 - vars->x1) * -1;
	else
		ex = vars->x2 - vars->x1;
	if (vars->y2 - vars->y1 < 0)
		ey = (vars->y2 - vars->y1) * -1;
	else
		ey = vars->y2 - vars->y1;
	vars->draw.dx = 2 * ex;
	vars->draw.dy = 2 * ey;
	setup(vars);
	if (vars->draw.dx >= vars->draw.dy)
		bres1(vars, ex);
	else
		bres2(vars, ey);
	return (0);
}
