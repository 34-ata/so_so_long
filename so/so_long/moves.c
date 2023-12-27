/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faata <faata@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:50:10 by faata             #+#    #+#             */
/*   Updated: 2023/12/27 18:39:46 by faata            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	go_right(t_mlx *vars)
{
	if ((vars->map[vars->monster_y / 64][(vars->monster_x / 64) + 1] == 'E'
			&& vars->count_cookie == 0))
		ft_close("Success!");
	if (vars->map[vars->monster_y / 64][(vars->monster_x / 64) + 1] != '1'
		&& vars->map[vars->monster_y / 64][(vars->monster_x / 64) + 1] != 'E')
	{
		if (vars->map[vars->monster_y / 64][(vars->monster_x / 64) + 1] == 'C')
		{
			vars->count_cookie -= 1;
			printf("%d\n", vars->count_cookie);
		}
		vars->map[vars->monster_y / 64][vars->monster_x / 64] = '0';
		vars->map[vars->monster_y / 64][(vars->monster_x / 64) + 1] = 'P';
		ft_printmap(vars, -1, 0, 0);
		vars->num_of_mov += 1;
		write(1, "Number of movements: ", 21);
		ft_putnbr(vars->num_of_mov);
		vars->temp = ft_itoa(vars->num_of_mov);
		mlx_string_put(vars->mlx, vars->mlx_win,
			10, 20, 99999, "Number of Movements: ");
		mlx_string_put(vars->mlx, vars->mlx_win, 155, 20, 99999, vars->temp);
		free(vars->temp);
		write(1, "\n", 1);
	}
}

void	go_left(t_mlx *vars)
{
	if ((vars->map[vars->monster_y / 64][(vars->monster_x / 64) - 1] == 'E'
			&& vars->count_cookie == 0))
		ft_close("Success!");
	if (vars->map[vars->monster_y / 64][(vars->monster_x / 64) - 1] != '1'
		&& vars->map[vars->monster_y / 64][(vars->monster_x / 64) - 1] != 'E')
	{
		if (vars->map[vars->monster_y / 64][(vars->monster_x / 64) - 1] == 'C')
		{
			vars->count_cookie -= 1;
			printf("%d\n", vars->count_cookie);
		}
		vars->map[vars->monster_y / 64][vars->monster_x / 64] = '0';
		vars->map[vars->monster_y / 64][(vars->monster_x / 64) - 1] = 'P';
		ft_printmap(vars, -1, 0, 0);
		vars->num_of_mov += 1;
		write(1, "Number of movements: ", 21);
		ft_putnbr(vars->num_of_mov);
		vars->temp = ft_itoa(vars->num_of_mov);
		mlx_string_put(vars->mlx, vars->mlx_win,
			10, 20, 99999, "Number of Movements: ");
		mlx_string_put(vars->mlx, vars->mlx_win, 155, 21, 99999, vars->temp);
		free(vars->temp);
		write(1, "\n", 1);
	}
}

void	go_up(t_mlx *vars)
{
	if ((vars->map[(vars->monster_y / 64) - 1][vars->monster_x / 64] == 'E'
			&& vars->count_cookie == 0))
		ft_close("Success!");
	if (vars->map[(vars->monster_y / 64) - 1][vars->monster_x / 64] != '1'
		&& vars->map[(vars->monster_y / 64) - 1][vars->monster_x / 64] != 'E')
	{
		if (vars->map[(vars->monster_y / 64) - 1][vars->monster_x / 64] == 'C')
		{
			vars->count_cookie -= 1;
			printf("%d\n", vars->count_cookie);
		}
		vars->map[vars->monster_y / 64][vars->monster_x / 64] = '0';
		vars->map[(vars->monster_y / 64) - 1][vars->monster_x / 64] = 'P';
		ft_printmap(vars, -1, 0, 0);
		vars->num_of_mov += 1;
		write(1, "Number of movements: ", 21);
		ft_putnbr(vars->num_of_mov);
		vars->temp = ft_itoa(vars->num_of_mov);
		mlx_string_put(vars->mlx, vars->mlx_win,
			10, 20, 99999, "Number of Movements: ");
		mlx_string_put(vars->mlx, vars->mlx_win, 155, 21, 99999, vars->temp);
		free(vars->temp);
		write(1, "\n", 1);
	}
}

void	go_down(t_mlx *vars)
{
	if ((vars->map[(vars->monster_y / 64) + 1][vars->monster_x / 64] == 'E'
			&& vars->count_cookie == 0))
		ft_close("Success!");
	if (vars->map[(vars->monster_y / 64) + 1][vars->monster_x / 64] != '1'
		&& vars->map[(vars->monster_y / 64) + 1][vars->monster_x / 64] != 'E')
	{
		if (vars->map[(vars->monster_y / 64) + 1][vars->monster_x / 64] == 'C')
		{
			vars->count_cookie -= 1;
			printf("%d\n", vars->count_cookie);
		}
		vars->map[vars->monster_y / 64][vars->monster_x / 64] = '0';
		vars->map[(vars->monster_y / 64) + 1][vars->monster_x / 64] = 'P';
		ft_printmap(vars, -1, 0, 0);
		vars->num_of_mov += 1;
		write(1, "Number of movements: ", 21);
		ft_putnbr(vars->num_of_mov);
		vars->temp = ft_itoa(vars->num_of_mov);
		mlx_string_put(vars->mlx, vars->mlx_win,
			10, 20, 99999, "Number of Movements: ");
		mlx_string_put(vars->mlx, vars->mlx_win, 155, 21, 99999, vars->temp);
		free(vars->temp);
		write(1, "\n", 1);
	}
}
void ft_devil_moves(t_mlx *vars, int x, int y)
{
	while (vars->map[y][x])
	{
		x = 0;
		while (vars->map[y][x] && vars->map[y][x] != '\n')
		{
			if (vars->map[y][x] == 'N' && vars->map[y - 1][x] != '1' && vars->map[y - 1][x] != 'C' && vars->map[y - 1][x] != 'E' && vars->map[y - 1][x] != 'N')
			{
				if (vars->monster_y / 64 == y - 1 && vars->monster_x / 64 == x)
					ft_close("Eaten!");
				if (vars->monster_y / 64 < y)
				{
					vars->map[y - 1][x] = 'N';
					vars->map[y][x] = '0';
					ft_printmap(vars, -1, 0, 0);
				}
			}
			if (vars->map[y][x] == 'N' && vars->map[y + 1][x] != '1' && vars->map[y + 1][x] != 'C' && vars->map[y + 1][x] != 'E' && vars->map[y + 1][x] != 'N')
			{
				if (vars->monster_y / 64 == y + 1 && vars->monster_x / 64 == x)
					ft_close("Eaten!");
				if (vars->monster_y / 64 > y)
				{
					vars->map[y + 1][x] = 'N';
					vars->map[y][x] = '0';
					ft_printmap(vars, -1, 0, 0);
				}
			}
			if (vars->map[y][x] == 'N' && vars->map[y][x + 1] != '1' && vars->map[y][x + 1] != 'C' && vars->map[y][x + 1] != 'E' && vars->map[y][x + 1] != 'N')
			{
				if (vars->monster_x / 64 == x + 1 && vars->monster_y / 64 == y)
					ft_close("Eaten!");
				if (vars->monster_x / 64 > x)
				{
					vars->map[y][x + 1] = 'N';
					vars->map[y][x] = '0';
					ft_printmap(vars, -1, 0, 0);
				}
			}
			if (vars->map[y][x] == 'N' && vars->map[y][x - 1] != '1' && vars->map[y][x - 1] != 'C' && vars->map[y][x - 1] != 'E' && vars->map[y][x - 1] != 'N')
			{
				if (vars->monster_x / 64 == x - 1 && vars->monster_y / 64 == y)
					ft_close("Eaten!");
				if (vars->monster_x / 64 < x)
				{
					vars->map[y][x - 1] = 'N';
					vars->map[y][x] = '0';
					ft_printmap(vars, -1, 0, 0);
				}
			}
			x++;
		}
		y++;
	}
	ft_printmap(vars, -1, 0, 0);
}

int	key_hook(int keycode, t_mlx *vars)
{
	(void)vars;
	if (keycode == 53)
		exit(1);
	if (keycode == 2 || keycode == 124)
	{
		go_right(vars);
		//ft_devil_moves(vars, 0, 0);
	}
	if (keycode == 0 || keycode == 123)
	{
		go_left(vars);
		//ft_devil_moves(vars, 0, 0);
	}
	if (keycode == 1 || keycode == 125)
	{
		go_down(vars);
		//ft_devil_moves(vars, 0, 0);
	}
	if (keycode == 13 || keycode == 126)
	{
		go_up(vars);
		//ft_devil_moves(vars, 0, 0);
	}
	return (0);
}
