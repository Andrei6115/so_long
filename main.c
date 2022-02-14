/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:15:15 by calecia           #+#    #+#             */
/*   Updated: 2022/02/14 20:54:52 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}	t_vars;

t_maps	null_map(void)
{
	t_maps	map;

	map.count_exit = 0;
	map.count_items = 0;
	map.count_move = 0;
	map.count_start = 0;
	map.height = 0;
	map.size_img = 48;
	map.size_x = 0;
	map.size_y = 0;
	map.valid = 0;
	map.width = 0;
	return (map);
}

int	init_map(t_maps *map, char *path)
{
	*map = null_map();
	map->map = ret_map(path);
	if (!valid_map(map))
	{
		ft_putstr_fd("Map Error\n", 2);
		exit(2);
	}
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, map->width, map->height, "");
	search_player(map);
	return (1);
}

int	init_img(t_maps *map, t_img *imgs)
{
	int	w;
	int	h;

	img_background(map, imgs);
	imgs->close_d = mlx_xpm_file_to_image(map->mlx, "image/Door.xpm", &w, &h);
	imgs->open_d = mlx_xpm_file_to_image(map->mlx, "image/Door.xpm", &w, &h);
	imgs->close_e = mlx_xpm_file_to_image(map->mlx, "image/Close.xpm", &w, &h);
	imgs->open_e_w = mlx_xpm_file_to_image(map->mlx,
			"image/Open_W.xpm", &w, &h);
	imgs->open_e_a = mlx_xpm_file_to_image(map->mlx,
			"image/Open_A.xpm", &w, &h);
	imgs->open_e_s = mlx_xpm_file_to_image(map->mlx,
			"image/Open_S.xpm", &w, &h);
	imgs->open_e_d = mlx_xpm_file_to_image(map->mlx,
			"image/Open_D.xpm", &w, &h);
	imgs->poop = mlx_xpm_file_to_image(map->mlx, "image/Poop.xpm", &w, &h);
	imgs->wall = mlx_xpm_file_to_image(map->mlx, "image/Wall.xpm", &w, &h);
	imgs->back = mlx_xpm_file_to_image(map->mlx, "image/Back.xpm", &w, &h);
	if (!(imgs->wall && imgs->back && imgs->close_d && imgs->close_e
			&& imgs->open_d && imgs->open_e_a && imgs->open_e_d
			&& imgs->open_e_s && imgs->open_e_w && imgs->poop))
	{
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_maps	map;
	t_img	imgs;

	if (argc < 2)
	{
		ft_putstr_fd("ERROR\nNo maps\n", 2);
		exit(1);
	}
	if (argc > 2)
	{
		ft_putstr_fd("ERROR\nOnly one arg\n", 2);
		exit(1);
	}
	init_map(&map, argv[1]);
	init_img(&map, &imgs);
	start_game(&map, &imgs);
	return (1);
}
