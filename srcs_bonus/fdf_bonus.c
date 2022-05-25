/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:31:05 by ybendavi          #+#    #+#             */
/*   Updated: 2022/05/16 10:41:57 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	mlx_init_all(t_vars *vars)
{	
	vars->mlx = mlx_init();
	vars->an = 0;
	vars->an2 = 0;
	if (!vars->mlx)
		exits(vars, EXIT_FAILURE);
	mlx_get_screen_size(vars->mlx, &vars->sizex, &vars->sizey);
	vars->win = mlx_new_window(vars->mlx, vars->sizex, vars->sizey, "fdf");
	if (!vars->win)
		exits(vars, EXIT_FAILURE);
	vars->img.img = mlx_new_image(vars->mlx, vars->sizex, vars->sizey);
	if (!vars->img.img)
		exits(vars, EXIT_FAILURE);
	vars->img.addr = mlx_get_data_addr(vars->img.img,
			&(vars->img.bits_per_pixel),
			&(vars->img.line_length), &(vars->img.endian));
}

int	mouse_zoom(int button, int x, int y, t_vars *vars)
{
	if (button == 4 || button == 5 || button == 1)
	{
		if (button == 4)
			vars->zoom++;
		else if (button == 5 && vars->zoom > 0)
			vars->zoom--;
		else if (button == 1)
		{
			vars->mousex = x;
			vars->mousey = y;
		}
		else
			return (0);
		mlx_destroy_image(vars->mlx, vars->img.img);
		vars->img.img = mlx_new_image(vars->mlx, vars->sizex, vars->sizey);
		vars->img.addr = mlx_get_data_addr(vars->img.img,
				&(vars->img.bits_per_pixel),
				&(vars->img.line_length),
				&(vars->img.endian));
		render_frame(vars);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	return (0);
}

int	close_esc(int keycode, t_vars *vars)
{
	if (keycode == 65363 || keycode == 65361
		|| keycode == 120 || keycode == 121)
	{
		if (keycode == 65363)
			vars->an++;
		if (keycode == 65361)
			vars->an--;
		if (keycode == 120)
			vars->sym = 0;
		if (keycode == 121)
			vars->sym = 1;
		mlx_destroy_image(vars->mlx, vars->img.img);
		vars->img.img = mlx_new_image(vars->mlx, vars->sizex, vars->sizey);
		vars->img.addr = mlx_get_data_addr(vars->img.img,
				&(vars->img.bits_per_pixel),
				&(vars->img.line_length),
				&(vars->img.endian));
		render_frame(vars);
		mlx_clear_window(vars->mlx, vars->win);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	if (keycode == 65307)
		exits(vars, EXIT_SUCCESS);
}

int	close_cross(t_vars *vars)
{
	exits(vars, EXIT_SUCCESS);
	return (0);
}

int	fdf(char **av)
{
	t_vars	vars;
	int		x;
	int		y;

	x = 0;
	y = 0;
	set_null(&vars);
	parse(av, &vars);
	mlx_init_all(&vars);
	vars.zoom = 5;
	scale(&vars);
	render_frame(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_hook(vars.win, 4, 1L << 2, mouse_zoom, &vars);
	mlx_hook(vars.win, 2, 1L << 0, close_esc, &vars);
	mlx_hook(vars.win, 17, 0L, close_cross, &vars);
	mlx_loop(vars.mlx);
}
