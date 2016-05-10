/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:41:50 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/10 13:01:28 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_env		*env;

	(void)ac;
	env = init_env();

	if(!(init_fractals(av[1], env)))
		exit(EXIT_SUCCESS);
	mlx_hook(env->win, 2, 3, keyboard, env);
	mlx_loop(env->mlx);
	return (0);
}
