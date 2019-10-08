/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_images_in_dir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 21:15:07 by ojessi            #+#    #+#             */
/*   Updated: 2019/10/08 10:28:18 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*print(char *name)
{
	ft_putstr("Unknown directory name: ");
	ft_putstr(name);
	ft_putchar('\n');
	return (NULL);
}

char		**ft_find_images_in_dir(char *dir_name, size_t *count)
{
	DIR				*dir;
	struct dirent	*image;
	char			**split;

	if (!(dir = opendir(dir_name)))
		return (print(dir_name));
	split = NULL;
	*count = 0;
	while ((image = readdir(dir)))
		if (image->d_name[0] != '.')
			(*count)++;
	if (*count != 0)
	{
		rewinddir(dir);
		split = ft_memalloc(sizeof(char*) * (*count + 1));
		split[*count] = NULL;
		while ((image = readdir(dir)))
			if (image->d_name[0] != '.')
				split[ft_atoi(image->d_name)] =
					ft_strjoin(dir_name, image->d_name);
	}
	closedir(dir);
	return (split);
}
