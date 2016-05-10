/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 11:43:16 by kwiessle          #+#    #+#             */
/*   Updated: 2016/05/10 14:31:24 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_param
{
	int				zoom;
	int				iter;
	int				xo;
	int				yo;
	int				color;
}					t_param;

typedef struct		s_coord
{
	int				x;
	int				y;
	struct s_coord	*next;
}					t_coord;

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
}					t_env;


#endif
