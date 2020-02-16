#include "../rubik.h"

void	orientCorners(t_cube *cube)
{
	if (cube->front[0][0] == cube->front[0][2]
		&& cube->right[0][0] == cube->right[0][2])
		;
	else if (cube->front[0][0] == cube->front[0][2])
		doAlgo(cube, "R' F R' B2 R F' R' B2 R2", 2, 1);
	else if (cube->right[0][0] == cube->right[0][2])
		doAlgo(cube, "R' F R' B2 R F' R' B2 R2", 3, 1);
	else if (cube->back[2][0] == cube->back[2][2])
		doAlgo(cube, "R' F R' B2 R F' R' B2 R2", 0, 1);
	else if (cube->left[0][0] == cube->left[0][2])
		doAlgo(cube, "R' F R' B2 R F' R' B2 R2", 1, 1);
	else
	{
		doAlgo(cube, "R' F R' B2 R F' R' B2 R2", 0, 1);
		orientCorners(cube);
	}
}
