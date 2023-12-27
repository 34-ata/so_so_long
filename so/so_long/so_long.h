#ifndef SO_LONG
#define SO_LONG

#include <stdlib.h>
#include <unistd.h>
#include "mlx/mlx.h"
#include "get_next_line.h"
#include <fcntl.h>

typedef struct t_mlx {
	void *mlx;
	void *mlx_win;
	void *monster;
	void *devil;
	void *cookie;
	void *wall;
	void *parquet;
	void *open_exit;
	void *close_exit;
	char **map;
	char *map_path;
	int count_cookie;
	int monster_x;
	int monster_y;
	int map_x;
	int map_y;
	int num_of_mov;
	char *temp;
} t_mlx;

int map_check(t_mlx *st_mlx);
void flood_fill3(char **map, int x, int y, t_mlx *st_mlx);
void flood_fill2(char **map, int x, int y, t_mlx *st_mlx);
int flood_fill(t_mlx *st_mlx);
int flood_fill0(t_mlx *st_mlx);
int	key_hook(int keycode, t_mlx *vars);
void	ft_printmap(t_mlx *st_mlx, int i, int x, int y);
int ft_maplen(char *path);
char **ft_getmap(char *path);
void	ft_putnbr(unsigned int a);
int	ft_close(char *x);
char	*ft_itoa(int n);
void ft_devil_moves(t_mlx *vars, int x, int y);

#endif