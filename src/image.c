/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 20:18:11 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/10 20:18:12 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_create_image(t_wolf *wf)
{
	int 	r;
	int 	g;
	int 	b;
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			r = 255 * i / (double)HEIGHT;
			g = 255 * j / (double)WIDTH;
			b = 0;
			wf->arr[i * WIDTH + j] = pack_color(r, g, b, 0);
		}
	}
	ft_put_rectangle(wf);
}

void	ft_rectangle(t_wolf *wf, size_t rec_w, size_t rec_h)
{
	size_t		i;
	size_t		j;
	size_t		cx;
	size_t		cy;

	i = -1;
	while (++i < rec_h)
	{
		j = -1;
		while (++j < rec_w)
		{
			cy = wf->pix.y + j;
			cx = wf->pix.x + i;
			if (cx < WIDTH && cy < HEIGHT)
				wf->arr[cy * WIDTH + cx] = wf->pix.color;
		}
	}
}

void	ft_create_map(t_wolf *wf)
{
	const char map[] = "0000222222220000"\
                       "1              0"\
                       "1      11111   0"\
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
                       "0002222222200000";

	wf->map = map;
}

void	ft_put_rectangle(t_wolf *wf)
{
	const size_t	rect_w = WIDTH / wf->map_w;
	const size_t	rect_h = HEIGHT / wf->map_h;
	size_t 			i;
	size_t			j;

	i = -1;
	while (++i < wf->map_h)
	{
		j = -1;
		while (++j < wf->map_w)
		{
			if (wf->map[i * wf->map_w + j] == ' ')
				continue ;
			wf->pix.x = j * rect_w;
			wf->pix.y = i * rect_h;
			wf->pix.color = pack_color(0, 255, 255, 0);
			ft_rectangle(wf, rect_w, rect_h);
		}
	}
}