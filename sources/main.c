/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:51:30 by khelen            #+#    #+#             */
/*   Updated: 2020/02/22 19:18:25 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int		is_key(int key)
{
	return (key == 27 || key == 78 || key == 24 || key == 69 ||
	key == 126 || key == 125 || key == 124 || key == 123 ||
	key == 11 || key == 15 || key == 5 || key == 19 || key == 18 ||
	key == 43 || key == 47 || key == 49 || key == 53);
}

void	do_key_a(int key, t_fdf *data)
{
	int		size_x;
	int		size_y;

	size_x = 0;
	size_y = 0;
	if (data->zoom > 2)
		if (key == 27 || key == 78)
			data->zoom -= 2;
	if (key == 24 || key == 69)
		data->zoom += 2;
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 124)
		data->shift_x += 10;
	if (key == 123)
		data->shift_x -= 10;
}

void	do_key_b(int key, t_fdf *data)
{
	if (key == 11)
		data->color1 = 0x87ceff;
	if (key == 15)
		data->color1 = 0xff0000;
	if (key == 5)
		data->color1 = 0x90ee90;
	if (key == 47)
		data->z_axis += 1;
	if (key == 43)
		data->z_axis -= 1;
	if (key == 49)
	{
		if (data->iso == 0)
			data->iso = 1;
		else
			data->iso = 0;
	}
	if (key == 53)
	{
		free(data);
		exit(0);
	}
}

int		deal_key(int key, t_fdf *data)
{
	is_key(key);
	do_key_a(key, data);
	do_key_b(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int		main(int ac, char **av)
{
	t_fdf *data;

	if (ac != 2 || av[1] == NULL)
	{
		ft_putstr("Error\n");
		exit(0);
	}
	legit_check(av[1]);
	if (!(data = (t_fdf*)malloc(sizeof(t_fdf) + 1)))
	{
		ft_putstr("Error\n");
		exit(0);
	}
	read_file(av[1], data);
	default_params(data);
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, (1L << 17), red_butt, data);
	mlx_loop(data->mlx_ptr);
}
