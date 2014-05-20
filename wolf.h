/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 07:23:53 by ccorazza          #+#    #+#             */
/*   Updated: 2014/05/18 17:35:51 by ccorazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <sys/types.h>

# define MAX_FOV 1024
# define HEIGHT 600
# define WIDTH 840
/*
** Having chosen a 60 degree angle, one column ACOL = 60 / 840
*/
# define ACOL 0.14286
# define SKY 0xFFFBE0
# define FLOOR 0xF8DEBD
# define NORTH 0xDF818F
# define SOUTH 0xFF7C65
# define WEST 0xE2756E
# define EAST 0xFD8EB8

# define ABS(a) ((a < 0) ? (-(a)) : (a))

typedef struct		s_env
{
	char			*map;
	char			*table;
	float			x;
	float			y;
	int				bpp;
	int				endian;
	int				size;
	int				map_col;
	int				map_line;
	void			*img;
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_coord
{
	float			x;
	float			y;
}					t_coord;

float				ft_line(t_env *env, float goal);
float				ft_way(t_env *e, int x, int y);
int					ft_check_wall(t_env *e, int x, int y);
int					ft_exposehook(t_env *e);
int					ft_keypress(int keycode, t_env *e);
int					key_hook(int keycode, t_env *e);
void				*ft_xmalloc(size_t size);
void				draw_floor(t_env *e, int bottom);
void				draw_sky(t_env *e, int top);
void				exit_gracefully(char *s);
void				ft_count_columns(t_env *e, char *av);
void				ft_draw(t_env *env);
void				ft_put_pixel(t_env *e, int x, int y, unsigned int c);

#endif