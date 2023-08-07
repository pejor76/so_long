/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecampos <pecampos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:35:40 by pecampos          #+#    #+#             */
/*   Updated: 2023/03/17 16:48:19 by pecampos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*
# ifndef MAP_1
#  define MAP_1 "/Users/pecampos/so_long/test.ber"
# endif
*/
typedef struct s_data
{
	mlx_image_t		*img;
	int				addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_vars
{
	mlx_t			*mlx;
}					t_vars;

typedef struct s_player
{
	int				x;
	int				y;
	mlx_image_t		*img;
	xpm_t			*texture;
	int				num_pasos;
	int				monedas;
	int				num_jugadores;
}					t_player;

typedef struct s_textures
{
	xpm_t			*mountain;
	xpm_t			*cesped;
	xpm_t			*enemy;
	xpm_t			*coin;
	xpm_t			*exit;
}					t_textures;

typedef struct s_map
{
	char			*map;
	int				x;
	int				y;
}					t_map;

typedef struct s_game
{
	t_data			data;
	t_vars			vars;
	t_player		player;
	t_textures		textures;
	t_map			map;
	int				monedas;
	int				salidas;
	char			**full_map;
}					t_game;

char				*get_next_line(int fd);
char				*ft_line(char *buf);
char				*ft_read(int fd, char *buf);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *c);
char				*ft_strchr(const char *string, int c);
char				*ft_keep(char *buf);
char				*ft_strdup(char *src);
void				key_hook(t_game *game);
void				columnas(t_game *game);
void				filas(t_game *game);
void				character(t_game *game);
void				destroy(t_game *game);
void				my_keyhook(mlx_key_data_t keydata, void *param);
void				comprobar_c(int x, int y, t_game *game);
int					comprobar_m(int x, int y, t_game *game);
void				map_init(t_game *game);
void				comprobar_e(int x, int y, t_game *game);
char				*ft_itoa(int n);
int					ft_int(int num);
int					comprobar_paredes(t_game *game);
void				tam_x(char *c, t_game *game);
void				tam_y(t_game *game);
void				load(t_game *game);
void				load_map(t_game *game);
void				liberar(t_game *game);
void				assign(t_game *game, char *c, int x);

#endif