/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 00:10:57 by smokhtar          #+#    #+#             */
/*   Updated: 2018/02/21 00:10:58 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_conv(t_ptr *ptr, char **tab, int i)
{
	int		e;
	int		nb;

	e = 0;
	while (e < ptr->map_x)
	{
		if (ft_isalpha((int)tab[e][0]) == 1)
			ft_error(5, 9);
		nb = ft_atoi(tab[e]);
		if (nb > 9)
			ft_error(6, 19);
		if (TEST || T)
			ft_error(7, 21);
		ptr->map[i * ptr->map_x + e] = ft_atoi(tab[e]);
		e++;
	}
	if (ptr->i != -1 && e != ptr->i)
		ft_error(5, 10);
	ptr->i = e;
}

static int		ft_file(int fd, t_ptr *ptr)
{
	char	*str;
	char	**tmp;
	int		a;
	int		i;
	int		e;

	i = 0;
	e = 0;
	if (!(ptr->map = (int*)malloc(sizeof(int*) * ptr->map_x * ptr->map_y)))
		ft_error(3, 6);
	str = 0;
	while ((a = get_next_line(fd, &str)) > 0)
	{
		if ((int)ft_strlen(str) != ptr->map_x * 2 - 1)
			ft_error(8, 20);
		e += a;
		tmp = ft_strsplit(str, ' ');
		ft_strdel(&str);
		ft_conv(ptr, tmp, i++);
		ft_tabdel(tmp);
	}
	ft_strdel(&str);
	if (a == -1)
		ft_error(2, 7);
	return (e);
}

static int		ft_count(t_ptr *ptr, int fd)
{
	char	**i;
	int		a;
	char	*str;

	if ((a = get_next_line(fd, &str)) > 0)
	{
		if (ft_strlen(str) <= 2)
			ft_error(10, 11);
		i = ft_strsplit(str, ' ');
		free(str);
		str = NULL;
		ptr->map_x = ft_atoi(i[0]);
		ptr->map_y = ft_atoi(i[1]);
		ft_tabdel(i);
	}
	if (a == -1)
		ft_error(2, 5);
	if (ptr->map_y < 3 || ptr->map_x < 3)
		ft_error(8, 16);
	return (0);
}

static int		ft_pos(t_ptr *ptr, int fd)
{
	char	**i;
	int		a;
	char	*str;

	if ((a = get_next_line(fd, &str)) > 0)
	{
		if (ft_strlen(str) <= 2)
			ft_error(5, 11);
		i = ft_strsplit(str, ' ');
		free(str);
		str = NULL;
		if (!(ptr->posx = ft_atoi(i[0])))
			ft_error(10, 17);
		if (!(ptr->posy = ft_atoi(i[1])))
			ft_error(10, 18);
		ft_tabdel(i);
	}
	if (a == -1)
		ft_error(2, 5);
	if (ptr->posy >= ptr->map_y || ptr->posx >= ptr->map_x)
		ft_error(10, 11);
	return (0);
}

int				pars(t_ptr *ptr, char *file)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) <= 0)
		ft_error(1, 2);
	ft_count(ptr, fd);
	ft_pos(ptr, fd);
	if (ptr->map_x <= 1 && ptr->map_y <= 1)
		ft_error(8, 3);
	if (ft_file(fd, ptr) != ptr->map_y)
		ft_error(9, 15);
	close(fd);
	if (ptr->map[(int)ptr->posx + (int)ptr->posy * ptr->map_x] != 0)
		ft_error(10, 12);
	return (1);
}
