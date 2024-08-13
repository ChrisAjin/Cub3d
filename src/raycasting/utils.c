#include "../../includes/cub3d.h"

int	get_color(t_map *map, int x, int y, int i)
{
	return (*(int *)(map->img[i].addr
		+ (y * map->img[i].line_len + x * (map->img[i].bpp / 8))));
}
