/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:08:22 by smokhtar          #+#    #+#             */
/*   Updated: 2018/03/02 16:08:23 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_print_2(t_ptr *ptr, int x, int y)
{
	int	d;
	int	ty;

	while (y < ptr->drawstart)
		ptr->i_img[x + y++ * W] = 0x2E4A62;
	while (y < ptr->drawend)
	{
		d = y * 256 - H * 128 + ptr->lineheight * 128;
		ty = ((d * 64) / ptr->lineheight) / 256;
		ptr->i_img[x + y++ * W] = ptr->i_tex[ptr->t - 1][64 * ty + ptr->texx];
	}
	while (y < H)
		ptr->i_img[x + y++ * W] = 0x998066;
}

void		ft_print_1(t_ptr *ptr, int x, int y)
{
	int	d;
	int	ty;

	if (!ptr->m)
		ft_print_2(ptr, x, y);
	else
	{
		while (y < ptr->drawstart)
			ptr->i_img[x + y++ * W] = 0x2E4A62;
		while (y < ptr->drawend)
		{
			d = y * 256 - H * 128 + ptr->lineheight * 128;
			ty = ((d * 64) / ptr->lineheight) / 256;
			if (ptr->side == 1 && ptr->raydiry > 0)
				ptr->i_img[x + y++ * W] = ptr->i_tex[0][64 * ty + ptr->texx];
			else if (ptr->side == 1 && ptr->raydiry < 0)
				ptr->i_img[x + y++ * W] = ptr->i_tex[1][64 * ty + ptr->texx];
			else if (ptr->side == 0 && ptr->raydirx > 0)
				ptr->i_img[x + y++ * W] = ptr->i_tex[2][64 * ty + ptr->texx];
			else if (ptr->side == 0 && ptr->raydirx < 0)
				ptr->i_img[x + y++ * W] = ptr->i_tex[3][64 * ty + ptr->texx];
		}
		while (y < H)
			ptr->i_img[x + y++ * W] = 0x998066;
	}
}
