#include "../rubik.h"

//F2 U R' L F2 R L'  U  F2

char	*middleTurnSide(t_cube *cube)
{
	if (cube->back[2][1] == GREEN && cube->front[0][1] == ORANGE)
		return ("F2 U R' L F2 R L' U F2");
	if (cube->front[0][1] == BLUE && cube->back[2][1] == RED)
		return ("F2 U R' L F2 R L' U F2");
	if (cube->right[0][1] == RED && cube->left[0][1] == GREEN)
		return ("F2 U R' L F2 R L' U F2");
	if (cube->left[0][1] == ORANGE && cube->right[0][1] == BLUE)
		return ("F2 U R' L F2 R L' U F2");
	return ("F2 U' R' L F2 R L' U' F2");
}

void	orientMiddle(t_cube  *cube)
{
	int side;

	side = -1;
	cube->front[0][0] == GREEN ? doAlgo(cube, "U2", 0, 1) : 0;
	cube->front[0][0] == RED ? doAlgo(cube, "U'", 0, 1) : 0;
	cube->front[0][0] == ORANGE ? doAlgo(cube, "U", 0, 1) : 0;
	if (cube->front[0][0] == cube->front[0][1]
		&& cube->right[0][0] == cube->right[0][1])
		;
	else if (cube->front[0][0] == cube->front[0][1])
		side = 2;
	else if (cube->right[0][0] == cube->right[0][1])
		side = 3;
	else if (cube->back[2][0] == cube->back[2][1])
		side = 0;
	else if (cube->left[0][0] == cube->left[0][1])
		side = 1;
	else if (cube->front[0][1] == GREEN)
		doAlgo(cube, "R2 L2 D R2 L2 U2 R2 L2 D R2 L2", 0, 1);
	else
		doAlgo(cube, "R2 L2 D R2 L2 U R' L F2 R2 L2 B2 R' L U2",
		cube->front[0][1] == RED ? 0 : 1, 1);
	if (side != -1)
		doAlgo(cube, middleTurnSide(cube), side, 1);
}
