/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:36:25 by ojessi            #+#    #+#             */
/*   Updated: 2019/08/10 19:36:26 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int 	pack_color(const int r, const int g, const int b, int a)
{
	a = 255;
	return ((a << 24) + (r << 16) + (g << 8) + b);
}

int		unpack_color(const int *color, int *r, int *g, int *b)
{
	*b = (*color >> 0) & 255;
	*g = (*color >> 8) & 255;
	*r = (*color >> 16) & 255;
	return ((*color >> 24) & 255);
}