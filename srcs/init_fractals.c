/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:37:20 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/11 17:31:27 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init_fractals(char *av, t_env *env)
{
	if (ft_strcmp(av, "mandelbrot") == 0)
	{
		mandelbrot(env);
		return (1);
	}
	if (!av)
		exit(EXIT_SUCCESS);
	else
	{
		ft_putstr("Dis pas de la merde stp\n");
		return (0);
	}
}
