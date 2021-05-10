/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:41:23 by khelen            #+#    #+#             */
/*   Updated: 2020/02/22 17:10:13 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_on_adress(char *s, int x, int y, t_fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, x + 1, y + 1, 0x000000, s);
	mlx_string_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFFAFA, s);
}

void	print_menu(t_fdf *data)
{
	int		i;
	int		n;

	i = -1;
	n = -1;
	while (i++ < 1000)
	{
		while (n++ < 135)
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, n, 0x778899);
		n = -1;
	}
	print_on_adress("FDF", 475, 15, data);
	print_on_adress("by apidgeot", 870, 30, data);
	print_on_adress("and khelen", 880, 50, data);
	print_on_adress("Exit:               ESC", 30, 10, data);
	print_on_adress("Rotation:           arrows", 30, 30, data);
	print_on_adress("Zoom in/out:        +/-", 30, 50, data);
	print_on_adress("Change projection:  SPACE", 30, 70, data);
	print_on_adress("Change color:       B/R/G", 30, 90, data);
	print_on_adress("Change Z-axis:      </>", 30, 110, data);
}
