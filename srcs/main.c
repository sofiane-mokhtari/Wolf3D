/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokhtar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 16:17:22 by smokhtar          #+#    #+#             */
/*   Updated: 2018/03/06 16:17:24 by smokhtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_error(int cas, int where)
{
	if (cas == 1)
		ft_putstr("File error\n");
	else if (cas == 2)
		ft_putstr("Get_next_line error\n");
	else if (cas == 3)
		ft_putstr("Malloc error\n");
	else if (cas == 4)
		ft_putstr("Mlx init error\n");
	else if (cas == 5)
		ft_putstr("Merci de ne pas mettre de fichier chelou en argument\n");
	else if (cas == 6)
		ft_putstr("/dev/random bien tente\n");
	else if (cas == 7)
		ft_putstr("La map n'est pas entoure de mur\n");
	else if (cas == 8)
		ft_putstr("la map est trop petite\n");
	else if (cas == 9)
		ft_putstr("La map n'est pas de la meme longueur partout\n");
	else if (cas == 10)
		ft_putstr("la pos de base est invalide\n");
	ft_putstr("L'erreur a ete trouve au check numero ");
	ft_putnbr(where);
	ft_putstr("\n");
	exit(0);
}

static void	texture(t_ptr *ptr)
{
	int		h;
	int		w;

	ptr->tex[0] = mlx_xpm_file_to_image(ptr->mlx, "text/co.XPM", &h, &w);
	ptr->i_tex[0] = ft_get_data_addr(ptr->tex[0]);
	ptr->tex[1] = mlx_xpm_file_to_image(ptr->mlx, "text/co_mossy.XPM", &h, &w);
	ptr->i_tex[1] = ft_get_data_addr(ptr->tex[1]);
	ptr->tex[2] = mlx_xpm_file_to_image(ptr->mlx, "text/st_mossy.XPM", &h, &w);
	ptr->i_tex[2] = ft_get_data_addr(ptr->tex[2]);
	ptr->tex[3] = mlx_xpm_file_to_image(ptr->mlx, "text/st_crack.XPM", &h, &w);
	ptr->i_tex[3] = ft_get_data_addr(ptr->tex[3]);
	ptr->tex[4] = mlx_xpm_file_to_image(ptr->mlx, "text/n_brick.XPM", &h, &w);
	ptr->i_tex[4] = ft_get_data_addr(ptr->tex[4]);
	ptr->tex[5] = mlx_xpm_file_to_image(ptr->mlx, "text/nr.XPM", &h, &w);
	ptr->i_tex[5] = ft_get_data_addr(ptr->tex[5]);
	ptr->tex[6] = mlx_xpm_file_to_image(ptr->mlx, "text/ss.XPM", &h, &w);
	ptr->i_tex[6] = ft_get_data_addr(ptr->tex[6]);
	ptr->tex[7] = mlx_xpm_file_to_image(ptr->mlx, "text/d_ore.XPM", &h, &w);
	ptr->i_tex[7] = ft_get_data_addr(ptr->tex[7]);
	ptr->tex[8] = mlx_xpm_file_to_image(ptr->mlx, "text/pfon.XPM", &h, &w);
	ptr->i_tex[8] = ft_get_data_addr(ptr->tex[8]);
	ptr->menu = mlx_xpm_file_to_image(ptr->mlx, "text/menu.XPM", &h, &w);
}

static void	ft_start_value(t_ptr *ptr)
{
	ptr->i = -1;
	ptr->m = -1;
	ptr->sensi = 1;
	if (!(ptr->mlx = mlx_init()))
		ft_error(4, 1);
	ptr->dirx = -1;
	ptr->diry = 0;
	ptr->camx = 0;
	ptr->camy = 0.66;
	ptr->oldx = W / 2;
	ptr->tex = (void**)malloc(sizeof(void*) * 9);
	ptr->i_tex = (int**)malloc(sizeof(int*) * 9);
	texture(ptr);
}

int			main(int ac, char **av)
{
	t_ptr	ptr;
	t_ptr	*param;

	param = &ptr;
	if (ac > 2)
		ft_error(1, 0);
	ft_start_value(param);
	param->win = mlx_new_window(param->mlx, W, H, "wolf3d");
	if (ac == 2)
	{
		if (ft_strcmp("/dev/random", av[1]) == 0)
			ft_error(6, 12);
		if (!(ft_strstr(av[1], ".wolf")))
			ft_error(6, 13);
		pars(param, av[1]);
		graph(param);
	}
	else
		menu(param);
}
