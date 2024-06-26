/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:46:43 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/26 12:04:39 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H

# define SOLONG_H

# include <fcntl.h>
# include "../libft/incs/libft.h"

typedef struct s_data
{
	int			xp;
	int			yp;
	int			cp;
	int			xe;
	int			ye;
	int			ce;
	int			ise;
	t_collec	*collecs;	
}				t_data;

t_data	*getmapdata(char **map);

char	**makemap(int fd);

int		checkmap(char **map);

int		getlinedata(char *line, int y, t_data *gamedata, t_collec **clist);

int		checkmapdata(t_data *gamedata);

#endif