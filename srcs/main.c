/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:41:50 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/12 11:54:01 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_env		*env;

	(void)ac;
	env = init_env(av[1]);

	if(!(init_fractals(env->param->name, env)))
		exit(EXIT_SUCCESS);
	mlx_mouse_hook(env->win, zoom, env);
//	mlx_mouse_hook(env->win, zoom, env);
	mlx_hook(env->win, 2, 3, keyboard, env);
//	mlx_mouse_hook(env->win, zoom, env);
	mlx_loop(env->mlx);
	return (0);
}
