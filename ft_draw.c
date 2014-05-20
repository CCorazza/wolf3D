/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 16:00:45 by ccorazza          #+#    #+#             */
/*   Updated: 2014/05/18 19:59:50 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <X11/Xlib.h>
#include <libft.h>
#include "wolf.h"

void				ft_put_pixel(t_env *e, int x, int y, unsigned int c)
{
	int				color;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	color = mlx_get_color_value(e->mlx, c);
	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0xFF00) >> 8);
	b = (color & 0xFF);
	if (x > 0 && x < e->map_col && y > 0 && y < e->map_line)
	{
		e->table[(y * e->map_col) + (x * (e->bpp / 8))] = b;
		e->table[(y * e->map_col) + (x * (e->bpp / 8)) + 1] = g;
		e->table[(y * e->map_col) + (x * (e->bpp / 8)) + 2] = r;
	}
}

void				draw_sky(t_env *env, int top)
{
	int				color;
	int				y;

	color = SKY;
	y = HEIGHT / 2;
	while (y <= top)
	{
		ft_put_pixel(env, env->x, y, color);
		y += 1;
	}
}

void				draw_floor(t_env *env, int bottom)
{
	int				color;
	int				y;

	color = FLOOR;
	y = HEIGHT / 2;
	while (y >= bottom)
	{
		ft_put_pixel(env, env->x, y, color);
		y -= 1;
	}
}

void				ft_draw(t_env *env)
{
	int				middle;

	middle = HEIGHT / 2;
	draw_sky(env, HEIGHT);
	draw_floor(env, 0);
	while (env->x <= 150 && env->y < 200)
	{
		ft_put_pixel(env, env->x, env->y, WEST);
		env->x += 1;
		env->y += 1;
	}
}
