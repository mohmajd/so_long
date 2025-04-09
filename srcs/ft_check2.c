
#include "so_long.h"

typedef struct s_point
{
	int	x;
	int	y;
}t_point;

char	**ft_get_map_cpy(char **map, int max_y, int max_x)
{
	char	**map_cpy;
	int		i;
	int		j;

	map_cpy = malloc((max_y + 1) * sizeof(char **));
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		map_cpy[i] = malloc(max_x);
		while (map[i][j] != '\n')
		{
			map_cpy[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	map_cpy[i] = NULL;
	return (map_cpy);
}

void	check_path(char **tab, t_point size, t_point cur, int *ek)
{
	if (tab[cur.y][cur.x] == 'C' || tab[cur.y][cur.x] == 'E')
	{
		*ek += 1;
		if (tab[cur.y][cur.x] == 'E')
			tab[cur.y][cur.x] = '1';
	}
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] == '1')
		return ;
	tab[cur.y][cur.x] = '1';
	check_path(tab, size, (t_point){cur.x - 1, cur.y}, ek);
	check_path(tab, size, (t_point){cur.x + 1, cur.y}, ek);
	check_path(tab, size, (t_point){cur.x, cur.y - 1}, ek);
	check_path(tab, size, (t_point){cur.x, cur.y + 1}, ek);
}

int	ft_check_path(t_mlx *mlx)
{
	t_point	size;
	t_point	start;
	char	**map;
	int		ek;

	size.x = ft_get_coordinates(mlx->map, 'S', 'x');
	size.y = ft_get_coordinates(mlx->map, 'S', 'y');
	start.x = ft_get_coordinates(mlx->map, 'P', 'x');
	start.y = ft_get_coordinates(mlx->map, 'P', 'y');
	ek = 0;
	map = ft_get_map_cpy(mlx->map, size.y + 1, size.x + 1);
	check_path(map, size, start, &ek);
	ft_free_map(map);
	if (ek != mlx->keys + 1)
		return (ft_error_msg(6), 1);
	return (0);
}
