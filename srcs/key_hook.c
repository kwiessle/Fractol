/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:36:15 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/12 17:19:43 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iterations(int keycode, t_env *env)
{

	if (keycode == ITER_MORE)
		env->param->iter += 1;
	if (keycode == ITER_LESS)
		env->param->iter -= 1;
	mlx_clear_window(env->mlx, env->win);
	init_fractals(env->param->name, env);
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
			mlx_clear_window(env->mlx, env->win);
			init_fractals(env->param->name, env);
		}
		if (mouse == 5)
		{
			env->param->zoom /= 1.1;
			env->param->x1 = x_comp - (x / env->param->zoom);
			env->param->y1 = y_comp - (y / env->param->zoom);
			mlx_clear_window(env->mlx, env->win);
			init_fractals(env->param->name, env);
		}
	}
	return (0);
}

void	moove(int keycode, t_env *env)
{
	if (keycode == RIGHT)
		env->param->x1 -= 0.01;
	if (keycode == LEFT)
		env->param->x1 += 0.01;
	if (keycode == UP)
		env->param->y1 -= 0.01;
	if (keycode == DOWN)
		env->param->y1 += 0.01;
	mlx_clear_window(env->mlx, env->win);
	init_fractals(env->param->name, env);
}

void	origin(t_env *env)
{
			env->param = init_param(env->param->name);
			mlx_clear_window(env->mlx, env->win);
			init_fractals(env->param->name, env);
}
