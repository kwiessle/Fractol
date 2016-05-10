/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:30:57 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/10 13:18:52 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include "struct.h"
# include "define.h"

/* STRUCTS FUNCTIONS */

t_env		*new_env(void);
t_env		*init_env(void);
t_img		*init_img(t_env *env);
t_param		*init_param(void);

/* GRAPHICAL FUNCTIONS */

void	mlx_put_pixel_to_image(t_env *env, int x, int y, int color);
void	mandelbrot(t_env *env);
int		init_fractals(char *av, t_env *env);

/* HOOKS */

int		keyboard(int keycode, t_env *env);
void	iterations(int keycode, t_env *env);


#endif
