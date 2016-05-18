/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:36:15 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/18 16:51:41 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iterations(int keycode, t_env *env)
{
	if (keycode == ITER_MORE)
		env->param->iter += 1;
	if (keycode == ITER_LESS)
		env->param->iter -= 1;
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
		}
		if (mouse == 5)
		{
			env->param->zoom /= 1.1;
			env->param->x1 = x_comp - (x / env->param->zoom);
			env->param->y1 = y_comp - (y / env->param->zoom);
		}
		mlx_clear_window(env->mlx, env->win);
		init_fractals(env->param->name, env);
		menu(env);
	}
	return (0);
}

void	moove(int keycode, t_env *env)
{
	if (env->param->zoom >= 300)
		env->param->zoom_rate = 0.01;
	if (env->param->zoom >= 360)
		env->param->zoom_rate = 0.001;
	if (keycode == RIGHT)
		env->param->x1 -= env->param->zoom_rate;
	if (keycode == LEFT)
		env->param->x1 += env->param->zoom_rate;
	if (keycode == UP)
		env->param->y1 -= env->param->zoom_rate;
	if (keycode == DOWN)
		env->param->y1 += env->param->zoom_rate;
}

void	origin(t_env *env)
{
	env->param = init_param(env->param->name);
	env->f = init_frac(env->param->name);
}

int		motion(int x, int y, t_env *env)
{
	if (env->f->motion % 2 == 1)
	{
		if (x > 0 && x <= X_WIN && y > 0 && y <= Y_WIN)
		{
			if (x < X_WIN / 2 && y < Y_WIN)
				env->f->c_r += 0.05;
			if (x > X_WIN / 2 && y < Y_WIN)
				env->f->c_r -= 0.05;
			if (x > X_WIN / 2 && y > Y_WIN)
				env->f->c_i += 0.05;
			if (x < X_WIN / 2 && y > Y_WIN)
				env->f->c_i -= 0.05;
		}
		mlx_clear_window(env->mlx, env->win);
		init_fractals(env->param->name, env);
		menu(env);
	}
	return (0);
}
