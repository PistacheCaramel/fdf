/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:23:37 by ybendavi          #+#    #+#             */
/*   Updated: 2022/05/16 10:23:39 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_init_all(t_vars *vars)
{	
	vars->mlx = mlx_init();
	vars->an = 0;
	vars->an2 = 0;
	vars->resc = 0;
	vars->resc1 = 0;
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

int	close_esc(int keycode, t_vars *vars)
{	
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
	mlx_hook(vars.win, 2, 1L << 0, close_esc, &vars);
	mlx_hook(vars.win, 17, 0L, close_cross, &vars);
	mlx_loop(vars.mlx);
}
/* If you want a representation like in subject,
 * you can add order(&vars); between scale and render_frame.
 * Here it is like the binary exemple*/
