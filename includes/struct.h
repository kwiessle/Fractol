/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:43:16 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/12 20:19:28 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_param
{
	char			*name;
	double			zoom;
	int				iter;
	int				color;
	double			x1;
	double			y1;
	double			zoom_rate;
}					t_param;

typedef struct		s_frac
{
	long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
	long double		tmp;
	int				i;
	int				x;
	int				y;
	int				motion;
}					t_frac;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_param			*param;
	t_frac			*f;
}					t_env;


#endif
