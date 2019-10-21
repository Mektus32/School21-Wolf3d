/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sskinner <sskinner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:20:36 by sskinner          #+#    #+#             */
/*   Updated: 2019/10/21 16:34:03 by sskinner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		is_correct_symbol(char a)
{
	if (a == '1')
		return (1);
	if (a == ' ')
		return (2);
	if (a == 'x')
		return (3);
	else
		return (0);
}

static int		symbolic_test(t_wolf *wf)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (wf->map[i] != '\0')
	{
		if (is_correct_symbol(wf->map[i]) == 0)
		{
			ft_putstr("Map Test // Symbols in map is not correct!\n");
			ft_putstr("Symbols that can be used:\n");
			ft_putstr("1 for wall\nx for player\n");
			ft_putstr("'Space bar' for ..u know.. space\n");
			return (-1);
		}
		if (is_correct_symbol(wf->map[i]) == 3)
			l++;
		i++;
	}
	if (l > 1)
	{
		ft_putstr("Map Test // There can only be one place for a player!\n");
		return (-1);
	}
	return (0);
}

static int		wall_test(t_wolf *wf)
{
	size_t			i;
	unsigned long	d;

	i = 0;
	d = 0;
	while (wf->map[i] != '\0')
	{
		if ((d == wf->map_w - 1 || wf->map[i + 1] == '\0') ||
		(d == 0) || (i < wf->map_w) ||
		((i > (wf->map_w * (wf->map_h - 1)) &&
		i < wf->map_w * wf->map_h)))
			if (is_correct_symbol(wf->map[i]) != 1)
			{
				ft_putstr("Map Test // Wall is not correct!\n");
				return (-1);
			}
		i++;
		d++;
		if (d == wf->map_w)
			d = 0;
	}
	return (0);
}

static int		player_test(t_wolf *wf)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (wf->map[i] != '\0')
	{
		if (is_correct_symbol(wf->map[i]) == 2 ||
		is_correct_symbol(wf->map[i]) == 3)
			k++;
		i++;
	}
	if (k == 0)
	{
		ft_putstr("Map Test // The map must have at least one space on it!\n");
		return (-1);
	}
	return (0);
}

int				map_test(t_wolf *wf)
{
	if (symbolic_test(wf) == -1)
		return (-1);
	if (wall_test(wf) == -1)
		return (-1);
	if (player_test(wf) == -1)
		return (-1);
	return (0);
}
