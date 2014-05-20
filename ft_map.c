/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 08:10:52 by ccorazza          #+#    #+#             */
/*   Updated: 2014/05/18 16:12:46 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <libft.h>
#include <stdlib.h>
#include "wolf.h"

void		ft_count_columns(t_env *e, char *av)
{
	int		i;
	int		j;
	int		fd;
	char	*line;

	e->map_line = 0;
	e->map_col = 0;
	if ((fd = open(av, O_RDONLY)) == -1)
		exit_gracefully("open: Couldn't read given file.");
	get_next_line(fd, &line);
	e->map_line = ft_atoi(line);
	e->map_col = ft_atoi(line + 3);
	free(line);
	e->map = (char *)ft_xmalloc((e->map_line * e->map_col) + 1);
	i = -1;
	while (get_next_line(fd, &line) && (i < e->map_line * e->map_col))
	{
		j = 0;
		while (line[j])
			e->map[i++] = line[j++];
		free(line);
	}
}
