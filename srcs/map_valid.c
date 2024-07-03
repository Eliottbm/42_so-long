/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:17:29 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/03 11:55:41 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	testmap(t_checkdata *tmpdata, int x, int y)
{
	if (tmpdata->map[y][x] == '1' || tmpdata->map[y][x] == 'x')
		return (0);
	if (tmpdata->map[y][x] == 'E')
		return (tmpdata->ise = 1, 0);
	if (tmpdata->map[y][x] == 'C')
		tmpdata->mcol += 1;
	if (tmpdata->ise == 1 && tmpdata->mcol == tmpdata->ccol)
		return (tmpdata->isf = 0);
	tmpdata->map[y][x] = 'x';
	testmap(tmpdata, x + 1, y);
	testmap(tmpdata, x - 1, y);
	testmap(tmpdata, x, y + 1);
	testmap(tmpdata, x, y - 1);
	return (tmpdata->isf);
}

char	**clonemap(char **map)
{
	char	**tmpmap;
	int		i;

	i = 0;
	while (map[i])
		i++;
	tmpmap = malloc(sizeof(char *) * (i + 1));
	if (!tmpmap)
		return (NULL);
	i = 0;
	while (map[i])
	{
		tmpmap[i] = ft_strdup(map[i]);
		i++;
	}
	tmpmap[i] = NULL;
	return (tmpmap);
}

t_checkdata	*clonestruct(t_data *gdata)
{
	t_checkdata	*tmpgdata;

	tmpgdata = malloc(sizeof(t_checkdata));
	if (!tmpgdata)
		return (NULL);
	tmpgdata->ccol = gdata->ccol;
	tmpgdata->mcol = 0;
	tmpgdata->ise = 0;
	tmpgdata->isf = 1;
	tmpgdata->map = clonemap(gdata->map);
	if (!tmpgdata->map)
		return (free(tmpgdata), NULL);
	return (tmpgdata);
}

void	ft_freemap(char **tmpmap)
{
	size_t	i;

	i = 0;
	if (*tmpmap)
	{
		while (tmpmap[i])
		{
			free(tmpmap[i]);
			i++;
		}
		free(tmpmap);
	}
}

int	ismapvalid(t_data *gdata)
{
	t_checkdata	*tmpgdata;

	tmpgdata = clonestruct(gdata);
	if (!tmpgdata)
		return (ft_putstr_fd("Error\nmap cloning map\n", 2), 1);
	if (testmap(tmpgdata, gdata->xp, gdata->yp))
	{
		ft_freemap(tmpgdata->map);
		free(tmpgdata);
		return (ft_putstr_fd("Error\nmap cant be finished\n", 2), 1);
	}
	ft_freemap(tmpgdata->map);
	free(tmpgdata);
	return (0);
}
