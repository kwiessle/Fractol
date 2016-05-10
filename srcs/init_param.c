/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:00:17 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/10 14:51:03 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_param		*init_param(void)
{
	t_param		*param;

	if (!(param = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	param->zoom = ZOOM;
	param->iter = 100;
	param->color = 0xfafafa;
	param->xo = 0;
	param->yo = 0;
	return (param);
}
/*
t_param		new_param(t_param new)
{

}*/
