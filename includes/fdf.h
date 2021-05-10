/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:27:55 by khelen            #+#    #+#             */
/*   Updated: 2020/02/22 19:28:33 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef struct	s_fdf	{
	int			width;
	int			height;
	int			**z_matrix;
	int			zoom;
	int			color;
	int			color1;
	int			shift_x;
	int			shift_y;
	float		angle;
	int			iso;
	int			z_axis;
	int			z1_axis;
	void		*mlx_ptr;
	void		*win_ptr;
	float		*x;
	float		*y;
	float		*x1;
	float		*y1;
	int			*z;
	int			*z1;
}				t_fdf;

typedef struct	s_xyz{
	float		x;
	float		y;
	float		x1;
	float		y1;
	int			z;
	int			z1;
}				t_xyz;

void			print_on_adress(char *s, int x, int y, t_fdf *data);
void			read_file(char *file_name, t_fdf *data);
void			bresenham(t_xyz *xyz1, t_fdf *data);
void			draw(t_fdf *data);
void			print_menu(t_fdf *data);
void			default_params(t_fdf *data);
void			draw_line(float *x_step, float *y_step, t_xyz **xyz1);
void			zoom(t_xyz **xyz1, t_fdf *data);
float			mod(float i);
float			max1(float a, float b);
void			fill_xyz(t_xyz *xyz1, int x, int y, int z);
void			fill(int x, int y, t_xyz *xyz1, t_fdf *data);
int				red_butt(t_fdf *data);
void			legit_check(char *file_name);
void			fill_matrix(int *z_line, char *line);
void			error_and_free(t_fdf *data);
#endif
