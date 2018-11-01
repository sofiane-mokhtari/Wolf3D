/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 14:08:36 by smokhtar          #+#    #+#             */
/*   Updated: 2018/03/14 14:08:38 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	menu(t_ptr *ptr)
{
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->menu, 0, 0);
	mlx_hook(ptr->win, ButtonPress, ButtonPressMask, menu_click, (void*)ptr);
	mlx_hook(ptr->win, DestroyNotify, NoEventMask, ft_quit, NULL);
	mlx_key_hook(ptr->win, menu_key, (void*)ptr);
	mlx_loop(ptr->mlx);
}
