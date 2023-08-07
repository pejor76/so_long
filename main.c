/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecampos <pecampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:11:44 by pecampos          #+#    #+#             */
/*   Updated: 2023/03/20 16:47:06 by pecampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* #include "memory-leaks/include/memory_leaks.h"
 */
int	comprobar_m(int x, int y, t_game *game)
{
	if (game->full_map[y][x] == '1')
	{
		return (1);
	}
	return (0);
}

void	comprobar_c(int x, int y, t_game *game)
{
	if (game->full_map[y][x] == 'C')
	{
		game->data.img = mlx_texture_to_image(game->vars.mlx,
				&game->textures.cesped->texture);
		mlx_image_to_window(game->vars.mlx, game->data.img, x * 60, y * 60);
		game->player.monedas++;
		game->full_map[y][x] = '0';
	}
}

void	comprobar_e(int x, int y, t_game *game)
{
	if (game->full_map[y][x] == 'E' && game->player.monedas >= game->monedas)
	{
		mlx_close_window(game->vars.mlx);
	}
}

int	ft_int(int num)
{
	int		x;
	char	c;
	char	*str;

	str = ft_itoa(num);
	x = 0;
	while (str[x] != '\0')
	{
		c = str[x];
		write(1, &c, 1);
		x++;
	}
	write(1, "\n", 1);
	free(str);
	return (x);
}

/*  void	showleaks(void)
{
	system("leaks -q so_long");
}  */

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(1, "Error\n", 7);
		return (0);
	}
	game.map.map = argv[1];
	tam_y(&game);
	load(&game);
	map_init(&game);
	if (comprobar_paredes(&game) != 0 || game.salidas != 1
		|| game.player.num_jugadores != 1 || game.monedas == 0)
	{
		write(1, "Error\n", 7);
		liberar(&game);
		return (0);
	}
	mlx_key_hook(game.vars.mlx, &my_keyhook, &game);
	mlx_loop(game.vars.mlx);
	liberar(&game);
	return (0);
}

//showleaks();