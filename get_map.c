/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calecia <calecia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:39:00 by calecia           #+#    #+#             */
/*   Updated: 2022/02/11 22:43:51 by calecia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_line(char *map)
{
	int		ret;
	int		fd;
	char	*temp;

	ret = 0;
	fd = open(map, O_RDONLY);
	temp = get_next_line(fd);
	while (temp != NULL)
	{
		free(temp);
		ret++;
		temp = get_next_line(fd);
	}
	close(fd);
	return (ret);
}

int	cleaner_arr(char **arr, int count_line)
{
	int	i;

	i = 0;
	while (arr[i] && i < count_line)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	arr = NULL;
	return (i);
}

int	map_from_file(char **map, int fd)
{
	int		i;
	char	*temp;

	temp = get_next_line(fd);
	i = 0;
	while (temp != NULL)
	{
		if (temp[ft_strlen(temp) - 1] == '\n')
		{
			map[i] = malloc(sizeof(char) * ft_strlen(temp));
			if (!map[i])
			{
				cleaner_arr(map, i);
				free(temp);
				return (0);
			}
			ft_strlcpy(map[i], temp, ft_strlen(temp));
			free(temp);
		}
		else
			map[i] = temp;
		i++;
		temp = get_next_line(fd);
	}
	return (i);
}

char	**ret_map(char *file)
{
	char	**ret;
	int		i;
	int		fd;
	int		size;

	i = 0;
	size = count_line(file);
	fd = open(file, O_RDONLY);
	ret = malloc((size + 1) * sizeof(char *));
	ret[size] = NULL;
	if (!ret)
	{
		cleaner_arr(ret, 0);
		return (NULL);
	}
	map_from_file(ret, fd);
	close(fd);
	return (ret);
}
