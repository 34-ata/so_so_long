/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:50:55 by faata             #+#    #+#             */
/*   Updated: 2023/12/27 18:49:01 by faata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_extension(char *path)
{
	int	i;

	i = ft_strlen(path) - 1;
	if (path[i] == 'r' && path[i - 1] == 'e' && path[i - 2] == 'b'
		&& path[i - 3] == '.')
		return (1);
	return (0);
}

int	overload(t_mlx *st_mlx)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(st_mlx->map[i]) - 1;
	while (st_mlx->map[++i])
	{
		if (len != ft_strlen(st_mlx->map[i]) - 1
			&& i != ft_maplen(st_mlx->map_path) - 1)
			return (0);
		else if (i != ft_maplen(st_mlx->map_path) - 1
			&& len != ft_strlen(st_mlx->map[i]) - 1)
			return (0);
	}
	return (1);
}

int	boundary(t_mlx *st_mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (st_mlx->map[0][j] && st_mlx->map[0][j] != '\n')
		if (st_mlx->map[0][j++] != '1')
			return (0);
	j = 0;
	i = ft_maplen(st_mlx->map_path) - 1;
	while (st_mlx->map[i][j])
		if (st_mlx->map[i][j++] != '1')
			return (0);
	i = 0;
	j = 0;
	while (st_mlx->map[i])
		if (st_mlx->map[i++][0] != '1')
			return (0);
	j = ft_strlen(st_mlx->map[0]) - 1;
	while (st_mlx->map[i])
		if (st_mlx->map[i++][j] != '1')
			return (0);
	return (1);
}

int	ft_count(t_mlx *st_mlx, int exit_count, int monster_count)
{
	int	i;
	int	j;

	i = -1;
	while (st_mlx->map[++i])
	{
		j = -1;
		while (st_mlx->map[i][++j])
		{
			if (st_mlx->map[i][j] == 'C')
				st_mlx->count_cookie += 1;
			else if (st_mlx->map[i][j] == 'E')
				exit_count += 1;
			else if (st_mlx->map[i][j] == 'P' && (monster_count++, 1))
			{
				st_mlx->monster_x = j;
				st_mlx->monster_y = i;
			}
		}
	}
	if (exit_count != 1 || st_mlx->count_cookie == 0 || monster_count != 1)
		return (0);
	return (1);
}

int	map_check(t_mlx *st_mlx)
{
	st_mlx->count_cookie = 0;
	if (!ft_count(st_mlx, 0, 0))
		return (0);
	if (!boundary(st_mlx))
		return (0);
	if (!overload(st_mlx))
		return (0);
	if (!(flood_fill(st_mlx) && flood_fill0(st_mlx)))
		return (0);
	if (!ft_extension(st_mlx->map_path))
		return (0);
	return (1);
}
