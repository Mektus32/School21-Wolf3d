/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:13:35 by ojessi            #+#    #+#             */
/*   Updated: 2019/10/02 20:16:34 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	gear1(t_rays *ray, t_wolf *wf, size_t rect_w, size_t rect_h)
{
	ray->cx = wf->player.x + ray->t * cos(ray->angle);
	ray->cy = wf->player.y + ray->t * sin(ray->angle);
	ray->pix_x = ray->cx * rect_w;
	ray->pix_y = ray->cy * rect_h;
	wf->arr[ray->pix_y * WIDTH + ray->pix_x] = pack_color(160, 160, 160, 0);
	if (wf->map[(int)ray->cy * wf->map_w + (int)ray->cx] == ' ')
	{
		ray->tmpx = ray->cx;
		ray->tmpy = ray->cy;
	}
}

static void	gear2(t_rays *ray, t_wolf *wf)
{
	wf->rect.h = HEIGHT / (ray->t * (cos(ray->angle - wf->player.angle)));
	wf->rect.y = HEIGHT / 2 - wf->rect.h / 2;
	ray->hitx = ray->cx - floor(ray->cx + 0.5);
	ray->hity = ray->cy - floor(ray->cy + 0.5);
	ray->coor_img = ray->hitx * ray->walltext_size;
	if (fabs(ray->hity) > fabs(ray->hitx))
		ray->coor_img = ray->hity * ray->walltext_size;
	if (ray->coor_img < 0)
		ray->coor_img += ray->walltext_size;
	wf->wall.size_img = ray->walltext_size;
	wf->wall.cor_img = ray->coor_img;
	wf->wall.col_h = wf->rect.h;
	if (ray->cx > ray->tmpx && ray->cy > ray->tmpy)
		wf->wall.id_img = 0;
	else if (ray->cx < ray->tmpx && ray->cy > ray->tmpy)
		wf->wall.id_img = 1;
	else if (ray->cx > ray->tmpx && ray->cy < ray->tmpy)
		wf->wall.id_img = 2;
	else if (ray->cx < ray->tmpx && ray->cy < ray->tmpy)
		wf->wall.id_img = 3;
	ray->col = ft_col_img(wf);
}

static void	gear3(t_rays *ray, t_wolf *wf, int i)
{
	size_t	j;

	gear2(ray, wf);
	ray->pix_x = i;
	j = -1;
	while (++j < wf->rect.h)
	{
		ray->pix_y = j + wf->rect.y;
		if (ray->pix_y < 0 || ray->pix_y >= HEIGHT)
			continue ;
		wf->arr[ray->pix_y * WIDTH + ray->pix_x] = ray->col[j];
	}
}

void		ft_put_ray(t_wolf *wf, t_rays *ray, size_t rect_w, size_t rect_h)
{
	size_t		i;

	ray->walltext_size = 64;
	ray->col = NULL;
	i = -1;
	while (++i < WIDTH)
	{
		ray->angle = wf->player.angle - wf->fov / 2 + wf->fov * i
													/ ((double)WIDTH);
		ray->t = 0;
		while (ray->t < 30)
		{
			gear1(ray, wf, rect_w, rect_h);
			if (wf->map[(int)ray->cy * wf->map_w + (int)ray->cx] != ' ')
			{
				gear3(ray, wf, i);
				ray->col ? free(ray->col) : 0;
				break ;
			}
			ray->t += 0.01;
		}
	}
	ft_put_rectangle(wf, rect_w, rect_h);
}
