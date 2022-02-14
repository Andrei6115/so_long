/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   click_halding.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:04:36 by calecia           #+#    #+#             */
/*   Updated: 2022/02/14 21:31:46 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	free_map(t_maps *map)
// {
// 	(void)map;
// }

int	esc_halding(t_maps *map)
{
	(void)map;
	exit(2);
}

static int	help_ch(t_maps *map, int x, int y)
{
	if (x < 0 || y < 0 || x == map->size_x || y == map->size_y)
		return (0);
	if (map->map[y][x] == '0')
	{
		map->map[y][x] = 'P';
		map->count_move++;
		return (1);
	}
	if (map->map[y][x] == 'C')
	{
		map->map[y][x] = 'P';
		map->count_move++;
		map->count_items--;
		return (1);
	}
	if (map->map[y][x] == 'E' && map->count_items == 0)
	{
		map->count_move++;
		ft_putstr_fd("Ti molodec\n", 1);
		exit (2);
	}
	return (0);
}

int	click_halding(int k, t_game *g)
{
	if (k == 13 && help_ch(g->map, g->map->player_x, g->map->player_y - 1))
	{
		g->map->map[g->map->player_y][g->map->player_x] = '0';
		ft_printf("%d\n", g->map->count_move);
	}
	else if (k == 0 && help_ch(g->map, g->map->player_x - 1, g->map->player_y))
	{
		g->map->map[g->map->player_y][g->map->player_x] = '0';
		ft_printf("%d\n", g->map->count_move);
	}
	else if (k == 1 && help_ch(g->map, g->map->player_x, g->map->player_y + 1))
	{
		g->map->map[g->map->player_y][g->map->player_x] = '0';
		ft_printf("%d\n", g->map->count_move);
	}
	else if (k == 2 && help_ch(g->map, g->map->player_x + 1, g->map->player_y))
	{
		g->map->map[g->map->player_y][g->map->player_x] = '0';
		ft_printf("%d\n", g->map->count_move);
	}
	else if (k == 53)
		esc_halding(g->map);
	search_player(g->map);
	draw_map(*g->map, *g->imgs);
	return (0);
}
