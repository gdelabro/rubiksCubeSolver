#include "../rubik.h"

void	rotationFP(t_cube *cube)
{
	rotateFace2((int*)&cube->front);

	cube->buffer[0][2] = cube->top[2][2];
	cube->buffer[1][2] = cube->top[2][1];
	cube->buffer[2][2] = cube->top[2][0];

	cube->top[2][0] = cube->right[0][0];
	cube->top[2][1] = cube->right[1][0];
	cube->top[2][2] = cube->right[2][0];

	cube->right[0][0] = cube->bottom[0][2];
	cube->right[1][0] = cube->bottom[0][1];
	cube->right[2][0] = cube->bottom[0][0];

	cube->bottom[0][0] = cube->left[0][2];
	cube->bottom[0][1] = cube->left[1][2];
	cube->bottom[0][2] = cube->left[2][2];

	cube->left[0][2] = cube->buffer[0][2];
	cube->left[1][2] = cube->buffer[1][2];
	cube->left[2][2] = cube->buffer[2][2];
}

void	rotationRP(t_cube *cube)
{
	rotateFace2((int*)&cube->right);

	cube->buffer[0][2] = cube->top[0][2];
	cube->buffer[1][2] = cube->top[1][2];
	cube->buffer[2][2] = cube->top[2][2];

	cube->top[0][2] = cube->back[0][2];
	cube->top[1][2] = cube->back[1][2];
	cube->top[2][2] = cube->back[2][2];

	cube->back[0][2] = cube->bottom[0][2];
	cube->back[1][2] = cube->bottom[1][2];
	cube->back[2][2] = cube->bottom[2][2];

	cube->bottom[0][2] = cube->front[0][2];
	cube->bottom[1][2] = cube->front[1][2];
	cube->bottom[2][2] = cube->front[2][2];

	cube->front[0][2] = cube->buffer[0][2];
	cube->front[1][2] = cube->buffer[1][2];
	cube->front[2][2] = cube->buffer[2][2];
}

void	rotationUP(t_cube *cube)
{
	rotateFace2((int*)&cube->top);

	cube->buffer[0][0] = cube->front[0][0];
	cube->buffer[0][1] = cube->front[0][1];
	cube->buffer[0][2] = cube->front[0][2];

	cube->front[0][0] = cube->left[0][0];
	cube->front[0][1] = cube->left[0][1];
	cube->front[0][2] = cube->left[0][2];

	cube->left[0][0] = cube->back[2][2];
	cube->left[0][1] = cube->back[2][1];
	cube->left[0][2] = cube->back[2][0];

	cube->back[2][2] = cube->right[0][0];
	cube->back[2][1] = cube->right[0][1];
	cube->back[2][0] = cube->right[0][2];

	cube->right[0][0] = cube->buffer[0][0];
	cube->right[0][1] = cube->buffer[0][1];
	cube->right[0][2] = cube->buffer[0][2];
}

void	rotationBP(t_cube *cube)
{
	rotateFace2((int*)&cube->back);

	cube->buffer[0][2] = cube->top[0][0];
	cube->buffer[1][2] = cube->top[0][1];
	cube->buffer[2][2] = cube->top[0][2];

	cube->top[0][0] = cube->left[2][0];
	cube->top[0][1] = cube->left[1][0];
	cube->top[0][2] = cube->left[0][0];

	cube->left[2][0] = cube->bottom[2][2];
	cube->left[1][0] = cube->bottom[2][1];
	cube->left[0][0] = cube->bottom[2][0];

	cube->bottom[2][2] = cube->right[0][2];
	cube->bottom[2][1] = cube->right[1][2];
	cube->bottom[2][0] = cube->right[2][2];

	cube->right[0][2] = cube->buffer[0][2];
	cube->right[1][2] = cube->buffer[1][2];
	cube->right[2][2] = cube->buffer[2][2];
}

void	rotationLP(t_cube *cube)
{
	rotateFace2((int*)&cube->left);

	cube->buffer[0][0] = cube->top[0][0];
	cube->buffer[1][0] = cube->top[1][0];
	cube->buffer[2][0] = cube->top[2][0];

	cube->top[0][0] = cube->front[0][0];
	cube->top[1][0] = cube->front[1][0];
	cube->top[2][0] = cube->front[2][0];

	cube->front[0][0] = cube->bottom[0][0];
	cube->front[1][0] = cube->bottom[1][0];
	cube->front[2][0] = cube->bottom[2][0];

	cube->bottom[0][0] = cube->back[0][0];
	cube->bottom[1][0] = cube->back[1][0];
	cube->bottom[2][0] = cube->back[2][0];

	cube->back[0][0] = cube->buffer[0][0];
	cube->back[1][0] = cube->buffer[1][0];
	cube->back[2][0] = cube->buffer[2][0];
}

void	rotationDP(t_cube *cube)
{
	rotateFace2((int*)&cube->bottom);

	cube->buffer[2][0] = cube->front[2][0];
	cube->buffer[2][1] = cube->front[2][1];
	cube->buffer[2][2] = cube->front[2][2];

	cube->front[2][0] = cube->right[2][0];
	cube->front[2][1] = cube->right[2][1];
	cube->front[2][2] = cube->right[2][2];

	cube->right[2][0] = cube->back[0][2];
	cube->right[2][1] = cube->back[0][1];
	cube->right[2][2] = cube->back[0][0];

	cube->back[0][2] = cube->left[2][0];
	cube->back[0][1] = cube->left[2][1];
	cube->back[0][0] = cube->left[2][2];

	cube->left[2][0] = cube->buffer[2][0];
	cube->left[2][1] = cube->buffer[2][1];
	cube->left[2][2] = cube->buffer[2][2];
}
