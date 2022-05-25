/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symetry_asset_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:34:29 by ybendavi          #+#    #+#             */
/*   Updated: 2022/05/16 10:34:31 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	sym_x1(t_vars *vars)
{
	if (vars->sym == 0)
		vars->y1 *= -1;
	if (vars->sym == 1)
		vars->x1 *= -1;
	calc_center_sym(vars, vars->taby / 2, vars->tabx / 2);
	vars->x1 += vars->diffx;
	vars->y1 += vars->diffy;
}

void	sym_x2(t_vars *vars)
{
	if (vars->sym == 0)
		vars->y2 *= -1;
	if (vars->sym == 1)
		vars->x2 *= -1;
	calc_center_sym(vars, vars->taby / 2, vars->tabx / 2);
	vars->x2 += vars->diffx;
	vars->y2 += vars->diffy;
}

void	conditional_diff_sym(t_vars *vars, int xt, int yt)
{
	if (vars->sym == 0)
		yt *= -1;
	if (vars->sym == 1)
		xt *= -1;
	if (vars->mousex == -1)
	{
		vars->diffx = vars->sizex / 2 - xt;
		vars->diffy = vars->sizey / 2 - yt;
	}
	else
	{
		vars->diffx = vars->mousex - xt;
		vars->diffy = vars->mousey - yt;
	}
	if (vars->sym == 0 && vars->mousey > vars->sizey / 2)
		vars->diffy = vars->diffy - (vars->sizey / 2);
	else if (vars->sym == 0 && vars->mousey < vars->sizey / 2)
		vars->diffy = vars->diffy + vars->sizey / 2;
	else if (vars->sym == 1 && vars->mousex > vars->sizex / 2)
		vars->diffx -= vars->sizex / 2;
	else if (vars->sym == 1 && vars->mousex < vars->sizex / 2)
		vars->diffx += vars->sizex / 2;
}
