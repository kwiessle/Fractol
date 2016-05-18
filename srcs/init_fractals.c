/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:37:20 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/18 14:31:13 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_frac		*init_frac(char *name)
{
	t_frac	*fractal;

	if (!(fractal = (t_frac *)malloc(sizeof(t_frac))))
		return (NULL);
	fractal->c_r = 0;
	fractal->c_i = 0;
	fractal = init_specials(fractal, name);
	fractal->motion = 0;
	fractal->menu = 0;
	fractal->z_r = 0;
	fractal->z_i = 0;
	fractal->tmp = 0;
	fractal->i = 0;
	fractal->x = 0;
	fractal->y = 0;
	return (fractal);
}

t_frac		*init_specials(t_frac *f, char *name)
{
	if (ft_strcmp(name, "sword") == 0)
	{
		f->c_r = -1.47;
		f->c_i = 0;
	}
	if (ft_strcmp(name, "chameleon") == 0)
	{
		f->c_r = -0.85;
		f->c_i = 0;
	}
	if (ft_strcmp(name, "julia") == 0)
	{
		f->c_r = -0.74;
		f->c_i = 0.14;
	}

	return (f);
}

void			init_fractals(char *av, t_env *env)
{
	if (ft_strcmp(av, "mandelbrot") == 0)
		mandelbrot(env);
	if (ft_strcmp(av, "julia") == 0)
		julia(env);
	if (ft_strcmp(av, "burningship") == 0)
		burningship(env);
	if (ft_strcmp(av, "tricorn") == 0)
		tricorn(env);
	if (ft_strcmp(av, "chameleon") == 0)
		chameleon(env);
	if (ft_strcmp(av, "sword") == 0)
		sword(env);
}
