/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:10:51 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/10 19:11:18 by ojessi           ###   ########.fr       */
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
	SDL_DestroyWindow(wf->sdl->win);
	SDL_Quit();
	return (0);
}
