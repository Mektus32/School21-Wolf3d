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
	wf->map =	"0000222222220000"\
				"1              0"\
				"1      11111   0"\
				"1     00       0"\
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
	wf->map_h = 16;
	wf->map_w = 16;
	wf->player.x = 3.456;
	wf->player.y = 2.345;
	wf->player.angle = 1.523;
	wf->fov = M_PI / 3.;
}
