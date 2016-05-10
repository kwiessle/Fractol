/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:48:38 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/09 15:49:00 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.c"

void		julia(t_env *env)
{
	long double		z_r;
	long double		z_i;
	long double		tmp;
	int				i;
	int				x;
	int				y;
	int				color;

	x = 0;
	while (x < X_WIN)
	{
		y = 0;
		while (y < Y_WIN)
		{
			z_r = (x - X_WIN / 2) / (ZOOM + X2)
			z_i = (y - Y_WIN / 2) / (ZOOM + Y2)
			i = -1;
			while ((z_r * z_r + z_i * z_i) < 4 && i++ < 50)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + 0.285;
				z_i = 2 * z_i * tmp + 0.01;
			}
			if (i == 50)
				mlx_put_pixel_to_image(env, x, y,);
		}
	}
}
