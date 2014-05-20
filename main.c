/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 08:10:06 by ccorazza          #+#    #+#             */
/*   Updated: 2014/05/18 19:59:59 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mlx.h>
#include <X11/Xlib.h>
#include "wolf.h"

int			ft_keypress(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit_gracefully("You exited the program");
	mlx_clear_window(e->mlx, e->win);
	ft_draw(e);
	return (0);
}

int			ft_exposehook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int			main(int ac, char **av)
{
	t_env	e;

	if (ac == 2 && av)
	{
		if (!(e.mlx = mlx_init()))
			exit_gracefully("mlx_init: Connexion to Xserver failed.");
		if (!(e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "Wolf3D")))
			exit_gracefully("mlx_new_window: Could not create window.");
		if (!(e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT)))
			exit_gracefully("mlx_new_image: Could not create image.");
		if (!(e.table = mlx_get_data_addr(e.img, &e.bpp, &e.size, &e.endian)))
			exit_gracefully("mlx_get_data_addr: Could not read data.");
		ft_count_columns(&e, av[1]);
		e.x = e.map_line / 2;
		e.y = e.map_col / 2;
		ft_line(&e, 1.2);
		ft_draw(&e);
		mlx_expose_hook(e.win, &ft_exposehook, &e);
		mlx_hook(e.win, KeyPress, KeyPressMask, &ft_keypress, &e);
		mlx_loop(e.mlx);
	}
	else
		exit_gracefully("\033[33mUsage : ./wolf3d <map.name>\033[0m");
	return (0);
}
