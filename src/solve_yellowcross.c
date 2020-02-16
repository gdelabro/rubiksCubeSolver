#include "../rubik.h"

int		numberYellowPiece(t_cube *cube)
{
	int		c;

	c = 0;
	cube->top[0][1] == YELLOW ? c++ : 0;
	cube->top[1][2] == YELLOW ? c++ : 0;
	cube->top[2][1] == YELLOW ? c++ : 0;
	cube->top[1][0] == YELLOW ? c++ : 0;
	return (c);
}

void	algoSelector(t_cube *cube)
{
	if (cube->top[0][1] == YELLOW && cube->top[2][1] == YELLOW)
		doAlgo(cube, "R B U B' U' R'", 0, 1);
	else if (cube->top[1][0] == YELLOW && cube->top[1][2] == YELLOW)
		doAlgo(cube, "R B U B' U' R'", 1, 1);
	else if (cube->top[1][0] == YELLOW && cube->top[2][1] == YELLOW)
		doAlgo(cube, "R U B U' B' R'", 0, 1);
	else if (cube->top[1][2] == YELLOW && cube->top[2][1] == YELLOW)
		doAlgo(cube, "R U B U' B' R'", 1, 1);
	else if (cube->top[1][2] == YELLOW && cube->top[0][1] == YELLOW)
		doAlgo(cube, "R U B U' B' R'", 2, 1);
	else if (cube->top[0][1] == YELLOW && cube->top[1][0] == YELLOW)
		doAlgo(cube, "R U B U' B' R'", 3, 1);
}

void	solveYellowCross(t_cube *cube)
{
	if (!numberYellowPiece(cube))
		doAlgo(cube, "R U B U' B' R' B L U L' U' B'", 0, 1);
	else if (numberYellowPiece(cube) == 2)
		algoSelector(cube);
}
