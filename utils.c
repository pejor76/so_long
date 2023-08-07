/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecampos <pecampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:47:40 by pecampos          #+#    #+#             */
/*   Updated: 2023/03/17 16:52:23 by pecampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* #include "memory-leaks/include/memory_leaks.h"
 */
void	liberar(t_game *game)
{
	int	tam;

	tam = 0;
	while (game->map.y > tam)
	{
		free(game->full_map[tam]);
		tam++;
	}
	free(game->full_map);
	mlx_delete_image(game->vars.mlx, game->data.img);
}

void	assign(t_game *game, char *c, int x)
{
	int	z;

	z = 0;
	while (z < game->map.x)
	{
		game->full_map[x][z] = c[z];
		z++;
	}
}
