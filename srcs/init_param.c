/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 13:00:17 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/11 17:46:30 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_param		*init_param(void)
{
	t_param		*param;

	if (!(param = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	param->zoom = 300;
	param->iter = 100;
//	param->color = 0xF4EF7B;
	param->color = 0x45DF44;
	param->xo = 0;
	param->yo = 0;
	param->x1 = -2.1;
	param->y1 = -1.2;
	return (param);
}
/*
t_param		new_param(t_param new)
{

}*/
