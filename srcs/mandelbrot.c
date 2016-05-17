/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 13:49:15 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/17 16:48:22 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void		mandelbrot(t_env *e)
{
	e->f->x = 0;
	while (e->f->x < X_WIN)
	{
		e->f->y = 0;
		while (e->f->y < Y_WIN)
		{
			e->f->c_r = e->f->x / e->param->zoom + e->param->x1;
			e->f->c_i = e->f->y / e->param->zoom + e->param->y1;
			e->f->z_r = 0;
			e->f->z_i = 0;
			e->f->i = 0;
			while ((pow(e->f->z_r, 2) + pow(e->f->z_i, 2)) < 4 && \
					e->f->i < e->param->iter)
			{
				e->f->tmp = e->f->z_r;
				e->f->z_r = pow(e->f->z_r, 2) - pow(e->f->z_i, 2) + e->f->c_r;
				e->f->z_i = 2 * e->f->z_i * e->f->tmp + e->f->c_i;
				e->f->i++;
			}
			put_pixel_to_fractal(e, 0);
			e->f->y++;
		}
		e->f->x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, 0);
}
