/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dirs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:48:01 by ebengtss          #+#    #+#             */
/*   Updated: 2024/07/04 14:33:57 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int	isdir(t_data *gdata, char pos)
{
	if (pos == '1' || (pos == 'E' && gdata->ise == 0))
		return (0);
	return (1);
}
