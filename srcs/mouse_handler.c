/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:26:39 by ybendavi          #+#    #+#             */
/*   Updated: 2022/05/16 10:26:44 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	conditional_diff(t_vars *vars, int xt, int yt)
{
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
}
