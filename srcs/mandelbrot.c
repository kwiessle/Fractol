/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 13:49:15 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/11 17:44:35 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void		mandelbrot(t_env *env)
{
	long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
	int				i;
	int				x;
	int				y;
	long double		tmp;
	int				color;

//	color = 0xFF00FF;
	x = 0;
	while (x < X_WIN)
	{
		y = 0;
		while (y < Y_WIN)
		{
			c_r = x / env->param->zoom + env->param->x1;
			c_i = y / env->param->zoom + env->param->y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while ((z_r * z_r + z_i * z_i) < 4 && i < env->param->iter)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == env->param->iter)
				mlx_put_pixel_to_image(env, x, y, 0);
			else
			{
				color = i * env->param->color / env->param->iter;
				mlx_put_pixel_to_image(env, x, y, color);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
}
