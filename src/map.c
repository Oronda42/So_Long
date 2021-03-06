/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:38:54 by oronda            #+#    #+#             */
/*   Updated: 2021/11/22 11:10:23 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_width_and_height(int fd, t_game *data)
{
	int		temp_width;
	int		height;
	int		width;

	width = 0;
	height = 0;
	temp_width = 0;
	if (!calculate(&height, &temp_width, &width, fd))
		return (print_error("map error"));
	data->map_size.x = temp_width;
	data->map_size.y = height;
	close(fd);
	return (1);
}

int	calculate(int *height, int *temp_width, int *width, int fd)
{
	int		r;
	char	buffer[1];

	r = 1;
	while (r)
	{
		r = read(fd, buffer, 1);
		if (r)
		{
			if (*buffer == '\n' || !r)
			{
				(*height)++;
				if (!(*temp_width))
					(*temp_width) = (*width);
				else if ((*temp_width) != (*width))
					return (0);
				(*width) = 0;
			}	
			else
				(*width)++;
		}
	}
	if (*buffer != '\n')
		*height += 1;
	return (1);
}
