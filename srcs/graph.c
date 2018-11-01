/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:17:31 by smokhtar          #+#    #+#             */
/*   Updated: 2018/03/06 16:17:32 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		try_to_hit(t_ptr *ptr, int stepx, int stepy)
{
	ptr->hit = 0;
	while (!ptr->hit)
	{
		if (ptr->frstdx < ptr->frstdy)
		{
			ptr->frstdx += ptr->pythadistx;
			ptr->mapx += stepx;
			ptr->side = 0;
		}
		else
		{
			ptr->frstdy += ptr->pythadisty;
			ptr->mapy += stepy;
			ptr->side = 1;
		}
		if ((ptr->t = ptr->map[ptr->mapx + ptr->mapy * ptr->map_x]) > 0)
			ptr->hit = 1;
	}
	if (ptr->side == 0)
		P->perpwd = (P->mapx - P->posx + (1 - stepx) / 2) / P->raydirx;
	else
		P->perpwd = (P->mapy - P->posy + (1 - stepy) / 2) / P->raydiry;
	ptr->lineheight = (int)(H / ptr->perpwd);
	ptr->drawstart = -ptr->lineheight / 2 + H / 2;
}

static void		find_step(t_ptr *ptr)
{
	int		stepx;
	int		stepy;

	if (ptr->raydirx < 0)
	{
		stepx = -1;
		ptr->frstdx = (ptr->posx - ptr->mapx) * ptr->pythadistx;
	}
	else
	{
		stepx = 1;
		ptr->frstdx = (ptr->mapx + 1.0 - ptr->posx) * ptr->pythadistx;
	}
	if (ptr->raydiry < 0)
	{
		stepy = -1;
		ptr->frstdy = (ptr->posy - ptr->mapy) * ptr->pythadisty;
	}
	else
	{
		stepy = 1;
		ptr->frstdy = (ptr->mapy + 1.0 - ptr->posy) * ptr->pythadisty;
	}
	try_to_hit(ptr, stepx, stepy);
}

static void		calcul(t_ptr *ptr, int x)
{
	ptr->cam = 2 * x / (float)W - 1;
	ptr->raydirx = ptr->dirx + ptr->camx * ptr->cam;
	ptr->raydiry = ptr->diry + ptr->camy * ptr->cam;
	ptr->mapx = (int)ptr->posx;
	ptr->mapy = (int)ptr->posy;
	ptr->pythadistx = fabs(1 / ptr->raydirx);
	ptr->pythadisty = fabs(1 / ptr->raydiry);
	find_step(ptr);
	if (ptr->drawstart < 0)
		ptr->drawstart = 0;
	ptr->drawend = ptr->lineheight / 2 + H / 2;
	if (ptr->drawend >= H)
		ptr->drawend = H - 1;
	if (ptr->side == 0)
		ptr->wallx = ptr->posy + ptr->perpwd * ptr->raydiry;
	else
		ptr->wallx = ptr->posx + ptr->perpwd * ptr->raydirx;
	ptr->wallx -= floor((ptr->wallx));
	ptr->texx = (int)(ptr->wallx * 64.0);
	ft_print_1(ptr, x, 0);
}

void			graph(t_ptr *ptr)
{
	int		x;

	x = -1;
	ptr->p_img = mlx_new_image(ptr->mlx, W, H);
	ptr->i_img = ft_get_data_addr(ptr->p_img);
	while (++x < W)
		calcul(ptr, x);
	mlx_clear_window(ptr->mlx, ptr->win);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->p_img, 0, 0);
	mlx_destroy_image(ptr->mlx, ptr->p_img);
	mlx_key_hook(ptr->win, ft_key, (void*)ptr);
	mlx_hook(ptr->win, MotionNotify, PointerMotionMask, ft_turn, (void*)ptr);
	mlx_hook(ptr->win, DestroyNotify, NoEventMask, ft_quit, NULL);
	mlx_hook(ptr->win, KeyPress, KeyPressMask, ft_key2, (void*)ptr);
	mlx_loop(ptr->mlx);
	exit(0);
}
