/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybendavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:35:20 by ybendavi          #+#    #+#             */
/*   Updated: 2022/05/16 10:36:26 by ybendavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_gnldata {
	char	*rst;
	char	*str;
	char	*buffer;
}			t_gnl;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_draw {
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	ix;
	int	iy;
	int	dx;
	int	dy;
	int	dxx;
	int	dyy;
}			t_draw;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	int		**points;
	int		tabx;
	int		taby;
	int		mousex;
	int		mousey;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		minx;
	int		miny;
	int		maxx;
	int		maxy;
	int		zoom;
	int		sizex;
	int		sizey;
	int		diffx;
	int		diffy;
	int		an;
	int		an2;
	int		sym;
	double	rad;
	double	rad2;
	t_gnl	gnl;
	t_data	img;
	t_draw	draw;
}			t_vars;

int		get_next_line(int fd, char **line, int buffer_size, t_vars *vars);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin_free(char *s1, char const *s2, t_vars *vars);
char	*ft_strdup(const char *s, t_vars *vars);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
int		fdf(char **av);
int		parse(char **av, t_vars *vars);
int		render_frame(t_vars *vars);
int		render_frame_sym(t_vars *vars);
int		pixel_drawing(t_vars *vars);
int		scale(t_vars *vars);
void	calculate_point(t_vars *vars, int y, int x);
int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	set_null(t_vars *vars);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	exits(t_vars *vars, int ex);
void	gnl_freer(t_gnl *gnl);
void	order(t_vars *vars);
void	ft_swap(int *a, int *b);
void	conditional_diff(t_vars *vars, int xt, int yt);
void	conditional_diff_sym(t_vars *vars, int xt, int yt);
void	sym_x2(t_vars *vars);
void	sym_x1(t_vars *vars);
void	calc_center_sym(t_vars *vars, int y, int x);
#endif
