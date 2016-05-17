/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:32:07 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/17 16:04:47 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		keyboard(int keycode, t_env *env)
{
	if (env->mlx == NULL)
		return (0);
	if (keycode == EXIT)
		exit(EXIT_SUCCESS);
	if (keycode == ITER_MORE || keycode == ITER_LESS)
		iterations(keycode, env);
	if (keycode == RIGHT || keycode == LEFT)
		moove(keycode, env);
	if (keycode == UP || keycode == DOWN)
		moove(keycode, env);
	if (keycode == ORIGIN)
		origin(env);
	if (keycode == MOTION)
		env->f->motion = (env->f->motion == 0) ? 1 : 0;
	mlx_clear_window(env->mlx, env->win);
	init_fractals(env->param->name, env);
	menu(env);
	return (0);
}
