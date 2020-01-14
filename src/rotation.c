#include "../rubik.h"

void	rotationF(t_cube *cube)
{
	copyFaceToBuf(cube->front, cube);
	rotateFace(cube);
	copyBufToFront(cube);
	cube->buffer[2][0] = cube->left[2][2];
	cube->buffer[2][1] = cube->left[1][2];
	cube->buffer[2][2] = cube->left[0][2];

	cube->left[0][2] = cube->bottom[0][0];
	cube->left[1][2] = cube->bottom[0][1];
	cube->left[2][2] = cube->bottom[0][2];

	cube->bottom[0][0] = cube->right[2][0];
	cube->bottom[0][1] = cube->right[1][0];
	cube->bottom[0][2] = cube->right[0][0];
	
	cube->right[0][0] = cube->top[2][0];
	cube->right[1][0] = cube->top[2][1];
	cube->right[2][0] = cube->top[2][2];

	cube->top[2][0] = cube->buffer[2][0];
	cube->top[2][1] = cube->buffer[2][1];
	cube->top[2][2] = cube->buffer[2][2];
}
