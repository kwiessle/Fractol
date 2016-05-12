/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:48:38 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/12 14:52:05 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		julia(t_env *env)
{
	env->f->x = 0;
	while (env->f->x < X_WIN)
	{
		env->f->y = 0;
		while (env->f->y < Y_WIN)
		{
			env->f->z_r = env->f->x / env->param->zoom + env->param->x1;
			env->f->z_i = env->f->y / env->param->zoom + env->param->y1;
			env->f->i = 0;
			while ((pow(env->f->z_r, 2) + pow(env->f->z_i, 2)) < 4 && env->f->i < env->param->iter)
			{
				env->f->tmp = env->f->z_r;
				env->f->z_r = pow(env->f->z_r, 2) - pow(env->f->z_i, 2) + env->f->c_r;
				env->f->z_i = 2 * env->f->z_i * env->f->tmp + env->f->c_i;
				env->f->i++;
			}
			put_pixel_to_fractal(env, 0);
			env->f->y++;
		}
		env->f->x++;
	}
//	env->f->x = 0;
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
}
