/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 12:36:15 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/10 13:23:28 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	iterations(int keycode, t_env *env)
{

	if (keycode == ITER_MORE)
		env->param->iter++;
	if (keycode == ITER_LESS)
		env->param->iter--;
//	env->param = new_param(param);
	init_fractals(NULL, env);
}
