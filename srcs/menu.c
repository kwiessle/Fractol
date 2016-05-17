#include "fractol.h"


int		menu(t_env *env)
{
	int		x;
	int		y;

	x = 800;
	y = 0;

	while (x <= X_WIN)
	{
		while (y <= Y_WIN)
		{
			if (x <= 800)
				mlx_pixel_put(env->mlx, env->win, x, y, 0x98f5ff);
			else
				mlx_pixel_put(env->mlx, env->win, x, y, 0x151515);
			y++;
		}
		y = 0;
		x++;
	}
	title(env);
	commands(env);
	return (0);
}

void	title(t_env *env)
{
	char	*title;
	int		i;

	i = 0;
	title = malloc(ft_strlen(env->param->name) + 1);
	while (env->param->name[i])
	{
		title[i] = ft_toupper(env->param->name[i]);
		i++;
	}
	title[i] = '\0';
	if (ft_strcmp(title, "JULIA") == 0)
		mlx_string_put(env->mlx, env->win, 865, 20, 0x98F5FF, title);
	else
		mlx_string_put(env->mlx, env->win, 850, 20, 0x98F5FF, title);
}

void	commands(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 815, 70, 0x98F5FF, "Move    :  Arrows");
	mlx_string_put(env->mlx, env->win, 815, 90, 0x98F5FF, "Iter +  :    s");
	mlx_string_put(env->mlx, env->win, 815, 110, 0x98F5FF, "Iter -  :    a");
	mlx_string_put(env->mlx, env->win, 815, 130, 0x98F5FF, "Reset   :    r");
}
