
#include "so_long.h"

void	ft_start(t_mlx *mlx)
{
	ft_map_gen(mlx);
	ft_mlx_print_img(mlx, mlx->img->player, mlx->px, mlx->py);
}

int	main(int argc, char *argv[])
{
	t_mlx	*mlx;

	if (argc != 2 || ft_check_extension(argv[1]))
		return (-1);
	mlx = ft_mlx_init(argv[1]);
	if (!mlx)
		return (-1);
	ft_start(mlx);
	mlx_key_hook(mlx->win, ft_input, mlx);
	mlx_hook(mlx->win, 17, 0, ft_exit, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
