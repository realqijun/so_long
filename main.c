#include "so_long.h"

int	mouse_event(void)
{
	printf("hello world");
	return (1);
}

int	main(void)
{
	void	*mlx = mlx_init();
	void	*win =  mlx_new_window(mlx, 1280, 720, "so_long");
	int width = 32;
	int height = 32;

	void *image = mlx_xpm_file_to_image(mlx, PLAYER_RIGHT, &width, &height);
	mlx_put_image_to_window(mlx, win, image, 200, 200);
	image = mlx_xpm_file_to_image(mlx, PLAYER_FRONT, &width, &height);
	mlx_put_image_to_window(mlx, win, image, 200, 168);
	image = mlx_xpm_file_to_image(mlx, PLAYER_LEFT, &width, &height);
	mlx_put_image_to_window(mlx, win, image, 200, 136);

	image = mlx_xpm_file_to_image(mlx, ENEMY, &width, &height);
	mlx_put_image_to_window(mlx, win, image, 300, 300);
	image = mlx_xpm_file_to_image(mlx, COIN, &width, &height);
	mlx_put_image_to_window(mlx, win, image, 332, 300);
	image = mlx_xpm_file_to_image(mlx, EXIT, &width, &height);
	mlx_put_image_to_window(mlx, win, image, 364, 300);
	image = mlx_xpm_file_to_image(mlx, WALL, &width, &height);
	mlx_put_image_to_window(mlx, win, image, 396,300);
	/*for (int i = 0; i < 1280; i++)
	{
		mlx_pixel_put(mlx, win, i, 300, 0x00FFFFFF);
	}
	mlx_mouse_hook(win, &mouse_event, 0);*/
	mlx_loop(mlx);
}
