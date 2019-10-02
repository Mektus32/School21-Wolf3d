/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:59:05 by ojessi            #+#    #+#             */
/*   Updated: 2019/10/02 19:16:47 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_rectangle(t_wolf *wf, size_t img_w, size_t img_h, int color)
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

void	ft_create_map(t_wolf *wf)
{
	size_t		i;

	!wf->map ? ft_putstr("Loaded standart map!\n") : 0;
	!wf->map ? wf->map_h = 12 : 0;
	!wf->map ? wf->map_w = 16 : 0;
	!wf->map ? wf->map = "0000222222220000"\
							"1              0"\
							"1         3    0"\
							"1     0        0"\
							"0     0  1110000"\
							"0     3        0"\
							"0   10000      0"\
							"0   0   0      0"\
							"0   0   1  00000"\
							"0       1      0"\
							"0              0"\
							"0002222222200000" : 0;
	wf->player.x = 3.456;
	wf->player.y = 2.345;
	wf->player.angle = 1.523;
	wf->fov = 2 * atan(0.66) / 1.0;
	wf->mouse.speed = 0.001;
	i = -1;
	while (++i < 10)
		wf->color[i] = pack_color(rand() % 255, rand() % 255, rand() % 255, 0);
}

int		*ft_col_img(t_wolf *wf)
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

void	ft_init_map(t_wolf *wf, char *filename, int width, int height)
{
	int		i;
	int		fd;
	char	*line;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_putstr("Can't open file!\n");
		return ;
	}
	wf->map = ft_memalloc(sizeof(char) * (width * height + 1));
	i = -1;
	while (get_next_line(fd, &line) > 0)
	{
		ft_strcpy(wf->map + (++i * width), line);
		ft_strdel(&line);
	}
	close(fd);
	wf->map_h = height;
	wf->map_w = width;
	print_map(wf);
}

void	ft_read_map(t_wolf *wf, char *filename)
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
			ft_putstr("Invalid file, not the same line!\n");
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
