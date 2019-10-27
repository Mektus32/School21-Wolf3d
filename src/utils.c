/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:55:13 by sskinner          #+#    #+#             */
/*   Updated: 2019/10/26 17:49:07 by sskinner         ###   ########.fr       */
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

void	put_fps(t_wolf *wf)
{
	char		*fps;
	long		getticks;
	const char	*str = "Frame rate : ";
	char		*tmp;

	getticks = SDL_GetTicks();
	if ((wf->framespersecond = (int)(getticks - wf->frametimelast)) == 0)
		wf->framespersecond = 1;
	wf->frametimelast = getticks;
	wf->framespersecond = (int)(1000.f / wf->framespersecond);
	fps = ft_itoa(wf->framespersecond);
	tmp = ft_strjoin(str, fps);
	wf->fps->message = TTF_RenderText_Solid(wf->fps->font,
										tmp, wf->fps->text_color);
	SDL_BlitSurface(wf->fps->message, &wf->fps->back_rect, wf->sdl->src,
			&wf->fps->text_rect);
	SDL_FreeSurface(wf->fps->message);
	free(tmp);
	free(fps);
}
