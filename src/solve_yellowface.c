#include "../rubik.h"
void	fillCubeForme(t_cube *cube, int *c0, int *c1, int *c2, int *c3)
{
	cube->top[0][0] == YELLOW ? *c0 = 0 : 0;
	cube->left[0][0] == YELLOW ? *c0 = 1 : 0;
	cube->back[2][0] == YELLOW ? *c0 = 2 : 0;

	cube->top[0][2] == YELLOW ? *c1 = 0 : 0;
	cube->back[2][2] == YELLOW ? *c1 = 1 : 0;
	cube->right[0][2] == YELLOW ? *c1 = 2 : 0;

	cube->top[2][2] == YELLOW ? *c2 = 0 : 0;
	cube->right[0][0] == YELLOW ? *c2 = 1 : 0;
	cube->front[0][2] == YELLOW ? *c2 = 2 : 0;

	cube->top[2][0] == YELLOW ? *c3 = 0 : 0;
	cube->front[0][0] == YELLOW ? *c3 = 1 : 0;
	cube->left[0][2] == YELLOW ? *c3 = 2 : 0;
}

int		formeScanning(t_cube *cube, int f0, int f1, int f2, int f3)
{
	int		c0;
	int		c1;
	int		c2;
	int		c3;

	fillCubeForme(cube, &c0, &c1, &c2, &c3);
	if (c0 == f0 && c1 == f1 && c2 == f2 && c3 == f3)
		return (0);
	if (c0 == f1 && c1 == f2 && c2 == f3 && c3 == f0)
		return (1);
	if (c0 == f2 && c1 == f3 && c2 == f0 && c3 == f1)
		return (2);
	if (c0 == f3 && c1 == f0 && c2 == f1 && c3 == f2)
		return (3);
	return (-1);
}

void	solveYellowFace(t_cube *cube)
{
	int		side;

	if ((side = formeScanning(cube, 1, 1, 0, 1)) != -1)
		doAlgo(cube, "L' U' L U' L' U2 L", side, 1);
	else if ((side = formeScanning(cube, 2, 2, 2, 0)) != -1)
		doAlgo(cube, "R U R' U R U2 R'", side, 1);
	else if ((side = formeScanning(cube, 2, 2, 1, 1)) != -1)
		doAlgo(cube, "L U' R' U L' U R U R' U R", side, 1);
	else if ((side = formeScanning(cube, 1, 2, 1, 2)) != -1)
		doAlgo(cube, "R U R' U R U' R' U R U2 R'", side, 1);
	else if ((side = formeScanning(cube, 0, 1, 2, 0)) != -1)
		doAlgo(cube, "R' F' L F R F' L' F", side, 1);
	else if ((side = formeScanning(cube, 0, 0, 2, 1)) != -1)
		doAlgo(cube, "R2 D R' U2 R D' R' U2 R'", side, 1);
	else if ((side = formeScanning(cube, 0, 1, 0, 2)) != -1)
		doAlgo(cube, "R' F' L' F R F' L F", side, 1);
}
