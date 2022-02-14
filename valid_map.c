/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:38:40 by calecia           #+#    #+#             */
/*   Updated: 2022/02/14 19:46:22 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_frame(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((y == 0 || map[y + 1] == NULL) && map[y][x] != '1')
				return (0);
			if ((x == 0 || map[y][x + 1] == '\0') && map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_item(t_maps	*map)
{
	int	x;
	int	y;

	y = 1;
	while (map->map[y + 1])
	{
		x = 1;
		while (map->map[y][x + 1])
		{
			if (map->map[y][x] == 'C')
				map->count_items++;
			else if (map->map[y][x] == 'E')
				map->count_exit++;
			else if (map->map[y][x] == 'P')
				map->count_start++;
			else if (map->map[y][x] != '0' && map->map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	if (map->count_exit < 1 || map->count_items < 1 || map->count_start != 1)
		return (0);
	return (1);
}

int	fill_size_map(t_maps *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			x++;
		}
		if (y == 0)
			map->size_x = x;
		else if (map->size_x != x)
			return (0);
		y++;
	}
	map->size_y = y;
	return (1);
}

int	valid_map(t_maps *map)
{
	if (!fill_size_map(map))
	{
		return (0);
	}
	if (!check_frame(map->map))
	{
		return (0);
	}
	if (!check_item(map))
	{
		return (0);
	}
	map->height = map->size_img * map->size_y;
	map->width = map->size_img * map->size_x;
	map->valid = 1;
	return (1);
}
