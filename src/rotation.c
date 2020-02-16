#include "../rubik.h"

void	rotationF(t_cube *cube, int aff)
{
	rotateFace((int*)&(cube->front));

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
	!cube->p.silent && aff ? ft_printf("F\n") : 0;
	aff ? cube->count++ : 0;
}

void	rotationR(t_cube *cube, int aff)
{
	rotateFace((int*)&cube->right);
	
	cube->buffer[0][2] = cube->top[0][2];
	cube->buffer[1][2] = cube->top[1][2];
	cube->buffer[2][2] = cube->top[2][2];

	cube->top[0][2] = cube->front[0][2];
	cube->top[1][2] = cube->front[1][2];
	cube->top[2][2] = cube->front[2][2];

	cube->front[0][2] = cube->bottom[0][2];
	cube->front[1][2] = cube->bottom[1][2];
	cube->front[2][2] = cube->bottom[2][2];

	cube->bottom[0][2] = cube->back[0][2];
	cube->bottom[1][2] = cube->back[1][2];
	cube->bottom[2][2] = cube->back[2][2];

	cube->back[0][2] = cube->buffer[0][2];
	cube->back[1][2] = cube->buffer[1][2];
	cube->back[2][2] = cube->buffer[2][2];
	!cube->p.silent && aff ? ft_printf("R\n") : 0;
	aff ? cube->count++ : 0;
}

void	rotationU(t_cube *cube, int aff)
{
	rotateFace((int*)&cube->top);

	cube->buffer[0][0] = cube->front[0][0];
	cube->buffer[0][1] = cube->front[0][1];
	cube->buffer[0][2] = cube->front[0][2];

	cube->front[0][0] = cube->right[0][0];
	cube->front[0][1] = cube->right[0][1];
	cube->front[0][2] = cube->right[0][2];

	cube->right[0][0] = cube->back[2][2];
	cube->right[0][1] = cube->back[2][1];
	cube->right[0][2] = cube->back[2][0];

	cube->back[2][2] = cube->left[0][0];
	cube->back[2][1] = cube->left[0][1];
	cube->back[2][0] = cube->left[0][2];

	cube->left[0][0] = cube->buffer[0][0];
	cube->left[0][1] = cube->buffer[0][1];
	cube->left[0][2] = cube->buffer[0][2];
	!cube->p.silent && aff ? ft_printf("U\n") : 0;
	aff ? cube->count++ : 0;
}

void	rotationB(t_cube *cube, int aff)
{
	rotateFace((int*)&cube->back);

	cube->buffer[2][0] = cube->top[0][0];
	cube->buffer[1][0] = cube->top[0][1];
	cube->buffer[0][0] = cube->top[0][2];

	cube->top[0][0] = cube->right[0][2];
	cube->top[0][1] = cube->right[1][2];
	cube->top[0][2] = cube->right[2][2];

	cube->right[0][2] = cube->bottom[2][2];
	cube->right[1][2] = cube->bottom[2][1];
	cube->right[2][2] = cube->bottom[2][0];

	cube->bottom[2][2] = cube->left[2][0];
	cube->bottom[2][1] = cube->left[1][0];
	cube->bottom[2][0] = cube->left[0][0];

	cube->left[2][0] = cube->buffer[2][0];
	cube->left[1][0] = cube->buffer[1][0];
	cube->left[0][0] = cube->buffer[0][0];
	!cube->p.silent && aff ? ft_printf("B\n") : 0;
	aff ? cube->count++ : 0;
}

void	rotationL(t_cube *cube, int aff)
{
	rotateFace((int*)&cube->left);

	cube->buffer[0][0] = cube->top[0][0];
	cube->buffer[1][0] = cube->top[1][0];
	cube->buffer[2][0] = cube->top[2][0];

	cube->top[0][0] = cube->back[0][0];
	cube->top[1][0] = cube->back[1][0];
	cube->top[2][0] = cube->back[2][0];

	cube->back[0][0] = cube->bottom[0][0];
	cube->back[1][0] = cube->bottom[1][0];
	cube->back[2][0] = cube->bottom[2][0];

	cube->bottom[0][0] = cube->front[0][0];
	cube->bottom[1][0] = cube->front[1][0];
	cube->bottom[2][0] = cube->front[2][0];

	cube->front[0][0] = cube->buffer[0][0];
	cube->front[1][0] = cube->buffer[1][0];
	cube->front[2][0] = cube->buffer[2][0];
	!cube->p.silent && aff ? ft_printf("L\n") : 0;
	aff ? cube->count++ : 0;
}

void	rotationD(t_cube *cube, int aff)
{
	rotateFace((int*)&cube->bottom);

	cube->buffer[2][0] = cube->front[2][0];
	cube->buffer[2][1] = cube->front[2][1];
	cube->buffer[2][2] = cube->front[2][2];

	cube->front[2][0] = cube->left[2][0];
	cube->front[2][1] = cube->left[2][1];
	cube->front[2][2] = cube->left[2][2];

	cube->left[2][0] = cube->back[0][2];
	cube->left[2][1] = cube->back[0][1];
	cube->left[2][2] = cube->back[0][0];

	cube->back[0][2] = cube->right[2][0];
	cube->back[0][1] = cube->right[2][1];
	cube->back[0][0] = cube->right[2][2];

	cube->right[2][0] = cube->buffer[2][0];
	cube->right[2][1] = cube->buffer[2][1];
	cube->right[2][2] = cube->buffer[2][2];
	!cube->p.silent && aff ? ft_printf("D\n") : 0;
	aff ? cube->count++ : 0;
}
