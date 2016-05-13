/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:32:07 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/12 17:16:51 by kwiessle         ###   ########.fr       */
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
	(keycode = MOTION) ? env->f->motion++ : 0;
	return (0);
}
