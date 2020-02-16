#include "../rubik.h"

void	usage()
{
	ft_printf("./rubik -csvw -rXX -iXX \"SCRAMBLE\"\n\
SCRAMBLE commands:\n\tF R U B L D\ncommand suffix:\n\
\t': turn the other way\n\t2: turn twice\nOptions:\n\
\t-c\tcount number of turn\n\t-s\tsilent mode\n\t-v\tvisual every turn\n\
\t-w\tvisual every step\n\t-rXX\trandom scramble of XX moves\n\t-iXX\t\
infinite random scrambles of XX moves\nXX is 99 maximum\n");
	exit(0);
}

void	init_cube(t_cube *cube)
{
	int i;
	int i2;
	int i3;

	i3 = -1;
	while (++i3 < 6)
	{
		i = -1;
		while (++i < 3)
		{
			i2 = -1;
			while (++i2 < 3)
			{
				i3 == 0 ? cube->bottom[i][i2] = WHITE : 0;
				i3 == 1 ? cube->top[i][i2] = YELLOW : 0;
				i3 == 2 ? cube->front[i][i2] = BLUE : 0;
				i3 == 3 ? cube->back[i][i2] = GREEN : 0;
				i3 == 4 ? cube->left[i][i2] = ORANGE : 0;
				i3 == 5 ? cube->right[i][i2] = RED : 0;
			}
		}
	}
	cube->count = 0;
}

void	lunchAlgo(t_cube *cube)
{
	cube->p.visual ? showCube(cube) : 0;
	solveWhiteCross(cube);
	cube->p.visual == 2 ? showCube(cube) : 0;
	solveWhiteFace(cube);
	cube->p.visual == 2 ? showCube(cube) : 0;
	solveSecondLayer(cube);
	cube->p.visual == 2 ? showCube(cube) : 0;
	solveYellowCross(cube);
	cube->p.visual == 2 ? showCube(cube) : 0;
	solveYellowFace(cube);
	cube->p.visual == 2 ? showCube(cube) : 0;
	orientCorners(cube);
	cube->p.visual == 2 ? showCube(cube) : 0;
	orientMiddle(cube);
	cube->p.visual == 2 ? showCube(cube) : 0;
	checkCube(cube);
	cube->p.count ? ft_printf("nombre de coups: %d\n", cube->count) : 0;
}

int		main(int ac, char **av)
{
	int			i;
	t_cube		cube;

	parser(&cube, av);
	if (ac == 1 || (!av[cube.p.i] && !cube.p.random && !cube.p.infinite))
		usage();
	--cube.p.i;
	while (av[++cube.p.i])
	{
		init_cube(&cube);
		doAlgo(&cube, av[cube.p.i], 0, 0);
		lunchAlgo(&cube);
	}
	if (cube.p.random)
	{
		init_cube(&cube);
		randomScrambler(cube.p.random, &cube);
		lunchAlgo(&cube);
	}
	while (cube.p.infinite)
	{
		init_cube(&cube);
		randomScrambler(cube.p.infinite, &cube);
		lunchAlgo(&cube);
	}
	return (1);
}
