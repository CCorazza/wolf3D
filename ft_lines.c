/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 07:53:38 by ccorazza          #+#    #+#             */
/*   Updated: 2014/05/18 19:59:19 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <math.h>

int			ft_check_wall(t_env *e, int x, int y)
{
	int		check;

	check = e->map_col * y + x;
	if (x < 0 || x > e->map_col || y < 0 || y > e->map_line)
		return (1);
	if (e->x < 0 || e->x > e->map_col || e->y < 0 || e->y > e->map_line)
		return (1);
	if (e->map[check] != '0')
		return (1);
	else
		return (0);
}

float		ft_check_x(t_env *env, float dir)
{
	int		x;
	int		y;
	float	delta_x;
	int		delta_y;

	delta_y = (dir > 0) ? 1 : -1;
	delta_x = delta_y / tan(dir);
	x = env->x;
	y = env->y;
	while (!(ft_check_wall(env, x, y)))
	{
		x += delta_x;
		y += delta_y;
	}
	return (sqrt(pow(env->x - x, 2) + pow(env->y - y, 2)));
}

float		ft_check_y(t_env *env, float dir)
{
	int		x;
	int		y;
	float	delta_y;
	int		delta_x;

	delta_x = (dir > 0) ? 1 : -1;
	delta_y = delta_x / tan(dir);
	x = env->x;
	y = env->y;
	while (!(ft_check_wall(env, x, y)))
	{
		x += delta_x;
		y += delta_y;
	}
	return (sqrt(pow(env->x - x, 2) + pow(env->y - y, 2)));
}

float		ft_line(t_env *env, float goal)
{
	float	x_dist;
	float	y_dist;

	x_dist = ft_check_x(env, goal);
	y_dist = ft_check_y(env, goal);
	return (0);
}
