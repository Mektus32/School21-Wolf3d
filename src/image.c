/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 20:18:11 by ojessi            #+#    #+#             */
/*   Updated: 2019/10/02 20:02:22 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_create_image(t_wolf *wf, t_rays *ray)
{
	const size_t	rect_w = WIDTH / (wf->map_w * 2) / 2;
	const size_t	rect_h = HEIGHT / wf->map_h / 2;
	size_t			i;
	size_t			j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (j < WIDTH && i < HEIGHT)
			{
				if (i <= HEIGHT / 2)
					wf->arr[i * WIDTH + j] = pack_color(0, 191, 255, 0);
				else
					wf->arr[i * WIDTH + j] = pack_color(101, 67, 33, 0);
			}
			j++;
		}
		i++;
	}
	ft_put_ray(wf, ray, rect_w, rect_h);
}

void	ft_put_rectangle(t_wolf *wf, size_t rect_w, size_t rect_h)
{
	size_t			i;
	size_t			j;

	i = -1;
	while (++i < wf->map_h)
	{
		j = -1;
		while (++j < wf->map_w)
		{
			if (wf->map[i * wf->map_w + j] == ' ')
				continue ;
			wf->rect.x = j * rect_w;
			wf->rect.y = i * rect_h;
			wf->rect.h = rect_h;
			wf->rect.w = rect_w;
			ft_draw_rectangle(wf, WIDTH, HEIGHT, pack_color(255, 255, 255, 0));
		}
	}
	ft_put_player(wf, rect_w, rect_h);
}

void	ft_put_player(t_wolf *wf, size_t rect_w, size_t rect_h)
{
	wf->rect.x = wf->player.x * rect_w;
	wf->rect.y = wf->player.y * rect_h;
	wf->rect.w = 2;
	wf->rect.h = 2;
	ft_draw_rectangle(wf, WIDTH, HEIGHT, pack_color(0, 0, 0, 0));
}
