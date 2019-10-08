/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:10:51 by ojessi            #+#    #+#             */
/*   Updated: 2019/10/08 09:29:27 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int ac, char **av)
{
	t_wolf	*wf;

	//sleep(5);
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
	free(wf->sdl);
	free(wf);
	return (0);
}
