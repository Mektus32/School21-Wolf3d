/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:31:06 by ojessi            #+#    #+#             */
/*   Updated: 2019/10/22 16:39:24 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		images(t_wolf *wf)
{
	char		**split;
	size_t		count;
	size_t		i;

	if (!(split = ft_find_images_in_dir("images/", &count)))
	{
		ft_putstr("No directory or images\n");
		exit(0);
	}
	wf->wall.images = ft_memalloc(sizeof(SDL_Surface*) * count);
	i = -1;
	while (++i < count)
	{
		if (!(wf->wall.images[i] = SDL_LoadBMP(split[i])))
		{
			ft_putstr(SDL_GetError());
			exit(0);
		}
	}
	ft_frtwarr((void**)split, count);
}

static void		setup_defaults(t_wolf *wf)
{
	size_t		i;
	size_t		j;
	int			flag;

	i = -1;
	j = 0;
	flag = 0;
	while (wf->map[++i] != '\0')
	{
		if (wf->map[i] == ' ' && flag == 0)
		{
			flag = 1;
			wf->player.x = i - (wf->map_w * j) + 0.5;
			wf->player.y = j + 0.5;
		}
		if (i / wf->map_w > 0)
			j = i / wf->map_w;
		if (wf->map[i] == 'x')
		{
			flag = 1;
			wf->player.x = i - (wf->map_w * j) + 0.5;
			wf->player.y = j + 0.5;
			wf->map[i] = ' ';
		}
	}
}

void			ft_init_sdl(t_wolf *wf)
{
	t_rays	*ray;

	ray = ft_memalloc(sizeof(t_rays));
	wf->sdl = ft_memalloc(sizeof(t_sdl));
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		crash(SDL_GetError());
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	wf->sdl->walk = Mix_LoadWAV("sound/Sand_Boots_Running.wav");
	wf->sdl->background = Mix_LoadWAV("sound/background.wav");
	wf->sdl->win = SDL_CreateWindow("Wolf3d", 100, 100,
			WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (!wf->sdl->win)
		crash(SDL_GetError());
	wf->sdl->src = SDL_GetWindowSurface(wf->sdl->win);
	if (!wf->sdl->src)
		crash(SDL_GetError());
	SDL_ShowCursor(SDL_DISABLE);
	Mix_PlayChannel(-1, wf->sdl->background, -1);
	wf->arr = (int*)wf->sdl->src->pixels;
	images(wf);
	ft_create_map(wf);
	setup_defaults(wf);
	ft_cicle(wf, ray);
	free(ray);
}
