/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:55:13 by sskinner          #+#    #+#             */
/*   Updated: 2019/10/25 16:38:40 by sskinner         ###   ########.fr       */
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
	wf->framespersecond = (int)(getticks - wf->frametimelast);
	wf->frametimelast = getticks;
	wf->framespersecond = (int)(1000.f / wf->framespersecond);
	fps = ft_itoa(wf->framespersecond);
	tmp = ft_strjoin(str, fps);
	wf->fps->message = TTF_RenderText_Solid(wf->fps->font,
										tmp, wf->fps->textColor);
	SDL_BlitSurface(wf->fps->message, NULL, wf->sdl->src, &wf->fps->textRect);
	SDL_FreeSurface(wf->fps->message);
	free(tmp);
	free(fps);
}

/*2019-10-25 16:36:38.655 wolf3d[20603:42361002] <NSXPCConnection: 0x7f812e449bb0> connection to service named com.apple.fonts: Warning: Exception caught during decoding of received reply to message 'XTCopyFontWithName:scope:options:reply:', dropping incoming message and calling failure block.

Exception: NSGetSizeAndAlignment(): malformed extended class info spec at '@"NSU8' in '@"NSU8'
2019-10-25 16:36:38.656 wolf3d[20603:42361002] <NSXPCConnection: 0x7f812e449bb0> connection to service named com.apple.fonts: Warning: Exception caught during decoding of received reply to message 'XTCopyFontWithName:scope:options:reply:', dropping incoming message and calling failure block.

Exception: NSGetSizeAndAlignment(): malformed extended class info spec at '@"NSU8' in '@"NSU8'
2019-10-25 16:36:38.656 wolf3d[20603:42361002] <NSXPCConnection: 0x7f812e449bb0> connection to service named com.apple.fonts: Warning: Exception caught during decoding of received reply to message 'XTCopyFontWithName:scope:options:reply:', dropping incoming message and calling failure block.

Exception: NSGetSizeAndAlignment(): malformed extended class info spec at '@"NSU8' in '@"NSU8'*/
