/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecampos <pecampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 09:32:38 by pecampos          #+#    #+#             */
/*   Updated: 2023/08/07 11:33:44 by pecampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "memory-leaks/include/memory_leaks.h"
 */
#include "so_long.h"

void	load(t_game *game)
{
	game->monedas = 0;
	game->salidas = 0;
	game->player.num_jugadores = 0;
	game->player.monedas = 0;
	game->vars.mlx = mlx_init(60 * game->map.x, 60 * game->map.y,
			"Hello world!", true);
	game->data.img = mlx_new_image(game->vars.mlx, 256, 256);
	game->player.texture = mlx_load_xpm42("xpm/cerdo.xpm42");
	game->textures.mountain = mlx_load_xpm42("xpm/mountain.xpm42");
	game->textures.cesped = mlx_load_xpm42("xpm/cesped.xpm42");
	game->textures.coin = mlx_load_xpm42("xpm/coin.xpm42");
	game->textures.exit = mlx_load_xpm42("xpm/exit.xpm42");
}
/*
void	load_map(t_game *game)
{
	int		fd;
	int		i;
	char	*c;
	int		res;

	i = 0;
	res = 0;
	fd = open(game->map.map, O_RDONLY);
	while (i < game->map.y)
	{
		write(1, "x\n", 3);
		c = get_next_line(fd);
		game->map.mapa[0] = c;
		write(1, "x\n", 3);
		free(c);
		i++;
	}
}
*/