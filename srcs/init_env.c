/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:46:18 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/12 18:35:55 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env	*new_env(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->mlx = NULL;
	env->win = NULL;
	env->img = NULL;
	env->param = NULL;
	env->f = NULL;

	return (env);
}

t_env	*init_env(char *name)
{
	t_env	*env;

	if (!(env = new_env()))
		return (NULL);
	env->mlx = mlx_init();
	env->param = init_param(name);
	env->win = mlx_new_window(env->mlx, X_WIN, Y_WIN, env->param->name);
	env->img = init_img(env);
	env->f = init_frac(name);
	return (env);
}

t_img	*init_img(t_env *env)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	img->img = mlx_new_image(env->mlx, X_WIN - 200, Y_WIN);
	img->data = mlx_get_data_addr(img->img, &img->bpp, \
			&img->size_line, &img->endian);
	return (img);
}

void	mlx_put_pixel_to_image(t_env *env, int x, int y, int color)
{
	int		octet;

	octet = env->img->bpp / 8;
	if (x > 0 && x < X_WIN - 200  && y > 0 && y < Y_WIN)
		ft_memcpy(&env->img->data[octet * (x + env->img->size_line / \
					octet * y)], &color, octet);
}

void	put_pixel_to_fractal(t_env *env, int color)
{

	if (env->f->i == env->param->iter)
		mlx_put_pixel_to_image(env, env->f->x, env->f->y, 0);
	else
	{
		color = env->f->i * env->param->color / env->param->iter;
		mlx_put_pixel_to_image(env, env->f->x, env->f->y, color);
	}
}
