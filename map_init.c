/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecampos <pecampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:11:44 by pecampos          #+#    #+#             */
/*   Updated: 2023/03/17 16:53:18 by pecampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "memory-leaks/include/memory_leaks.h"
 */
#include "so_long.h"

void	mountain(t_game *game, int x, int y)
{
	game->data.img = mlx_texture_to_image(game->vars.mlx,
			&game->textures.mountain->texture);
	mlx_image_to_window(game->vars.mlx, game->data.img, 60 * y, 60 * x);
}

void	player(t_game *game, int y, int x)
{
	game->player.img = mlx_texture_to_image(game->vars.mlx,
			&game->player.texture->texture);
	game->player.x = (x * 60);
	game->player.y = (y * 60);
	mlx_image_to_window(game->vars.mlx, game->player.img, game->player.x,
		game->player.y);
	game->player.num_jugadores++;
}

void	coin(t_game *game, int x, int y)
{
	game->data.img = mlx_texture_to_image(game->vars.mlx,
			&game->textures.coin->texture);
	mlx_image_to_window(game->vars.mlx, game->data.img, 60 * y, 60 * x);
	game->monedas++;
}

void	colocar(t_game *game, char *a, int x)
{
	int	y;

	y = 0;
	while (a[y] != 0 && a[y] != '\n')
	{
		game->data.img = mlx_texture_to_image(game->vars.mlx,
				&game->textures.cesped->texture);
		mlx_image_to_window(game->vars.mlx, game->data.img, 60 * y, 60 * x);
		if (a[y] == 49)
			mountain(game, x, y);
		else if (a[y] == 80)
			player(game, x, y);
		else if (a[y] == 'C')
			coin(game, x, y);
		else if (a[y] == 'E')
		{
			game->data.img = mlx_texture_to_image(game->vars.mlx,
					&game->textures.exit->texture);
			game->salidas++;
			mlx_image_to_window(game->vars.mlx, game->data.img, 60 * y, 60 * x);
		}
		y++;
	}
}

void	map_init(t_game *game)
{
	int		fd;
	int		i;
	char	*c;

	i = 0;
	game->player.num_pasos = 0;
	game->full_map = (char **)malloc(sizeof(char *) * (game->map.y + 1));
	fd = open(game->map.map, O_RDONLY);
	while (i < game->map.y)
	{
		game->full_map[i] = (char *)malloc(sizeof(char) * (game->map.x));
		c = get_next_line(fd);
		assign(game, c, i);
		colocar(game, c, i);
		free(c);
		i++;
	}
	i = 0;
	while (i < game->map.y)
	{
		i++;
	}
	close(fd);
}
