/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 16:50:19 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/17 16:52:05 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		menu(t_env *env)
{
	int		x;
	int		y;

	x = 800;
	y = 0;
	while (x <= X_WIN)
	{
		while (y <= Y_WIN)
		{
			if (x <= 800)
				mlx_pixel_put(env->mlx, env->win, x, y, 0x98f5ff);
			else
				mlx_pixel_put(env->mlx, env->win, x, y, 0x30FF30);
			y++;
		}
		y = 0;
		x++;
	}
	title(env);
	commands(env);
	return (0);
}

void	title(t_env *env)
{
	char	*title;
	int		i;

	i = 0;
	title = malloc(ft_strlen(env->param->name) + 1);
	while (env->param->name[i])
	{
		title[i] = ft_toupper(env->param->name[i]);
		i++;
	}
	title[i] = '\0';
	if (ft_strcmp(title, "JULIA") == 0)
		mlx_string_put(env->mlx, env->win, 875, 20, 0xffffff, title);
	else
		mlx_string_put(env->mlx, env->win, 850, 20, 0xffffff, title);
	mlx_string_put(env->mlx, env->win, 810, 250, 0xffffff, "CURENT PARAMETERS");
}

void	commands(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 815, 70, 0x98F5FF, "Move    :  Arrows");
	mlx_string_put(e->mlx, e->win, 815, 90, 0x98F5FF, "Iter +  :    s");
	mlx_string_put(e->mlx, e->win, 815, 110, 0x98F5FF, "Iter -  :    a");
	mlx_string_put(e->mlx, e->win, 815, 130, 0x98F5FF, "Reset   :    r");
	mlx_string_put(e->mlx, e->win, 815, 150, 0x98F5FF, "Zoom    :  Scroll");
	mlx_string_put(e->mlx, e->win, 815, 170, 0x98F5FF, "Exit    :   Esc");
	if (ft_strcmp(e->param->name, "mandelbrot") != 0)
	{
		if (e->f->motion == 1)
			mlx_string_put(e->mlx, e->win, 815, 300, G, "Motion  :   ON");
		else
			mlx_string_put(e->mlx, e->win, 815, 300, R, "Motion  :   OFF");
	}
	mlx_string_put(e->mlx, e->win, 815, 320, 0x98f5ff, "Iter    :");
	mlx_string_put(e->mlx, e->win, 950, 320, 0x98f5ff, ft_itoa(e->param->iter));
	mlx_string_put(e->mlx, e->win, 815, 340, 0x98f5ff, "Zoom    :   x");
	mlx_string_put(e->mlx, e->win, 950, 340, 0x98f5ff, ft_itoa(e->param->zoom));
}
