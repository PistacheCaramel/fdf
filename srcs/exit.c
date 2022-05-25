/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:22:07 by ybendavi          #+#    #+#             */
/*   Updated: 2022/05/16 10:22:58 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	gnl_freer(t_gnl *gnl)
{
	if (gnl)
	{
		if (gnl->rst != NULL)
		{
			free(gnl->rst);
			gnl->rst = NULL;
		}
		if (gnl->str != NULL)
		{
			free(gnl->str);
			gnl->str = NULL;
		}
		if (gnl->buffer != NULL)
		{
			free(gnl->buffer);
			gnl->buffer = NULL;
		}
	}
	gnl = NULL;
}

void	points_freer(int **points, int taby)
{
	int	y;

	y = 0;
	if (points)
	{
		while (y < taby)
		{
			free(points[y]);
			y++;
		}
		free(points);
	}
}

void	freer(t_vars *vars)
{
	gnl_freer(&vars->gnl);
	points_freer(vars->points, vars->taby);
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}

void	exits(t_vars *vars, int ex)
{
	freer(vars);
	exit(ex);
}
