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
# define WIDTH 1024
# define HEIGHT 512

# include <stdio.h>
# include "libft.h"
# include "SDL.h"
# include <math.h>

typedef struct	s_sdl
{
	SDL_Window	*win;
	SDL_Surface	*src;
	SDL_Event	event;
}				t_sdl;

typedef	struct	s_rect
{
	size_t		x;
	size_t		y;
	size_t		w;
	size_t		h;
}				t_rect;

typedef struct	s_player
{
	double		x;
	double		y;
	double		angle;
}				t_player;

typedef	struct	s_wolf
{
	int 			i;
	int 			loop;
	t_sdl			*sdl;
	int 			*arr;
	const char		*map;
	double			fov;
	size_t			map_h;
	size_t			map_w;
	t_rect			rect;
	t_player		player;
}				t_wolf;

void 			ft_init_sdl(t_wolf *wf);
int				pack_color(const int r, const int g, const int b, int a);
int				unpack_color(const int *color, int *r, int *g, int *b);
void			ft_cicle(t_wolf *wf);
void			ft_create_image(t_wolf *wf);
void			ft_create_map(t_wolf *wf);
void			ft_put_rectangle(t_wolf *wf, size_t rect_w, size_t rect_h);
void			ft_draw_rectangle(t_wolf *wf, size_t img_w, size_t img_h, int color);
void			ft_put_player(t_wolf *wf, size_t rect_w, size_t rect_h);
void			ft_put_ray(t_wolf *wf, size_t rect_w, size_t rect_h);

#endif
