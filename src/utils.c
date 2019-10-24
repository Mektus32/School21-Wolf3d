/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:55:13 by sskinner          #+#    #+#             */
/*   Updated: 2019/10/24 16:30:21 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	crash(const char *str)
{
	ft_putstr(str);
	exit(0);
}

void	print_map(t_wolf *wf)
{
	size_t		i;
	size_t		j;

	i = -1;
	while (++i < wf->map_h)
	{
		j = -1;
		while (++j < wf->map_w)
			printf("%c", wf->map[i * wf->map_w + j]);
		printf("\n");
	}
}

void	delayformusic(int time, t_wolf *wf)
{
	clock_t	clocktime;

	clocktime = clock();
	while (clock() < clocktime + time)
		Mix_PlayChannelTimed(-1, wf->sdl->walk, 0, 300);
}

int		fpsset(t_wolf *wf)
{
	long	getticks;

	getticks = SDL_GetTicks();
	wf->framespersecond = (int)(getticks - wf->frametimelast);
	wf->frametimelast = getticks;
	wf->framespersecond = (int)(1000.f / wf->framespersecond);
	return (wf->framespersecond);
}

void		put_fps(t_wolf *wf)
{
	wf->fps->message = TTF_RenderText_Solid(wf->fps->font,
						ft_strjoin("Frame rate : ", ft_itoa(fpsset(wf))), wf->fps->textColor); //maybe leak?
	SDL_BlitSurface(wf->fps->message, NULL, wf->sdl->src, &wf->fps->textRect);
}
