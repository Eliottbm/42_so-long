/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_inputs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:29:42 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/04 14:38:39 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	listen_close(t_data *gdata)
{
	return (mlx_loop_end(gdata->mlx), 0);
}

void	takecol(t_data *gdata)
{
	t_collec	*tmpcol;
	t_collec	*tmpcolpast;

	tmpcol = gdata->lcol;
	while (tmpcol)
	{
		if (tmpcol->xc == gdata->xp && tmpcol->yc == gdata->yp)
		{
			if (tmpcol == gdata->lcol)
				gdata->lcol = tmpcol->next;
			else
				tmpcolpast->next = tmpcol->next;
			free(tmpcol);
			gdata->ccol -= 1;
			break ;
		}
		tmpcolpast = tmpcol;
		tmpcol = tmpcol->next;
	}
	if (gdata->ccol == 0)
	{
		gdata->ise = 1;
		gdata->lcol = NULL;
		replaceimg(gdata, -1, -1, 'E');
	}
}

int	listen_inputs(int key, t_data *gdata)
{
	if (key == 65307)
		return (mlx_loop_end(gdata->mlx), 1);
	if (key == 97 && isdir(gdata, gdata->map[gdata->yp][gdata->xp - 1]))
		replaceimg(gdata, gdata->yp, gdata->xp--, '0');
	else if (key == 119 && isdir(gdata, gdata->map[gdata->yp - 1][gdata->xp]))
		replaceimg(gdata, gdata->yp--, gdata->xp, '0');
	else if (key == 115 && isdir(gdata, gdata->map[gdata->yp + 1][gdata->xp]))
		replaceimg(gdata, gdata->yp++, gdata->xp, '0');
	else if (key == 100 && isdir(gdata, gdata->map[gdata->yp][gdata->xp + 1]))
		replaceimg(gdata, gdata->yp, gdata->xp++, '0');
	else
		return (2);
	gdata->cm += 1;
	ft_printf("total mooves: %d\n", gdata->cm);
	if (gdata->map[gdata->yp][gdata->xp] == 'C')
		takecol(gdata);
	if (gdata->map[gdata->yp][gdata->xp] == 'E')
		return (ft_printf("you won !\n"), mlx_loop_end(gdata->mlx), 0);
	replaceimg(gdata, gdata->yp, gdata->xp, 'P');
	return (0);
}
