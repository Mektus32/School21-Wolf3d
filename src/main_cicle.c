/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cicle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:50:29 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/10 19:50:31 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_cicle(t_wolf *wf)
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
			{
				wf->player.x += cos(wf->player.angle) / 7;
				if (wf->map[(int)wf->player.y * wf->map_w + (int)wf->player.x] != ' ')
					wf->player.x -= cos(wf->player.angle) / 7;
				wf->player.y += sin(wf->player.angle) /7;
				if (wf->map[(int)wf->player.y * wf->map_w + (int)wf->player.x] != ' ')
					wf->player.y -= sin(wf->player.angle) / 7;
			}
			if (wf->sdl->event.key.keysym.sym == SDLK_s)
			{
				wf->player.x -= cos(wf->player.angle) / 7;
				if (wf->map[(int)wf->player.y * wf->map_w + (int)wf->player.x] != ' ')
					wf->player.x += cos(wf->player.angle) / 7;
				wf->player.y -= sin(wf->player.angle) /7;
				if (wf->map[(int)wf->player.y * wf->map_w + (int)wf->player.x] != ' ')
					wf->player.y += sin(wf->player.angle) / 7;
			}
			SDL_GetMouseState(&wf->mouse.x, &wf->mouse.y);
			wf->player.angle -= wf->mouse.speed * (WIDTH / 2 - wf->mouse.x);
			SDL_WarpMouseInWindow(wf->sdl->win, WIDTH / 2, HEIGHT / 2);
			if (wf->sdl->event.key.keysym.sym == SDLK_a)
				wf->player.angle -= M_PI / 90;
			if (wf->sdl->event.key.keysym.sym == SDLK_d)
				wf->player.angle += M_PI / 90;
		}
		ft_create_image(wf);
		SDL_UpdateWindowSurface(wf->sdl->win);
	}
}
