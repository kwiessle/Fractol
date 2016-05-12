/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:36:15 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/11 17:39:44 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iterations(int keycode, t_env *env)
{

	if (keycode == ITER_MORE)
		env->param->iter += 10;
	if (keycode == ITER_LESS)
		env->param->iter -= 10;
//	env->param = new_param(param);
	init_fractals("mandelbrot", env);
}

int		zoom(int mouse, int x, int y, t_env *env)
{
	double	x_comp;
	double	y_comp;

	if (y > 0 && x > 0)
	{
		x_comp = (x / env->param->zoom) + env->param->x1;
		y_comp = (y / env->param->zoom) + env->param->y1;
		if (mouse == 4)
		{
			env->param->zoom *= 1.1;
			env->param->x1 = x_comp - (x / env->param->zoom);
			env->param->y1 = y_comp - (y / env->param->zoom);
			init_fractals("mandelbrot", env);
		}
		if (mouse == 5)
		{
			env->param->zoom /= 1.1;
			env->param->x1 = x_comp - (x / env->param->zoom);
			env->param->y1 = y_comp - (y / env->param->zoom);
			init_fractals("mandelbrot", env);
		}
	}
	return (0);
}
