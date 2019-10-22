/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:59:05 by ojessi            #+#    #+#             */
/*   Updated: 2019/10/22 16:40:26 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_draw_rectangle(t_wolf *wf, size_t img_w, size_t img_h, int color)
{
	size_t		i;
	size_t		j;
	size_t		cx;
	size_t		cy;

	i = 0;
	while (i < wf->rect.h)
	{
		j = 0;
		while (j < wf->rect.w)
		{
			cx = wf->rect.x + j;
			cy = wf->rect.y + i;
			if (cx >= img_w || cy >= img_h)
			{
				j++;
				continue ;
			}
			wf->arr[cy * img_w + cx] = color;
			j++;
		}
		i++;
	}
}

void		ft_create_map(t_wolf *wf)
{
	size_t		i;

	if (!wf->map)
	{
		wf->map_h = 10;
		wf->map_w = 16;
		wf->map = ft_memalloc(sizeof(char) * (wf->map_w * wf->map_h + 1));
		ft_putstr("Loaded standart map!\n");
		ft_strcpy(wf->map, "1111111111111111"\
							"1         x    1"\
							"1     1        1"\
							"1     1  1111111"\
							"1     1        1"\
							"1   11111      1"\
							"1   1   1  11111"\
							"1       1      1"\
							"1              1"\
							"1111111111111111");
	}
	wf->player.angle = 1.523;
	wf->fov = 2 * atan(0.66) / 1.0;
	wf->mouse.speed = 0.001;
	i = -1;
	while (++i < 10)
		wf->color[i] = pack_color(rand() % 255, rand() % 255, rand() % 255, 0);
}

int			*ft_col_img(t_wolf *wf)
{
	int				*col;
	size_t			y;
	size_t			pix_x;
	size_t			pix_y;

	col = ft_memalloc(sizeof(int) * wf->wall.col_h);
	y = -1;
	while (++y < wf->wall.col_h)
	{
		pix_x = wf->wall.size_img + wf->wall.cor_img;
		pix_y = (y * wf->wall.size_img) / wf->wall.col_h;
		col[y] = ((int*)wf->wall.images[wf->wall.id_img]->pixels)[pix_y
												* wf->wall.size_img + pix_x];
	}
	return (col);
}

void		ft_init_map(t_wolf *wf, char *filename, int width, int height)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	wf->map = ft_memalloc(sizeof(char) * (width * height + 1));
	i = -1;
	while (get_next_line(fd, &line) > 0)
	{
		ft_strcpy(wf->map + (++i * width), line);
		ft_strdel(&line);
	}
	wf->map_h = height;
	wf->map_w = width;
	if (map_test(wf) == -1)
	{
		close(fd);
		ft_strdel(&wf->map);
		return ;
	}
	close(fd);
	print_map(wf);
}

void		ft_read_map(t_wolf *wf, char *filename)
{
	int		store[3];
	char	*line;

	if ((store[0] = open(filename, O_RDONLY)) < 0)
	{
		ft_putstr("Can't open file!\n");
		return ;
	}
	store[1] = 0;
	while (get_next_line(store[0], &line) > 0)
	{
		store[1] == 0 ? store[2] = (int)ft_strlen(line) : 0;
		if (store[2] != (int)ft_strlen(line))
		{
			ft_putstr("Map Test ///  Width of map is not correct!\n");
			close(store[0]);
			ft_strdel(&wf->map);
			return ;
		}
		store[1]++;
		ft_strdel(&line);
	}
	close(store[0]);
	ft_init_map(wf, filename, store[2], store[1]);
	ft_init_sdl(wf);
}
