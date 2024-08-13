#include "../includes/cub3d.h"

int	ft_test_extension(char *argv)
{
	int	i;
	int	j;

	i = ft_strlen(argv);
	j = 0;
	i -= 4;
	while (argv[i] != '\0')
	{
		if (j == 0 && argv[i] != '.')
			return (0);
		if (j == 1 && argv[i] != 'c')
			return (0);
		if (j == 2 && argv[i] != 'u')
			return (0);
		if (j == 3 && argv[i] != 'b')
			return (0);
		i++;
		j++;
	}
	return (1);
}

void	bzero_struct(t_map *map)
{
	int	i;

	i = 0;
	map->map_tab = NULL;
	map->width_map = 0;
	map->height_map = 0;
	map->rgb_floor[0] = -1;
	map->rgb_floor[1] = -1;
	map->rgb_floor[2] = -1;
	map->rgb_sky[0] = -1;
	map->rgb_sky[1] = -1;
	map->rgb_sky[2] = -1;
	map->line = NULL;
	map->map_line = NULL;
	while (i < 5)
	{
		map->img[i].mlx_img = NULL;
		map->img[i].path = NULL;
		i++;
	}
	map->minimap.mlx_img = NULL;
}

int	main(int ac, char **av)
{
	t_map	map;
	int		fd;

	bzero_struct(&map);
	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd <= 0)
	{
		ft_printf("Error\nFailed to open file\n");
		return (37);
	}
	if (!ft_parse_map(&map, fd))
	{
		free_double_array(map.map_tab);
		return (38);
	}
	ft_init_game(&map);
	return (0);
}
