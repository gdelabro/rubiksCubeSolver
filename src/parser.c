#include "../rubik.h"

void	init_parser(t_cube *cube)
{
	cube->p.silent = 0;
	cube->p.infinite = 0;
	cube->p.random = 0;
	cube->p.count = 0;
	cube->p.visual = 0;
	cube->p.stat = 0;
	cube->p.i = 0;
	cube->countall = 0;
	cube->lowestcount = 1000;
	cube->biggestcount = 0;
	cube->cubeNumber = 0;
}

void	parser(t_cube *cube, char **av)
{
	int		i;
	char	c;

	init_parser(cube);
	while (av[++cube->p.i] && av[cube->p.i][0] == '-')
	{
		if (!ft_strcmp("--", av[cube->p.i]) && ++cube->p.i)
			break ;
		if (av[cube->p.i][1] == 'r' || av[cube->p.i][1] == 'i')
		{
			av[cube->p.i][1] == 'r' ? cube->p.random = 0 : 0;
			av[cube->p.i][1] == 'i' ? cube->p.infinite = 0 : 0;
			i = 1;
			while (av[cube->p.i][++i])
			{
				if (av[cube->p.i][i] < '0' || av[cube->p.i][i] > '9')
					usage();
				av[cube->p.i][1] == 'r' ? cube->p.random =
					cube->p.random * 10 + av[cube->p.i][i] - '0' : 0;
				av[cube->p.i][1] == 'i' ? cube->p.infinite =
					cube->p.infinite * 10 + av[cube->p.i][i] - '0' : 0;
			}
		}
		else
		{
			i = 0;
			while (av[cube->p.i][++i])
			{
				c = av[cube->p.i][i];
				if (c != 'c' && c != 's' && c != 'v' && c != 'w' && c != 't')
					usage();
				c == 'c' ? cube->p.count = 1 : 0;
				c == 's' ? cube->p.silent = 1 : 0;
				c == 'v' ? cube->p.visual = 1 : 0;
				c == 'w' ? cube->p.visual = 2 : 0;
				c == 't' ? cube->p.stat = 1 : 0;
			}
		}
	}
	cube->p.stat && !cube->p.infinite ? cube->p.infinite = 20 : 0;
}
