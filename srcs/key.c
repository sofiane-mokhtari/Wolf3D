/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:18:27 by smokhtar          #+#    #+#             */
/*   Updated: 2018/03/06 22:31:23 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		left(t_ptr *ptr, double px, double py)
{
	if (ptr->dirx <= -0.5)
	{
		px = ptr->posx + 0.5;
		py = ptr->posy - 0.5;
	}
	else if (ptr->dirx >= 0.5)
	{
		px = ptr->posx - 0.5;
		py = ptr->posy + 0.5;
	}
	else if (ptr->diry <= -0.5)
	{
		px = ptr->posx + 0.5;
		py = ptr->posy + 0.5;
	}
	else
	{
		px = ptr->posx - 0.5;
		py = ptr->posy - 0.5;
	}
	if (!(ptr->map[(int)(px) + (int)(py) * ptr->map_x]))
	{
		ptr->posx = px;
		ptr->posy = py;
	}
}

static void		right(t_ptr *ptr, double px, double py)
{
	if (ptr->dirx <= -0.5)
	{
		px = ptr->posx + 0.5;
		py = ptr->posy + 0.5;
	}
	else if (ptr->dirx >= 0.5)
	{
		px = ptr->posx - 0.5;
		py = ptr->posy - 0.5;
	}
	else if (ptr->diry <= -0.5)
	{
		px = ptr->posx - 0.5;
		py = ptr->posy + 0.5;
	}
	else
	{
		px = ptr->posx + 0.5;
		py = ptr->posy - 0.5;
	}
	if (!(ptr->map[(int)(px) + (int)(py) * ptr->map_x]))
	{
		ptr->posx = px;
		ptr->posy = py;
	}
}

static	void	ft_turn_2(int k, t_ptr *ptr)
{
	float	olddir;
	float	oldcam;

	olddir = ptr->dirx;
	oldcam = ptr->camx;
	if (k == 14)
	{
		ptr->dirx = ptr->dirx * cos(-RS) - ptr->diry * sin(-RS);
		ptr->diry = olddir * sin(-RS) + ptr->diry * cos(-RS);
		ptr->camx = ptr->camx * cos(-RS) - ptr->camy * sin(-RS);
		ptr->camy = oldcam * sin(-RS) + ptr->camy * cos(-RS);
	}
	else
	{
		ptr->dirx = ptr->dirx * cos(RS) - ptr->diry * sin(RS);
		ptr->diry = olddir * sin(RS) + ptr->diry * cos(RS);
		ptr->camx = ptr->camx * cos(RS) - ptr->camy * sin(RS);
		ptr->camy = oldcam * sin(RS) + ptr->camy * cos(RS);
	}
}

int				ft_key2(int k, t_ptr *ptr)
{
	if (k == 13 && !(ptr->map[AVANCER]))
	{
		ptr->posx += ptr->dirx / 2;
		ptr->posy += ptr->diry / 2;
	}
	else if (k == 1 && !(ptr->map[RECULER]))
	{
		ptr->posx -= ptr->dirx / 2;
		ptr->posy -= ptr->diry / 2;
	}
	else if (k == 2)
		right(ptr, 0, 0);
	else if (k == 0)
		left(ptr, 0, 0);
	else if (k == 12 || k == 14)
		ft_turn_2(k, ptr);
	graph(ptr);
	return (0);
}
