/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:31:06 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/10 19:31:08 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init_sdl(t_wolf *wf)
{
	wf->sdl = ft_memalloc(sizeof(t_sdl));
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		ft_putstr(SDL_GetError());
		exit(0);
	}
	wf->sdl->win = SDL_CreateWindow("Wolf3d", 100, 100,
			WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (!wf->sdl->win)
	{
		ft_putstr(SDL_GetError());
		exit(0);
	}
	wf->sdl->src = SDL_GetWindowSurface(wf->sdl->win);
	if (!wf->sdl->src)
	{
		ft_putstr(SDL_GetError());
		exit(0);
	}
	wf->sdl->img = SDL_LoadBMP("image.bmp");
	if (!wf->sdl->img)
	{
		ft_putstr(SDL_GetError());
		exit(0);
	}
	wf->arr = (int*)wf->sdl->src->pixels;
//	for (int i = 0; i < 512; i++)
//		for (int j = 0; j < 512; j++)
//			wf->arr[i * 1024 + j] = ((int*)wf->sdl->img->pixels)[i * 512 + j];
	ft_create_map(wf);
}