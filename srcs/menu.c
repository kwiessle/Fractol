/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 16:50:19 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/18 16:37:21 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		menu(t_env *env)
{
	int		x;
	int		y;

	x = 800;
	y = 0;
	while (x <= X_WIN + 200)
	{
		while (y <= Y_WIN + 200)
		{
			if (x == 800 || x == 999)
				mlx_pixel_put(env->mlx, env->win, x, y, M);
			if (x % 10 == 0 && y > 400)
				mlx_pixel_put(env->mlx, env->win, x, y, M);
			if ((y == 0 || y == 230) || (y == 400 || y == 799))
				mlx_pixel_put(env->mlx, env->win, x + 1, y, M);
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
	if (ft_strcmp(title, "JULIA") == 0 || ft_strcmp(title, "SWORD") == 0)
		mlx_string_put(env->mlx, env->win, 875, 20, W, title);
	else
		mlx_string_put(env->mlx, env->win, 850, 20, W, title);
	mlx_string_put(env->mlx, env->win, 810, 250, W, "CURRENT PARAMETERS");
	mlx_string_put(env->mlx, env->win, 815, 190, B, "Motion  :   spc");
}

void	commands(t_env *e)
{
	int		color;

	mlx_string_put(e->mlx, e->win, 815, 70, B, "Move    :  Arrows");
	mlx_string_put(e->mlx, e->win, 815, 90, B, "Iter +  :    s");
	mlx_string_put(e->mlx, e->win, 815, 110, B, "Iter -  :    a");
	mlx_string_put(e->mlx, e->win, 815, 130, B, "Reset   :    r");
	mlx_string_put(e->mlx, e->win, 815, 150, B, "Zoom    :  Scroll");
	mlx_string_put(e->mlx, e->win, 815, 170, B, "Exit    :   Esc");
	if (ft_strcmp(e->param->name, "mandelbrot") != 0 && \
		ft_strcmp(e->param->name, "burningship") != 0 && \
		ft_strcmp(e->param->name, "tricorn") != 0)
	{
		if (e->f->motion == 1)
			mlx_string_put(e->mlx, e->win, 815, 300, G, "Motion  :    ON");
		else
			mlx_string_put(e->mlx, e->win, 815, 300, R, "Motion  :    OFF");
	}
	mlx_string_put(e->mlx, e->win, 815, 320, B, "Iter    :");
	color = (e->param->iter < 2) ? R : G;
	mlx_string_put(e->mlx, e->win, 945, 320, color, ft_itoa(e->param->iter));
	color = (e->param->zoom < 20) ? R : G;
	mlx_string_put(e->mlx, e->win, 815, 340, B, "Zoom    : x");
	mlx_string_put(e->mlx, e->win, 925, 340, color, \
			ft_itoa(e->param->zoom / 100));
}
