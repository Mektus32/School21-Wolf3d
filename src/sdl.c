/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:31:06 by ojessi            #+#    #+#             */
/*   Updated: 2019/10/26 17:52:58 by sskinner         ###   ########.fr       */
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
	int		store[3];

	store[0] = -1;
	store[1] = 0;
	store[2] = 0;
	while (wf->map[++store[0]] != '\0')
	{
		if (wf->map[store[0]] == ' ' && store[2] == 0)
		{
			store[2] = 1;
			wf->player.x = store[0] - (wf->map_w * store[1]) + 0.5;
			wf->player.y = store[1] + 0.5;
		}
		if (store[0] / wf->map_w > 0)
			store[1] = store[0] / wf->map_w;
		if (wf->map[store[0]] == 'x')
		{
			store[2] = 1;
			wf->player.x = store[0] - (wf->map_w * store[1]) + 0.5;
			wf->player.y = store[1] + 0.5;
			wf->map[store[0]] = ' ';
		}
	}
	wf->framespersecond = 0;
	wf->frametimelast = SDL_GetTicks();
}

static void		setup_text(t_wolf *wf)
{
	wf->fps = malloc(sizeof(t_text));
	wf->fps->text_color.r = 255;
	wf->fps->text_color.g = 255;
	wf->fps->text_color.b = 255;
	wf->fps->text_rect.x = WIDTH - 200;
	wf->fps->text_rect.y = HEIGHT - 50;
	wf->fps->text_rect.w = 300;
	wf->fps->text_rect.h = 200;
	wf->fps->back_rect.x = 0;
	wf->fps->back_rect.y = 0;
	wf->fps->back_rect.w = WIDTH;
	wf->fps->back_rect.h = HEIGHT;
	if (!(wf->fps->font = TTF_OpenFont("fonts/OpenSans-Semibold.ttf", 25)))
		crash(SDL_GetError());
}

void			ft_init_sdl(t_wolf *wf)
{
	t_rays	*ray;

	ray = ft_memalloc(sizeof(t_rays));
	wf->sdl = ft_memalloc(sizeof(t_sdl));
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
		crash(SDL_GetError());
	if (TTF_Init() == -1)
		crash(TTF_GetError());
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	wf->sdl->walk = Mix_LoadWAV("sound/Sand_Boots_Running.wav");
	wf->sdl->background = Mix_LoadWAV("sound/background.wav");
	if (!(wf->sdl->win = SDL_CreateWindow("Wolf3d", 100, 100,
			WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		crash(SDL_GetError());
	if (!(wf->sdl->src = SDL_GetWindowSurface(wf->sdl->win)))
		crash(SDL_GetError());
	Mix_PlayChannel(-1, wf->sdl->background, -1);
	SDL_ShowCursor(SDL_DISABLE);
	wf->arr = (int*)wf->sdl->src->pixels;
	setup_text(wf);
	images(wf);
	ft_create_map(wf);
	setup_defaults(wf);
	ft_cicle(wf, ray);
	free(ray);
}
