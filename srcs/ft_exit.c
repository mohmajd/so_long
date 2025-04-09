
#include "so_long.h"

void	ft_free_images(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img->door);
	mlx_destroy_image(mlx->mlx, mlx->img->floor);
	mlx_destroy_image(mlx->mlx, mlx->img->key);
	mlx_destroy_image(mlx->mlx, mlx->img->player);
	mlx_destroy_image(mlx->mlx, mlx->img->wall);
	free(mlx->img);
}

int	ft_exit(t_mlx *mlx)
{
	ft_free_images(mlx);
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	ft_free_map(mlx->map);
	free(mlx->mlx);
	close(mlx->fd);
	free(mlx);
	exit(0);
	return (0);
}

void	ft_error_msg(unsigned int msg)
{
	if (msg == 1)
		write(2, "ERROR : Wrong Map Extention\n", 28);
	else if (msg == 2)
		write(2, "ERROR : Wrong Map Components\n", 29);
	else if (msg == 3)
		write(2, "ERROR : Missing Map Components\n", 31);
	else if (msg == 4)
		write(2, "ERROR : Doubled Components\n", 27);
	else if (msg == 5)
		write(2, "ERROR : Wrong Border\n", 21);
	else if (msg == 6)
		write(2, "ERROR : Player Can't Win\n", 25);
	else if (msg == 7)
		write(2, "ERROR : Map is too large\n", 25);
}
