/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:30:54 by calecia           #+#    #+#             */
/*   Updated: 2022/02/11 22:53:47 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	img_background(t_maps *map, t_img *img)
{
	int		*mlx_data_addr;
	int		bpp;
	int		size;
	int		end;

	img->back = mlx_new_image(map->mlx, map->width, map->height);
	mlx_data_addr = (int *)mlx_get_data_addr(img->back, &bpp, &size, &end);
	map->it_i = 0;
	while (map->it_i < map->height)
	{
		map->it_j = 0;
		while (map->it_j < map->width)
		{
			mlx_data_addr[map->it_i * map->width + map->it_j] = 0x0D0D0E;
			map->it_j++;
		}
		map->it_i++;
	}
	return (1);
}

int	filling(void)
{
	return (0);
}
