/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:06:17 by smokhtar          #+#    #+#             */
/*   Updated: 2018/03/02 16:06:18 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		menu_click(int b, int x, int y, t_ptr *ptr)
{
	b = 0;
	if (x > 662 && x < 1260 && ptr->m == -1)
	{
		if (y > 400 && y < 450)
		{
			ptr->m = 1;
			pars(ptr, "map/map1.wolf");
			graph(ptr);
		}
		else if (y > 475 && y < 532)
		{
			ptr->m = 0;
			pars(ptr, "map/map2.wolf");
			graph(ptr);
		}
		else if (y > 547 && y < 604)
		{
			ptr->m = 0;
			pars(ptr, "map/map3.wolf");
			graph(ptr);
		}
		else if (y > 656 && y < 711)
			ft_quit();
	}
	return (0);
}

int		menu_key(int k, t_ptr *ptr)
{
	(void)ptr;
	if (k == 53)
		exit(0);
	return (0);
}

int		ft_turn(int x, int y, t_ptr *ptr)
{
	float	olddir;
	float	oldcam;

	y = 0;
	olddir = ptr->dirx;
	oldcam = ptr->camx;
	if (x > ptr->oldx)
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
	ptr->oldx = x;
	graph(ptr);
	return (0);
}

int		ft_key(int k, t_ptr *ptr)
{
	(void)ptr;
	if (k == 53)
		exit(0);
	else if (k == 126)
	{
		ptr->sensi += 0.5;
	}
	else if (k == 125)
	{
		ptr->sensi -= 0.5;
		if (ptr->sensi <= 0)
			ptr->sensi += 0.5;
	}
	return (0);
}
