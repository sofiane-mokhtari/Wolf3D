/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bordel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 22:46:37 by smokhtar          #+#    #+#             */
/*   Updated: 2018/02/21 22:46:39 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		*ft_get_data_addr(void *img)
{
	int		bpp;
	int		s_l;
	int		endian;

	return ((int*)mlx_get_data_addr(img, &(bpp), &(s_l), &(endian)));
}

int		ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_tabdel(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	free(tab);
	tab = NULL;
}

int		ft_quit(void)
{
	exit(0);
}
