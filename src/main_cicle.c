/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cicle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:50:29 by ojessi            #+#    #+#             */
/*   Updated: 2019/10/26 17:49:00 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_cicle_key_support(t_wolf *wf, int a)
{
	if (a == 1)
	{
		delayformusic(100, wf);
		wf->player.x += cos(wf->player.angle) / 7;
		if (wf->map[(int)wf->player.y * wf->map_w + (int)wf->player.x] != ' ')
			wf->player.x -= cos(wf->player.angle) / 7;
		wf->player.y += sin(wf->player.angle) / 7;
		if (wf->map[(int)wf->player.y * wf->map_w + (int)wf->player.x] != ' ')
			wf->player.y -= sin(wf->player.angle) / 7;
	}
	else if (a == 2)
	{
		delayformusic(100, wf);
		wf->player.x -= cos(wf->player.angle) / 7;
		if (wf->map[(int)wf->player.y * wf->map_w + (int)wf->player.x] != ' ')
			wf->player.x += cos(wf->player.angle) / 7;
		wf->player.y -= sin(wf->player.angle) / 7;
		if (wf->map[(int)wf->player.y * wf->map_w + (int)wf->player.x] != ' ')
			wf->player.y += sin(wf->player.angle) / 7;
	}
}

void		ft_cicle(t_wolf *wf, t_rays *ray)
{
	while (!wf->loop)
	{
		while (SDL_PollEvent(&wf->sdl->event))
		{
			if (wf->sdl->event.type == SDL_QUIT)
				wf->loop = 1;
			if (wf->sdl->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				wf->loop = 1;
			if (wf->sdl->event.key.keysym.sym == SDLK_w)
				ft_cicle_key_support(wf, 1);
			if (wf->sdl->event.key.keysym.sym == SDLK_s)
				ft_cicle_key_support(wf, 2);
			SDL_GetMouseState(&wf->mouse.x, &wf->mouse.y);
			wf->player.angle -= wf->mouse.speed * (WIDTH / 2 - wf->mouse.x);
			SDL_WarpMouseInWindow(wf->sdl->win, WIDTH / 2, HEIGHT / 2);
			if (wf->sdl->event.key.keysym.sym == SDLK_a)
				wf->player.angle -= M_PI / 90;
			if (wf->sdl->event.key.keysym.sym == SDLK_d)
				wf->player.angle += M_PI / 90;
		}
		ft_create_image(wf, ray);
		put_fps(wf);
		SDL_UpdateWindowSurface(wf->sdl->win);
	}
}
