/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:04:23 by smokhtar          #+#    #+#             */
/*   Updated: 2017/11/20 17:10:32 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttable(char **tab)
{
	while (*tab)
	{
		ft_putstr(*tab++);
		ft_putchar('\n');
	}
}
