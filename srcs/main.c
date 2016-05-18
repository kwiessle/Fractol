/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:41:50 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/18 14:55:09 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		param_checker(char *param)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(char) * 7);
	tab[0] = "mandelbrot";
	tab[1] = "burningship";
	tab[2] = "sword";
	tab[3] = "chameleon";
	tab[4] = "tricorn";
	tab[5] = "julia";
	tab[6] = 0;
	while (tab[i])
	{
		if (ft_strcmp(param, tab[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_env		*env;

	(void)ac;
	if (ac != 2 || param_checker(av[1]) == 0)
	{
		ft_putstr("usage : launch <./fractol> with one of this names\n \
		- julia\n \
		- mandelbrot\n		- burningship\n		- sword\n \
		- chameleon\n		- tricorn\n");
		return (0);
	}
	env = init_env(av[1]);
	menu(env);
	init_fractals(env->param->name, env);
	mlx_mouse_hook(env->win, zoom, env);
	mlx_hook(env->win, 6, 1L << 6, motion, env);
	mlx_hook(env->win, 2, 3, keyboard, env);
	mlx_loop(env->mlx);
	return (0);
}
