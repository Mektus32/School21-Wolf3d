/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:13:35 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/12 14:13:36 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_put_ray(t_wolf *wf, size_t rect_w, size_t rect_h)
{
	double		t;
	double		cx;
	double		cy;
	size_t		i;
	double		angle;
	size_t		pix_x;
	size_t		pix_y;

	i = -1;
	while (++i < WIDTH)
	{
		angle = wf->player.angle - wf->fov / 2 + wf->fov * i / ((double)WIDTH);
		t = 0;
		while (t < 20)
		{
			cx = wf->player.x + t * cos(angle);
			cy = wf->player.y + t * sin(angle);

			pix_x = cx * rect_w;
			pix_y = cy * rect_h;
			wf->arr[pix_y * WIDTH + pix_x] = pack_color(160, 160, 160, 0);

			if (wf->map[(int) cy * wf->map_w + (int) cx] != ' ')
			{
				wf->rect.h = HEIGHT / (t * (cos(angle - wf->player.angle)));
				wf->rect.x = i;
				wf->rect.y = HEIGHT / 2 - wf->rect.h / 2;
				wf->rect.w = 1;
				ft_draw_rectangle(wf, WIDTH, HEIGHT, pack_color(255, 15, 195, 0));
				wf->arr[pix_y * WIDTH + pix_x] = pack_color(160, 160, 160, 0);
				break ;
			}
			t += 0.01;
		}
	}
	ft_put_rectangle(wf, rect_w, rect_h);
}
