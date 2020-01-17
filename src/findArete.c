#include "../rubik.h"

void	AreteOnTop(t_arete *ar, t_cube *cube)
{
	ar->side = -2;
	if (cube->top[2][1] == ar->color && cube->front[0][1] == ar->color2)
		ar->layer = 0;
	else if (cube->top[1][2] == ar->color && cube->right[0][1] == ar->color2)
		ar->layer = 1;
	else if (cube->top[0][1] == ar->color && cube->back[2][1] == ar->color2)
		ar->layer = 2;
	else if (cube->top[1][0] == ar->color && cube->left[0][1] == ar->color2)
		ar->layer = 3;
}

void	AreteOnLeft(t_arete *ar, t_cube *cube)
{
	ar->side = 3;
	if (cube->left[0][1] == ar->color && cube->top[1][0] == ar->color2)
		ar->layer = 0;
	else if (cube->left[1][2] == ar->color && cube->front[1][0] == ar->color2)
		ar->layer = 1;
	else if (cube->left[2][1] == ar->color && cube->bottom[1][0] == ar->color2)
		ar->layer = 2;
	else if (cube->left[1][0] == ar->color && cube->back[1][0] == ar->color2)
		ar->layer = 3;
	else
		AreteOnTop(ar, cube);
}

void	AreteOnBack(t_arete *ar, t_cube *cube)
{
	ar->side = 2;
	if (cube->back[2][1] == ar->color && cube->top[0][1] == ar->color2)
		ar->layer = 0;
	else if (cube->back[1][0] == ar->color && cube->left[1][0] == ar->color2)
		ar->layer = 1;
	else if (cube->back[0][1] == ar->color && cube->bottom[2][1] == ar->color2)
		ar->layer = 2;
	else if (cube->back[1][2] == ar->color && cube->right[1][2] == ar->color2)
		ar->layer = 3;
	else
		AreteOnLeft(ar, cube);
}

void	AreteOnRight(t_arete *ar, t_cube *cube)
{
	ar->side = 1;
	if (cube->right[0][1] == ar->color && cube->top[1][2] == ar->color2)
		ar->layer = 0;
	else if (cube->right[1][2] == ar->color && cube->back[1][2] == ar->color2)
		ar->layer = 1;
	else if (cube->right[2][1] == ar->color && cube->bottom[1][2] == ar->color2)
		ar->layer = 2;
	else if (cube->right[1][0] == ar->color && cube->front[1][2] == ar->color2)
		ar->layer = 3;
	else
		AreteOnBack(ar, cube);
}

void	AreteOnFront(t_arete *ar, t_cube *cube)
{
	ar->side = 0;
	if (cube->front[0][1] == ar->color && cube->top[2][1] == ar->color2)
		ar->layer = 0;
	else if (cube->front[1][2] == ar->color && cube->right[1][0] == ar->color2)
		ar->layer = 1;
	else if (cube->front[2][1] == ar->color && cube->bottom[0][1] == ar->color2)
		ar->layer = 2;
	else if (cube->front[1][0] == ar->color && cube->left[1][2] == ar->color2)
		ar->layer = 3;
	else
		AreteOnRight(ar, cube);
}

void	findArete(t_arete *ar, t_cube *cube)
{
	ar->side = -1;
	if (cube->bottom[0][1] == ar->color && cube->front[2][1] == ar->color2)
		ar->layer = 0;
	else if (cube->bottom[1][2] == ar->color && cube->right[2][1] == ar->color2)
		ar->layer = 1;
	else if (cube->bottom[2][1] == ar->color && cube->back[0][1] == ar->color2)
		ar->layer = 2;
	else if (cube->bottom[1][0] == ar->color && cube->left[2][1] == ar->color2)
		ar->layer = 3;
	else
		AreteOnFront(ar, cube);
}
