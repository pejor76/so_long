/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecampos <pecampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:11:44 by pecampos          #+#    #+#             */
/*   Updated: 2023/03/17 16:52:36 by pecampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* #include "memory-leaks/include/memory_leaks.h"
 */
void	up(t_game *game)
{
	comprobar_e((game->player.x / 60), (game->player.y / 60) - 1, game);
	comprobar_c((game->player.x / 60), (game->player.y / 60) - 1, game);
	game->player.y = game->player.y - 60;
	mlx_delete_image(game->vars.mlx, game->player.img);
	game->player.img = mlx_texture_to_image(game->vars.mlx,
			&game->player.texture->texture);
	mlx_image_to_window(game->vars.mlx, game->player.img, game->player.x,
		game->player.y);
	game->player.num_pasos++;
	ft_int(game->player.num_pasos);
}

void	down(t_game *game)
{
	comprobar_e(game->player.x / 60, (game->player.y / 60) + 1, game);
	comprobar_c(game->player.x / 60, (game->player.y / 60) + 1, game);
	game->player.num_pasos++;
	game->player.y = game->player.y + 60;
	mlx_delete_image(game->vars.mlx, game->player.img);
	game->player.img = mlx_texture_to_image(game->vars.mlx,
			&game->player.texture->texture);
	mlx_image_to_window(game->vars.mlx, game->player.img, game->player.x,
		game->player.y);
	ft_int(game->player.num_pasos);
}

void	right(t_game *game)
{
	comprobar_e((game->player.x / 60) + 1, (game->player.y / 60), game);
	comprobar_c((game->player.x / 60) + 1, (game->player.y / 60), game);
	game->player.num_pasos++;
	game->player.x = game->player.x + 60;
	mlx_delete_image(game->vars.mlx, game->player.img);
	game->player.img = mlx_texture_to_image(game->vars.mlx,
			&game->player.texture->texture);
	mlx_image_to_window(game->vars.mlx, game->player.img, game->player.x,
		game->player.y);
	ft_int(game->player.num_pasos);
}

void	left(t_game *game)
{
	comprobar_e((game->player.x / 60) - 1, (game->player.y / 60), game);
	comprobar_c((game->player.x / 60) - 1, (game->player.y / 60), game);
	game->player.num_pasos++;
	game->player.x = game->player.x - 60;
	mlx_delete_image(game->vars.mlx, game->player.img);
	game->player.img = mlx_texture_to_image(game->vars.mlx,
			&game->player.texture->texture);
	mlx_image_to_window(game->vars.mlx, game->player.img, game->player.x,
		game->player.y);
	ft_int(game->player.num_pasos);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS
		&& comprobar_m((game->player.x) / 60,
			(game->player.y + 60) / 60, game) != 1
		&& (game->player.y + 60) / 60 != game->map.y + 1)
		down(game);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS
		&& comprobar_m((game->player.x + 60) / 60,
			(game->player.y) / 60, game) != 1)
		right(game);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS
		&& comprobar_m((game->player.x - 60) / 60,
			(game->player.y) / 60, game) != 1)
		left(game);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
		&& comprobar_m((game->player.x) / 60,
			(game->player.y - 60) / 60, game) != 1)
		up(game);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->vars.mlx);
}
