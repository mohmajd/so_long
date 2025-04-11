
#include "so_long.h"

static void	ft_mov(t_mlx *mlx, int x, int y)
{
	ft_map_genrate(mlx);
	ft_mlx_print_img(mlx, mlx->img->player, x, y);
}

static int	ft_can_mov(t_mlx *mlx, int x, int y)
{
	int		obg;
	char	*steps;

	obg = mlx->map[y][x];
	if (obg == '1' || (obg == 'E' && mlx->collected == 0))
		return (0);
	else
	{
		steps = ft_itoa(mlx->steps++);
		write(1, steps, ft_strlen(steps));
		free(steps);
		write(1, "\n", 1);
	}
	return (1);
}

static	void	ft_event(t_mlx *mlx, int px, int py)
{
	int	current;

	current = mlx->map[py][px];
	if (current == 'C')
	{
		mlx->map[py][px] = '0';
		mlx->keys--;
	}
	if (mlx->keys == 0)
		mlx->collected = 1;
	if ((current == 'E' && mlx->collected == 1))
	{
		write(1, "YOU WON!!\n", 10);
		ft_exit(mlx);
	}
}

int	ft_input(int keycode, t_mlx *mlx)
{
	static int	xpo;
	static int	ypo;

	if (xpo == 0 && ypo == 0)
	{
		xpo = mlx->px;
		ypo = mlx->py;
	}
	if (keycode == ESC_KEY)
		ft_exit(mlx);
	else if (keycode == W_KEY && ft_can_mov(mlx, xpo, ypo - 1))
		ypo -= 1;
	else if (keycode == S_KEY && ft_can_mov(mlx, xpo, ypo + 1))
		ypo += 1;
	else if (keycode == A_KEY && ft_can_mov(mlx, xpo - 1, ypo))
		xpo -= 1;
	else if (keycode == D_KEY && ft_can_mov(mlx, xpo + 1, ypo))
		xpo += 1;
	ft_mov(mlx, xpo, ypo);
	ft_event(mlx, xpo, ypo);
	return (0);
}
