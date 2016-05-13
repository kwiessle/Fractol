/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:37:20 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/12 15:24:34 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_frac		*init_frac(char *name)
{
	t_frac	*fractal;

	if (!(fractal = (t_frac *)malloc(sizeof(t_frac))))
		return (NULL);
	if (ft_strcmp(name, "julia") == 0)
	{
		fractal->c_r = -0.64;
		fractal->c_i = -0.55;
	}
	else
	{
		fractal->c_r = 0;
		fractal->c_i = 0;
	}
	fractal->motion = 1;
	fractal->z_r = 0;
	fractal->z_i = 0;
	fractal->tmp = 0;
	fractal->i = 0;
	fractal->x = 0;
	fractal->y = 0;
	return (fractal);
}

int			init_fractals(char *av, t_env *env)
{
	if (ft_strcmp(av, "mandelbrot") == 0)
	{
		mandelbrot(env);
		return (1);
	}
	if (ft_strcmp(av, "julia") == 0)
	{
		julia(env);
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
