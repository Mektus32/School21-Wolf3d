/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 13:59:05 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/13 13:59:06 by ojessi           ###   ########.fr       */
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
	!wf->map ? wf->map_h = 16 : 0;
	!wf->map ? wf->map_w = 16 : 0;
	!wf->map ? wf->map =	"0000222222220000"\
							"1              0"\
							"1     011111   0"\
							"1     0        0"\
							"0     0  1110000"\
							"0     3        0"\
							"0   10000      0"\
							"0   0   11100  0"\
							"0   0   0      0"\
							"0   0   1  00000"\
							"0       1      0"\
							"2       1      0"\
							"0       0      0"\
							"0 0000000      0"\
							"0              0"\
							"0002222222200000" : 0;
	wf->player.x = 3.456;
	wf->player.y = 2.345;
	wf->player.angle = 1.523;
	wf->fov = 2 * atan(0.66) / 1.0;//M_PI / 3.;
	wf->mouse.speed = 0.001;
	i = -1;
	while (++i < 10)
		wf->color[i] = pack_color(rand() % 255, rand() % 255, rand() % 255, 0);
}

int 	*ft_col_img(t_wolf *wf)
{
	int 			*col;
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
	int 	i;
	int 	fd;
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
	//printf("%p\n", wf->map);
	close(fd);
	wf->map_h = height;
	wf->map_w = width;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			printf("%c", wf->map[i * width + j]);
		printf("\n");
	}
}

void	ft_read_map(t_wolf *wf, char *filename)
{
	int		i;
	int 	fd;
	int 	len;
	char	*line;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_putstr("Can't open file!\n");
		return ;
	}
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		i == 0 ? len = (int)ft_strlen(line) : 0;
		if (len != (int)ft_strlen(line))
		{
			ft_putstr("Invalid file, not the same line!\n");
			close(fd);
			ft_strdel(&wf->map);
			return ;
		}
		i++;
		ft_strdel(&line);
	}
	close(fd);
	ft_init_map(wf, filename, len, i);
	ft_init_sdl(wf);
	//ft_cicle(wf);
}
