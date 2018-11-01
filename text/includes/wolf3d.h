/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wold3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 22:53:08 by smokhtar          #+#    #+#             */
/*   Updated: 2018/02/20 22:53:39 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <X.h>
# include <stdlib.h>
# include <time.h>

# define W 1920
# define H 1018

# define BL 0x0000FE
# define BC 0xFFF0FF
# define O 0xFF6600
# define RS 0.03 * ptr->sensi

# define P ptr
# define TEST (!i && tab[e][0] == '0') || (i == ptr->map_y && tab[e][0] == '0')
# define T (!e && tab[e][0] == '0') || (e + 1 == ptr->map_x && tab[e][0] == '0')
# define AVANCER (int)(P->posx + P->dirx) + (int)(P->posy + P->diry) * P->map_x
# define RECULER (int)(P->posx - P->dirx) + (int)(P->posy - P->diry) * P->map_x

typedef struct	s_ptr
{
	void		*mlx;
	void		*win;
	void		*p_img;
	int			*i_img;
	int			*map;
	int			i;
	int			map_x;
	int			map_y;
	float		posx;
	float		posy;
	float		dirx;
	float		diry;
	float		camx;
	float		camy;
	float		cam;
	float		raydirx;
	float		raydiry;
	int			mapx;
	int			mapy;
	float		frstdx;
	float		frstdy;
	float		pythadistx;
	float		pythadisty;
	float		perpwd;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			texture;
	int			oldx;
	void		**tex;
	void		*menu;
	int			**i_tex;
	float		wallx;
	int			texx;
	int			t;
	int			m;
	int			block;
	int			acc;
	int			reset;
	float		sensi;
}				t_ptr;

void			menu(t_ptr *ptr);
int				menu_key(int k, t_ptr *ptr);
int				menu_click(int b, int x, int y, t_ptr *ptr);

void			graph(t_ptr *ptr);
int				pars(t_ptr *ptr, char *file);
void			ft_error(int cas, int where);

int				*ft_get_data_addr(void *img);
int				ft_tablen(char **tab);
void			ft_tabdel(char **tab);
int				ft_quit(void);

void			ft_print_1(t_ptr *ptr, int x, int y);

int				ft_turn(int x, int y, t_ptr *ptr);
int				ft_key(int k, t_ptr *ptr);
int				ft_key2(int k, t_ptr *ptr);
#endif
