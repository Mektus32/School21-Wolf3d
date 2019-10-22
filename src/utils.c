/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 18:55:13 by sskinner          #+#    #+#             */
/*   Updated: 2019/10/22 16:24:37 by sskinner         ###   ########.fr       */
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
