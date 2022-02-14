/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:51:18 by calecia           #+#    #+#             */
/*   Updated: 2022/02/14 21:34:04 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	draw_map(t_maps map, t_img imgs)
{
	map.it_i = -1;
	mlx_put_image_to_window(map.mlx, map.mlx_win, imgs.back, 0, 0);
	while (++map.it_i < map.size_y)
	{
		map.it_j = 0;
		while (map.it_j < map.size_x)
		{
			if (map.map[map.it_i][map.it_j] == '1')
				mlx_put_image_to_window(map.mlx,
					map.mlx_win, imgs.wall, map.it_j * 48, map.it_i * 48);
			else if (map.map[map.it_i][map.it_j] == 'P')
				mlx_put_image_to_window(map.mlx,
					map.mlx_win, imgs.close_e, map.it_j * 48, map.it_i * 48);
			else if (map.map[map.it_i][map.it_j] == 'C')
				mlx_put_image_to_window(map.mlx,
					map.mlx_win, imgs.poop, map.it_j * 48, map.it_i * 48);
			else if (map.map[map.it_i][map.it_j] == 'E')
				mlx_put_image_to_window(map.mlx,
					map.mlx_win, imgs.close_d, map.it_j * 48, map.it_i * 48);
			else if (map.map[map.it_i][map.it_j] == '0')
				mlx_put_image_to_window(map.mlx,
					map.mlx_win, imgs.back, map.it_j * 48, map.it_i * 48);
			map.it_j++;
		}
	}
}

int	start_game(t_maps *map, t_img *imgs)
{
	t_game	game;

	game.map = map;
	game.imgs = imgs;
	draw_map(*map, *imgs);
	mlx_hook(map->mlx_win, ON_DESTROY, 0, esc_halding, map);
	mlx_key_hook(map->mlx_win, click_halding, &game);
	mlx_loop(map->mlx);
	return (1);
}
