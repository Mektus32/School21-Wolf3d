/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cicle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:50:29 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/10 19:50:31 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_cicle(t_wolf *wf)
{
	while (!wf->loop)
	{
		while (SDL_PollEvent(&wf->sdl->event))
		{
			if (wf->sdl->event.type == SDL_QUIT)
				wf->loop = 1;
			ft_create_image(wf);
		}
		SDL_UpdateWindowSurface(wf->sdl->win);
	}
}
