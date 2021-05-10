/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:52:41 by khelen            #+#    #+#             */
/*   Updated: 2020/02/20 16:53:20 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	mod(float i)
{
	return ((i < 0) ? -i : i);
}

float	max1(float a, float b)
{
	return (a > b ? a : b);
}

void	fill_xyz(t_xyz *xyz1, int x, int y, int z)
{
	xyz1->x = x;
	xyz1->y = y;
	if (z == 1)
	{
		xyz1->x1 = x + 1;
		xyz1->y1 = y;
	}
	else
	{
		xyz1->x1 = x;
		xyz1->y1 = y + 1;
	}
}

void	fill(int x, int y, t_xyz *xyz1, t_fdf *data)
{
	if (x < data->width - 1)
	{
		fill_xyz(xyz1, x, y, 1);
		bresenham(xyz1, data);
	}
	if (y < data->height - 1)
	{
		fill_xyz(xyz1, x, y, 0);
		bresenham(xyz1, data);
	}
}
