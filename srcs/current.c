#include "fractol.h"

int		motion_checker(t_env *env)
{
	if (env->f->motion % 2 == 1)
	{
		mlx_clear_window(env->mlx, env->win);
		init_fractals(env->param->name, env);
		mlx_string_put(env->mlx, env->win, 20, 15, 0x00FF00, "Motion is ON");
		menu(env);
	}
	else
	{
		mlx_clear_window(env->mlx, env->win);
		init_fractals(env->param->name, env);
		mlx_string_put(env->mlx, env->win, 20, 15, 0xFF0000, "Motion is OFF");
		menu(env);
	}
	return (0);
}
