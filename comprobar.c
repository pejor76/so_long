/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comprobar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecampos <pecampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:11:44 by pecampos          #+#    #+#             */
/*   Updated: 2023/03/20 16:27:12 by pecampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* #include "memory-leaks/include/memory_leaks.h"
 */
int	todo_paredes(char *c, t_game *game)
{
	int	x;

	x = 0;
	while (c[x] != '\n' && c[x] != 0)
	{
		if (c[x] != '1')
		{
			return (1);
		}
		x++;
	}
	if (x - 1 != game->map.x - 1)
	{
		return (1);
	}
	return (0);
}

int	comprobar_paredes(t_game *game)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (i < game->map.y)
	{
		if (i == 0 || i == game->map.y - 1)
		{
			res = todo_paredes(game->full_map[i], game) + res;
		}
		else if (game->full_map[i][0] != '1' || game->full_map[i][game->map.x
				- 1] != '1' || game->full_map[i][game->map.x] != '\n')
		{
			res++;
		}
		i++;
	}
	return (res);
}

void	tam_x(char *c, t_game *game)
{
	int	x;

	x = 0;
	while (c[x] != 0)
	{
		game->map.x = x;
		x++;
	}
}

void	tam_y(t_game *game)
{
	int		fd;
	int		i;
	char	*c;

	i = 1;
	fd = open(game->map.map, O_RDONLY);
	c = get_next_line(fd);
	tam_x(c, game);
	game->map.y = i;
	while (c != NULL)
	{
		free(c);
		c = get_next_line(fd);
		i++;
		game->map.y = i;
	}
	game->map.y = game->map.y - 1;
}
