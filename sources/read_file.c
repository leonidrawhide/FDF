/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khelen <khelen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:54:02 by khelen            #+#    #+#             */
/*   Updated: 2020/02/22 19:25:31 by khelen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_height_width(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		height;
	int		width;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd, &line))
	{
		if (height == 0)
			width = ft_wdcounter(line, ' ');
		height++;
		free(line);
	}
	if (line != NULL)
		free(line);
	close(fd);
	data->height = height;
	data->width = width;
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_strsplit(line, ' ');
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums[i]);
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	get_height_width(file_name, data);
	if (!(data->z_matrix = (int **)malloc(sizeof(int*) * (data->height + 1))))
		error_and_free(data);
	while (i <= data->height)
		data->z_matrix[i++] = (int*)malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	if (line != NULL)
		free(line);
	close(fd);
	free(data->z_matrix[i]);
	data->z_matrix[i] = NULL;
}
