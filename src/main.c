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

int		main(void)
{
	t_wolf	*wf;

	wf = ft_memalloc(sizeof(t_wolf));
	wf->map_h = 16;
	wf->map_w = 16;
	ft_init_sdl(wf);
	ft_cicle(wf);
	SDL_FreeSurface(wf->sdl->src);
	SDL_DestroyWindow(wf->sdl->win);
	SDL_Quit();
	return (0);
}
