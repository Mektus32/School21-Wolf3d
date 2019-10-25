/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:09:15 by ojessi            #+#    #+#             */
/*   Updated: 2019/10/25 15:20:48 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define WIDTH 1280
# define HEIGHT 640

# include <stdio.h>
# include "libft.h"
# include "SDL.h"
# include <SDL_image.h>
# include "SDL_mixer.h"
# include "SDL_ttf.h"
# include <math.h>
# include <time.h>

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Surface		*src;
	SDL_Event		event;
	Mix_Chunk		*walk;
	Mix_Chunk		*background;
}					t_sdl;

typedef struct		s_mouse
{
	int				x;
	int				y;
	double			speed;
}					t_mouse;

typedef	struct		s_rect
{
	size_t			x;
	size_t			y;
	size_t			w;
	size_t			h;
}					t_rect;

typedef struct		s_wall
{
	SDL_Surface		**images;
	size_t			size_img;
	size_t			id_img;
	size_t			cor_img;
	size_t			col_h;
}					t_wall;

typedef struct		s_player
{
	double			x;
	double			y;
	double			angle;
}					t_player;

typedef struct		s_text
{
	TTF_Font		*font;
	SDL_Surface		*message;
	SDL_Texture		*text;
	SDL_Rect		textRect;
	SDL_Color		textColor;
}					t_text;

typedef struct		s_rays
{
	double			t;
	double			cx;
	double			cy;
	double			angle;
	int				pix_x;
	int				pix_y;
	double			hitx;
	double			hity;
	int				coor_img;
	int				walltext_size;
	int				*col;
	int				tmpx;
	int				tmpy;
}					t_rays;

typedef	struct		s_wolf
{
	int				i;
	int				loop;
	t_sdl			*sdl;
	int				*arr;
	char			*map;
	double			fov;
	size_t			map_h;
	size_t			map_w;
	t_rect			rect;
	t_player		player;
	t_wall			wall;
	t_mouse			mouse;
	t_text			*fps;
	int				color[10];
	int				framespersecond;
	long			frametimelast;
}					t_wolf;

void				ft_init_sdl(t_wolf *wf);
int					pack_color(const int r, const int g, const int b, int a);
int					unpack_color(const int *color, int *r, int *g, int *b);
void				ft_cicle(t_wolf *wf, t_rays *ray);
void				ft_create_image(t_wolf *wf, t_rays *ray);
void				ft_create_map(t_wolf *wf);
void				ft_put_rectangle(t_wolf *wf, size_t rect_w, size_t rect_h);
void				ft_draw_rectangle(t_wolf *wf, size_t img_w, size_t img_h,
															int color);
void				ft_put_player(t_wolf *wf, size_t rect_w, size_t rect_h);
void				ft_put_ray(t_wolf *wf, t_rays *ray, size_t rect_w,
															size_t rect_h);
int					*ft_col_img(t_wolf *wf);
void				ft_read_map(t_wolf *wf, char *filename);
void				ft_init_map(t_wolf *wf, char *filename, int width, int height);
void				delayformusic(int time, t_wolf *wf);
void				print_map(t_wolf *wf);
void				crash(const char *str);
int					map_test(t_wolf *wf);
int					fpsset(t_wolf *wf);
void				put_fps(t_wolf *wf);
void				cleaning(t_wolf *wf);

#endif
