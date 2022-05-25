/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symetry_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:34:39 by ybendavi          #+#    #+#             */
/*   Updated: 2022/05/16 10:48:28 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	calc_center_sym(t_vars *vars, int y, int x)
{
	int		xt;
	int		yt;
	int		zt;
	int		resx;
	int		resy;

	vars->rad = vars->an * (M_PI / 180);
	zt = vars->points[y][x];
	resx = ((((vars->sizex / 2 - (((vars->tabx * vars->zoom) / 2)))
					+ x * vars->zoom)
				- ((vars->sizey / 2 - (vars->taby * vars->zoom) / 2)
					+ y * vars->zoom)) + vars->sizey / 2);
	resy = ((((vars->sizey / 2 - ((vars->tabx * vars->zoom) / 2))
					+ x * vars->zoom)
				+ ((vars->sizey / 2 - (vars->taby * vars->zoom) / 2)
					+ y * vars->zoom)) / 2) - (zt * vars->zoom);
	xt = cos(vars->rad) * resx + (sin(vars->rad) * -1) * resy;
	yt = sin(vars->rad) * resx + cos(vars->rad) * resy;
	conditional_diff_sym(vars, xt, yt);
}

void	calculate_point_sym(t_vars *vars, int y, int x)
{
	int		xt;
	int		yt;
	int		zt;

	vars->rad = vars->an * (M_PI / 180);
	vars->rad2 = vars->an2 * (M_PI / 180);
	zt = vars->points[y][x];
	vars->x1 = ((((vars->sizex / 2 - (((vars->tabx * vars->zoom) / 2)))
					+ x * vars->zoom)
				- ((vars->sizey / 2 - (vars->taby * vars->zoom) / 2)
					+ y * vars->zoom)) + vars->sizey / 2);
	vars->y1 = ((((vars->sizey / 2 - ((vars->tabx * vars->zoom) / 2))
					+ x * vars->zoom)
				+ ((vars->sizey / 2 - (vars->taby * vars->zoom) / 2)
					+ y * vars->zoom)) / 2) - (zt * vars->zoom);
	xt = cos(vars->rad) * vars->x1 + (sin(vars->rad) * -1) * vars->y1;
	yt = sin(vars->rad) * vars->x1 + cos(vars->rad) * vars->y1;
	vars->x1 = xt;
	vars->y1 = yt;
	sym_x1(vars);
}

void	calculate_point2_sym(t_vars *vars, int y, int x)
{
	int		xt;
	int		yt;
	int		zt;

	vars->rad = vars->an * (M_PI / 180);
	vars->rad2 = vars->an2 * (M_PI / 180);
	zt = vars->points[y][x];
	vars->x2 = ((((vars->sizex / 2 - (((vars->tabx * vars->zoom) / 2)))
					+ x * vars->zoom)
				- ((vars->sizey / 2 - (vars->taby * vars->zoom) / 2)
					+ y * vars->zoom)) + vars->sizey / 2);
	vars->y2 = ((((vars->sizey / 2 - ((vars->tabx * vars->zoom) / 2))
					+ x * vars->zoom)
				+ ((vars->sizey / 2 - (vars->taby * vars->zoom) / 2)
					+ y * vars->zoom)) / 2) - (zt * vars->zoom);
	xt = cos(vars->rad) * vars->x2 + (sin(vars->rad) * -1) * vars->y2;
	yt = sin(vars->rad) * vars->x2 + cos(vars->rad) * vars->y2;
	vars->x2 = xt;
	vars->y2 = yt;
	sym_x2(vars);
}

void	point_connect_sym(t_vars *vars, int y, int x)
{
	if (x < vars->tabx - 1)
	{
		calculate_point2_sym(vars, y, x + 1);
		pixel_drawing(vars);
	}
	if (y < vars->taby - 1)
	{
		calculate_point2_sym(vars, y + 1, x);
		pixel_drawing(vars);
	}
}

int	render_frame_sym(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->taby)
	{
		x = 0;
		while (x < vars->tabx)
		{
			calculate_point_sym(vars, y, x);
			point_connect_sym(vars, y, x);
			if (vars->x1 <= vars->sizex && vars->y1 <= vars->sizey
				&& vars->x1 >= 0 && vars->y1 >= 0)
				my_mlx_pixel_put(&vars->img, vars->x1, vars->y1, 0x00FFFFFF);
			x++;
		}
		y++;
	}
	return (0);
}
