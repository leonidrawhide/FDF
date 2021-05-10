/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:51:23 by khelen            #+#    #+#             */
/*   Updated: 2020/02/22 19:02:23 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z, t_fdf *data)
{
	z *= data->z_axis;
	*x = (*x - *y) * cos(data->angle);
	*y = (*x + *y) * sin(data->angle) - z;
}

void	bresenham(t_xyz *xyz1, t_fdf *data)
{
	float	x_step;
	float	y_step;

	xyz1->z = data->z_matrix[(int)xyz1->y][(int)xyz1->x];
	xyz1->z1 = data->z_matrix[(int)xyz1->y1][(int)xyz1->x1];
	zoom(&xyz1, data);
	data->color = (xyz1->z || xyz1->z1) ? data->color1 : 0xffffff;
	if (data->iso == 1)
	{
		isometric(&xyz1->x, &xyz1->y, xyz1->z, data);
		isometric(&xyz1->x1, &xyz1->y1, xyz1->z1, data);
	}
	draw_line(&x_step, &y_step, &xyz1);
	while ((int)(xyz1->x - xyz1->x1) || (int)(xyz1->y - xyz1->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->shift_x + xyz1->x,
				data->shift_y + xyz1->y, data->color);
		xyz1->x += x_step;
		xyz1->y += y_step;
	}
}

void	draw_line(float *x_step, float *y_step, t_xyz **xyz1)
{
	int		max;

	*x_step = (*xyz1)->x1 - (*xyz1)->x;
	*y_step = (*xyz1)->y1 - (*xyz1)->y;
	max = max1(mod(*x_step), mod(*y_step));
	*x_step /= max;
	*y_step /= max;
}

void	draw(t_fdf *data)
{
	int		x;
	int		y;
	t_xyz	*xyz1;

	if (!(xyz1 = (t_xyz*)malloc(sizeof(t_xyz))))
	{
		ft_putstr("Error\n");
		exit(0);
	}
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			fill(x, y, xyz1, data);
			x++;
		}
		y++;
	}
	print_menu(data);
	free(xyz1);
}
