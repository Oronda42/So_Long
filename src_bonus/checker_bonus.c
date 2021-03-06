/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:39:39 by oronda            #+#    #+#             */
/*   Updated: 2021/11/18 14:53:49 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	validate_map(t_game *data)
{
	if (!is_enclosed(data))
		return (print_error("map is not enclosed with walls"));
	if (!check_player_nb(data))
		return (print_error("wrong number of player"));
	if (!check_exit_nb(data))
		return (print_error("wrong number of exit"));
	if (!check_collectible_nb(data))
		return (print_error("no collectibles"));
	return (1);
}

int	is_enclosed(t_game *data)
{	
	int	i;

	i = 0;
	while (i < data->map_size.x)
		if (data->tilemap[i++][0].type != WALL)
			return (0);
	i = 0;
	while (i < data->map_size.x)
		if (data->tilemap[i++][data->map_size.y - 1].type != WALL)
			return (0);
	i = 0;
	while (i < data->map_size.y)
		if (data->tilemap[0][i++].type != WALL)
			return (0);
	i = 0;
	while (i < data->map_size.y)
		if (data->tilemap[data->map_size.x - 1][i++].type != WALL)
			return (0);
	return (1);
}

int	check_exit_nb(t_game *data)
{
	int	x;
	int	y;
	int	exitnb;

	exitnb = 0;
	y = 0;
	while (y < data->map_size.y)
	{
		x = 0;
		while (x < data->map_size.x)
		{
			if (data->tilemap[x][y].type == EXIT)
				exitnb++;
			x++;
		}
		y++;
	}
	if (exitnb == 1)
		return (1);
	else
		return (0);
}

int	check_collectible_nb(t_game *data)
{
	int	x;
	int	y;
	int	collectnb;

	collectnb = 0;
	y = 0;
	while (y < data->map_size.y)
	{
		x = 0;
		while (x < data->map_size.x)
		{
			if (data->tilemap[x][y].type == COLLECTIBLE)
				collectnb++;
			x++;
		}
		y++;
	}
	if (collectnb >= 1)
		return (1);
	else
		return (0);
}

int	check_player_nb(t_game *data)
{
	int	x;
	int	y;
	int	playercount;

	playercount = 0;
	y = 0;
	while (y < data->map_size.y)
	{
		x = 0;
		while (x < data->map_size.x)
		{
			if (data->tilemap[x][y].type == PLAYER)
				playercount++;
			x++;
		}
		y++;
	}
	if (playercount == 1)
		return (1);
	else
		return (0);
}
