/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:09:15 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/10 19:10:12 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define WIDTH 640
# define HEIGHT 640

# include <stdio.h>
# include "libft.h"
# include "SDL.h"

typedef struct	s_sdl
{
	SDL_Window	*win;
	SDL_Surface	*src;
	SDL_Event	event;
}				t_sdl;

typedef	struct	s_pix
{
	int 	x;
	int 	y;
	int 	color;
}				t_pix;

typedef	struct	s_wolf
{
	int 			i;
	int 			loop;
	t_sdl			*sdl;
	int 			*arr;
	const char		*map;
	size_t			map_h;
	size_t			map_w;
	t_pix		pix;
}				t_wolf;

void 			ft_init_sdl(t_wolf *wf);
int				pack_color(const int r, const int g, const int b, int a);
int				unpack_color(const int *color, int *r, int *g, int *b);
void			ft_cicle(t_wolf *wf);
void			ft_create_image(t_wolf *wf);
void			ft_rectangle(t_wolf *wf, size_t rec_w, size_t rec_h);
void			ft_put_rectangle(t_wolf *wf);

#endif
