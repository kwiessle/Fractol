/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:30:57 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/18 15:32:00 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "libft.h"
# include "mlx.h"
# include "struct.h"
# include "define.h"

/*
** STRUCTS FUNCTIONS
*/

t_env		*new_env(void);
t_env		*init_env(char *name);
t_img		*init_img(t_env *env);
t_param		*init_param(char *name);
t_frac		*init_frac(char *name);
t_frac		*init_specials(t_frac *f, char *name);
int			param_checker(char *param);

/*
** GRAPHICAL FUNCTIONS
*/

void		mlx_put_pixel_to_image(t_env *env, int x, int y, int color);
void		put_pixel_to_fractal(t_env *env, int color);
void		mandelbrot(t_env *env);
void		julia(t_env *env);
void		burningship(t_env *env);
void		tricorn(t_env *env);
void		chameleon(t_env *env);
void		sword(t_env *env);
void		init_fractals(char *av, t_env *env);

/*
** HOOKS
*/

int			keyboard(int keycode, t_env *env);
void		iterations(int keycode, t_env *env);
int			zoom(int mouse, int x, int y, t_env *env);
void		moove(int keycode, t_env *env);
void		origin(t_env *env);
int			motion(int x, int y, t_env *env);
int			showmenu(t_env *env);

/*
** MENU
*/

int			menu(t_env *env);
void		title(t_env *env);
int			motion_checker(t_env *env);
void		commands(t_env *env);

#endif
