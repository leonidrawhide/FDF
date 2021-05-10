/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:51:42 by khelen            #+#    #+#             */
/*   Updated: 2020/02/22 19:10:52 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	default_params(t_fdf *data)
{
	data->iso = 1;
	data->color1 = 0x90ee90;
	data->angle = 1;
	data->zoom = 20;
	data->z_axis = 1;
	data->shift_x = 300;
	data->shift_y = 300;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
}

void	zoom(t_xyz **xyz1, t_fdf *data)
{
	(*xyz1)->x *= data->zoom;
	(*xyz1)->y *= data->zoom;
	(*xyz1)->x1 *= data->zoom;
	(*xyz1)->y1 *= data->zoom;
}

int		red_butt(t_fdf *data)
{
	free(data);
	exit(0);
}

void	legit_check(char *file_name)
{
	int		fd;

	fd = open(file_name, O_RDONLY, 0);
	if (fd == -1)
	{
		ft_putstr("Error\n");
		close(fd);
		exit(0);
	}
	else
		close(fd);
}

void	error_and_free(t_fdf *data)
{
	ft_putstr("Error\n");
	free(data);
	exit(0);
}
