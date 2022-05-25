/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_null.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:28:31 by ybendavi          #+#    #+#             */
/*   Updated: 2022/05/16 10:28:33 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_null(t_vars *vars)
{
	vars->mlx = NULL;
	vars->win = NULL;
	vars->points = NULL;
	vars->gnl.rst = NULL;
	vars->gnl.buffer = NULL;
	vars->gnl.str = NULL;
	vars->img.img = NULL;
	vars->mousex = -1;
	vars->mousey = -1;
	vars->sym = -1;
}
