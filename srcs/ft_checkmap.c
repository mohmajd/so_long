
#include "so_long.h"

int	ft_check_map_border(char **map, int map_x, int map_y)
{
	int	i;
	int	j;

	i = 0;
   	while (map[0][i] != '\n' && map[map_y][i] != '\n')
	{
		if (map[0][i] != '1' || map[map_y][i] != '1')
			return (ft_error_msg(5), 1);
		i++;
	}
	i = -1;
	while (++i < map_y)
		if (map[i][0] != '1')
			return (ft_error_msg(5), 1);
	j = -1;
	while (++j <= map_y)
	{
		i = -1;
		while (map[j][++i] != '\n')
			if ((i != map_x - 1 || map[j][i] != '1') && map[j][i + 1] == '\n')
				return (ft_error_msg(5), 1);
	}
	return (0);
}

int	ft_check_double(char **map)
{
	int	i;
	int	j;
	int	e;
	int	p;

	e = 0;
	p = 0;
	j = 0;
	while (map[++j] != NULL)
	{
		i = -1;
		while (map[j][++i] != '\n')
		{
			if (map[j][i] == 'P')
				p++;
			else if (map[j][i] == 'E')
				e++;
		}
	}
	if (p != 1 || e != 1)
		return (ft_error_msg(4), 1);
	return (0);
}

int	ft_check_map_components(char **map)
{
	int	i;
	int	j;

	j = 0;
	while (map[++j] != NULL)
	{
		i = -1;
		while (map[j][++i] != '\n')
		{
			if (map[j][i] != 'C' && map[j][i] != '1' && map[j][i] != '0'
				&& map[j][i] != 'E' && map[j][i] != 'P')
				return (ft_error_msg(2), 1);
		}
	}
	return (ft_check_double(map));
}

char	**ft_ckeck_map(char **map)
{
	int	key;
	int	map_x;
	int	map_y;
	int	player_x;
	int	exit_x;

	key = ft_key_count(map);
	map_x = ft_get_coordinates(map, 'S', 'x');
	map_y = ft_get_coordinates(map, 'S', 'y');
	player_x = ft_get_coordinates(map, 'P', 'x');
	exit_x = ft_get_coordinates(map, 'E', 'x');
	if (key <= 0 || player_x == map_x || exit_x == map_x
		|| map_x > 60 || map_y > 32)
		return (ft_error_msg(3), ft_free_map(map), NULL);
	if (ft_check_map_components(map)
		|| ft_check_map_border(map, map_x, map_y - 1))
		return (ft_free_map(map), NULL);
	return (map);
}

int	ft_check_extension(char *path)
{
	int		len;
	int		max;
	int		i;
	char	*extension;

	if (!path)
		return (1);
	extension = ".ber";
	len = ft_strlen(path);
	if (len < 4)
		return (1);
	max = len - 4;
	i = 0;
	while (max + i < len)
	{
		if (path[max + i] != extension[i])
			return (ft_error_msg(1), 1);
		i++;
	}
	return (0);
}
