
#include "so_long.h"

int	ft_get_coordinates(char **map, int obg, int axis)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j] != NULL)
	{
		i = 0;
		while (map[j][i] != '\n')
		{
			if (map[j][i] == obg)
				break ;
			i++;
		}
		if (map[j][i] == obg)
			break ;
		j++;
	}
	if (axis == 'x')
		return (i);
	else if (axis == 'y')
		return (j);
	return (0);
}

void	ft_free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_map_max(char **map, int max)
{
	int	i;

	i = 0;
	while (i <= max)
		free(map[i++]);
}

char	**ft_get_map(int fd)
{
	char	*tmp_map[MAX_COL];
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = -1;
	tmp_map[i] = get_next_line(fd);
	if (!tmp_map[i])
		return (NULL);
	while (tmp_map[i] != NULL && i < MAX_COL - 1)
		tmp_map[++i] = get_next_line(fd);
	if (i == MAX_COL - 1)
		return (ft_error_msg(7), ft_free_map_max(tmp_map, i), NULL);
	map = malloc(sizeof(char *) * (i + 1));
	if (map == NULL)
		return (ft_free_map_max(tmp_map, i), NULL);
	while (++j < i)
		map[j] = tmp_map[j];
	map[i] = NULL;
	map = ft_ckeck_map(map);
	return (map);
}

void	ft_map_generate(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mlx->map[j] != NULL)
	{
		i = 0;
		while (mlx->map[j][i] != '\n')
		{
			if (mlx->map[j][i] == '1')
				ft_mlx_print_img(mlx, mlx->img->wall, i, j);
			else if (mlx->map[j][i] == 'C' && mlx->collected == 0)
				ft_mlx_print_img(mlx, mlx->img->key, i, j);
			else if (mlx->map[j][i] == 'E')
				ft_mlx_print_img(mlx, mlx->img->door, i, j);
			else
				ft_mlx_print_img(mlx, mlx->img->floor, i, j);
			i++;
		}
		j++;
	}
}
