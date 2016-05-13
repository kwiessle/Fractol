/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:00:17 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/12 20:28:08 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_param		*init_param(char *name)
{
	t_param		*param;

	if (!(param = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	param->name = name;
	if (ft_strcmp(name, "mandelbrot") == 0)
		param->zoom = 300;
	else
		param->zoom = 200;
	param->iter = 36;
	param->color = 0xfefefe;
	if (ft_strcmp(name, "mandelbrot") == 0)
	{
		param->x1 = -2.1;
		param->y1 = -1.2;
	}
	else
	{
		param->x1 = -2.0;
		param->y1 = -2.0;
	}
	param->zoom_rate = 0.1;
	return (param);
}
