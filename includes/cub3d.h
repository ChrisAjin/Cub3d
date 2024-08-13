/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cassassa <cassassa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:31:57 by cassassa          #+#    #+#             */
/*   Updated: 2024/08/13 16:31:58 by cassassa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <mlx.h>
# include <math.h>
# include <limits.h>
# include "struct.h"
# include "../libft/src/libft.h"

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define SPACE			32

# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_L			65361
# define KEY_R			65363

enum	e_direction
{
	NORTH = 0,
	SOUTH = 1,
	EAST = 2,
	WEST = 3
};

/* ********************************************************** */
/*                           MAIN                             */
/* ********************************************************** */

/* MAIN */

void	bzero_struct(t_map *map);

/* FREE_FUNCTIONS */

void	destroy_image(t_map *map);
void	free_rgb_texture(t_map *map);
void	free_double_array(char **str);
int		close_game(t_map *map);



/* ********************************************************** */
/*                           GAME                             */
/* ********************************************************** */

/* KEY_EVENTS */

int		key_hook(int keycode, t_map *map);
int		mouse_rotate_hook(int x, int y, t_map *map);
int		mouse_hook(int keycode, int x, int y, t_map *map);

/* INIT_GAME */

void	game_error(t_map *map, char *message);
void	ft_init_game_stat(t_map *map);
void	ft_init_img(t_map *map);
int		ft_init_game(t_map *map);

/* MOVES */

void	move(t_map *map, double next_x, double next_y, char sign);
void	rotate(t_map *map, double rot_spd);
void	rotate_east_west(t_map *map, double rot_spd);

/* ********************************************************** */
/*                           RAYCASTING                       */
/* ********************************************************** */

/* RAYCASTING */

void	get_delta_dist(t_map *map);
void	get_step(t_map *map);
void	digital_differential_analyser(t_map *map);
void	init_raycasting(t_map *map, int x);
void	raycasting(t_map *map);

/* UTILS */

int		get_color(t_map *map, int x, int y, int i);

/* DRAW */

void	img_pix_put(t_map *map, int x, int y, int color);
void	draw_column(t_map *map, int x);
void	define_texture(t_map *map, int start, int line_height);
int		render(t_map *map);

/* RENDER */

int		create_trgb(int t, int r, int g, int b);
void	render_background(t_map *map);
int		render(t_map *map);

/* MINIMAP */

void	draw_minimap(t_map *map);
void	actualise_minimap(t_map *map, int old_x, int old_y);
void	minimap_pix_put(t_map *map, int x, int y, int color);
void	draw_case(t_map *map, int x, int y, int color);

/* UTILS */

int		is_valid_char(char c, char *valid_char);

#endif
