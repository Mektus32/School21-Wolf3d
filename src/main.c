/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:10:51 by ojessi            #+#    #+#             */
/*   Updated: 2019/09/08 17:04:03 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int ac, char **av)
{
	t_wolf	*wf;

	wf = ft_memalloc(sizeof(t_wolf));
	if (ac == 2)
		ft_read_map(wf, av[1]);
	else
	{
		ft_putstr("More or less 1 arguments!\n");
	}
	!wf->map ? ft_init_sdl(wf) : 0;
	SDL_FreeSurface(wf->sdl->src);
	Mix_FreeChunk(wf->sdl->background);
	Mix_FreeChunk(wf->sdl->walk);
	SDL_DestroyWindow(wf->sdl->win);
	Mix_CloseAudio();
	SDL_Quit();
	return (0);
}
