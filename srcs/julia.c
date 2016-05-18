/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:48:38 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/18 14:09:27 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia(t_env *e)
{
	e->f->x = 0;
	while (e->f->x < X_WIN)
	{
		e->f->y = 0;
		while (e->f->y < Y_WIN)
		{
			e->f->z_r = e->f->x / e->param->zoom + e->param->x1;
			e->f->z_i = e->f->y / e->param->zoom + e->param->y1;
			e->f->i = 0;
			while ((pow(e->f->z_r, 2) + pow(e->f->z_i, 2)) < 4 && \
					e->f->i < e->param->iter)
			{
				e->f->tmp = e->f->z_r;
				e->f->z_r = pow(e->f->z_r, 2) - pow(e->f->z_i, 2) + e->f->c_r;
				e->f->z_i = 2 * e->f->z_i * e->f->tmp + e->f->c_i;
				e->f->i++;
			}
			put_pixel_to_fractal(e, 0xf4d533);
			e->f->y++;
		}
		e->f->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
}

void		chameleon(t_env *e)
{
	e->f->x = 0;
	while (e->f->x < X_WIN)
	{
		e->f->y = 0;
		while (e->f->y < Y_WIN)
		{
			e->f->z_r = e->f->x / e->param->zoom + e->param->x1;
			e->f->z_i = e->f->y / e->param->zoom + e->param->y1;
			e->f->i = 0;
			while ((pow(e->f->z_r, 2) + pow(e->f->z_i, 2)) < 4 && \
					e->f->i < e->param->iter)
			{
				e->f->tmp = e->f->z_r;
				e->f->z_r = pow(e->f->z_r, 2) - pow(e->f->z_i, 2) + e->f->c_r;
				e->f->z_i = -2 * e->f->z_i * e->f->tmp + e->f->c_i;
				e->f->i++;
			}
			put_pixel_to_fractal(e, 0xf4d533);
			e->f->y++;
		}
		e->f->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
}

void		sword(t_env *e)
{
	e->f->x = 0;
	while (e->f->x < X_WIN)
	{
		e->f->y = 0;
		while (e->f->y < Y_WIN)
		{
			e->f->z_r = e->f->x / e->param->zoom + e->param->x1;
			e->f->z_i = e->f->y / e->param->zoom + e->param->y1;
			e->f->i = 0;
			while ((pow(e->f->z_r, 2) + pow(e->f->z_i, 2)) < 4 && \
					e->f->i < e->param->iter)
			{
				e->f->tmp = e->f->z_r;
				e->f->z_r = fabsl(pow(e->f->z_r, 2) - pow(e->f->z_i, 2) + e->f->c_r);
				e->f->z_i = fabsl(-2 * e->f->z_i * e->f->tmp + e->f->c_i);
				e->f->i++;
			}
			put_pixel_to_fractal(e, 0xf4d533);
			e->f->y++;
		}
		e->f->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
}
