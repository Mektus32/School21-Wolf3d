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
	int			pix_x;
	int			pix_y;
	double		hitx;
	double		hity;
	int 		coor_img;
	int 		walltext_size = 64;//random
	int			*col = NULL;
	size_t		j;
	int			tmpx;
	int			tmpy;

	i = -1;
	while (++i < WIDTH)
	{
		angle = wf->player.angle - wf->fov / 2 + wf->fov * i / ((double)WIDTH);
		t = 0;
		while (t < 30)
		{
			cx = wf->player.x + t * cos(angle);
			cy = wf->player.y + t * sin(angle);

			pix_x = cx * rect_w;
			pix_y = cy * rect_h;
			wf->arr[pix_y * WIDTH + pix_x] = pack_color(160, 160, 160, 0);
			if (wf->map[(int)cy * wf->map_w + (int)cx] == ' ')
			{
				tmpx = cx;
				tmpy = cy;
			}
			if (wf->map[(int)cy * wf->map_w + (int)cx] != ' ')
			{
				wf->rect.h = HEIGHT / (t * (cos(angle - wf->player.angle)));
				wf->rect.y = HEIGHT / 2 - wf->rect.h / 2;
				hitx = cx - floor(cx + 0.5);
				hity = cy - floor(cy + 0.5);
				coor_img = hitx * walltext_size;
				if (fabs(hity) > fabs(hitx))
					coor_img = hity * walltext_size;
				if (coor_img < 0)
					coor_img += walltext_size;
				wf->wall.size_img = walltext_size;
				wf->wall.cor_img = coor_img;
				wf->wall.col_h = wf->rect.h;
				//Следующая строка отвечает за смену текстур относительно номера на карте
			//	wf->wall.id_img = wf->map[(int)cy * wf->map_w + (int)cx] - '0';
			//Эти условия -> попытка сделать разные текстуры на разных сторонах,  вроде как на двух получилось, значит надо додумать все варианты
			if (cx > tmpx && cy > tmpy)
					wf->wall.id_img = 0;
				else if (cx < tmpx && cy > tmpy)
					wf->wall.id_img = 1;
				else if (cx > tmpx && cy < tmpy)
					wf->wall.id_img = 2;
				else if (cx < tmpx && cy < tmpy)
					wf->wall.id_img = 3;
				col = ft_col_img(wf);
				pix_x = i;
				j = -1;
				while (++j < wf->rect.h)
				{
					pix_y = j + wf->rect.y;
					if (pix_y < 0 || pix_y >= HEIGHT)
						continue ;
					wf->arr[pix_y * WIDTH + pix_x] = col[j];
				}
				col ? free(col) : 0;
				break ;
			}
			t += 0.01;
		}
	}
	ft_put_rectangle(wf, rect_w, rect_h);
}
