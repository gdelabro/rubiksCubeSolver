#include "../rubik.h"

void	cornerOnTop(t_arete *p, t_cube *cube)
{
	p->side = -2;
	if (cube->top[0][0] == p->color && cube->back[2][0] == p->color2)
		p->layer = 0;
	else if (cube->top[0][2] == p->color && cube->right[0][2] == p->color2)
		p->layer = 1;
	else if (cube->top[2][2] == p->color && cube->front[0][2] == p->color2)
		p->layer = 2;
	else if (cube->top[2][0] == p->color && cube->left[0][2] == p->color2)
		p->layer = 3;
}

void	cornerOnLeft(t_arete *p, t_cube *cube)
{
	p->side = 3;
	if (cube->left[0][0] == p->color && cube->top[0][0] == p->color2)
		p->layer = 0;
	else if (cube->left[0][2] == p->color && cube->front[0][0] == p->color2)
		p->layer = 1;
	else if (cube->left[2][2] == p->color && cube->bottom[0][0] == p->color2)
		p->layer = 2;
	else if (cube->left[2][0] == p->color && cube->back[0][0] == p->color2)
		p->layer = 3;
	else
		cornerOnTop(p, cube);
}

void	cornerOnBack(t_arete *p, t_cube *cube)
{
	p->side = 2;
	if (cube->back[2][2] == p->color && cube->top[0][2] == p->color2)
		p->layer = 0;
	else if (cube->back[2][0] == p->color && cube->left[0][0] == p->color2)
		p->layer = 1;
	else if (cube->back[0][0] == p->color && cube->bottom[2][0] == p->color2)
		p->layer = 2;
	else if (cube->back[0][2] == p->color && cube->right[2][2] == p->color2)
		p->layer = 3;
	else
		cornerOnLeft(p, cube);
}

void	cornerOnRight(t_arete *p, t_cube *cube)
{
	p->side = 1;
	if (cube->right[0][0] == p->color && cube->top[2][2] == p->color2)
		p->layer = 0;
	else if (cube->right[0][2] == p->color && cube->back[2][2] == p->color2)
		p->layer = 1;
	else if (cube->right[2][2] == p->color && cube->bottom[2][2] == p->color2)
		p->layer = 2;
	else if (cube->right[2][0] == p->color && cube->front[2][2] == p->color2)
		p->layer = 3;
	else
		cornerOnBack(p, cube);
}

void	cornerOnFront(t_arete *p, t_cube *cube)
{
	p->side = 0;
	if (cube->front[0][0] == p->color && cube->top[2][0] == p->color2)
		p->layer = 0;
	else if (cube->front[0][2] == p->color && cube->right[0][0] == p->color2)
		p->layer = 1;
	else if (cube->front[2][2] == p->color && cube->bottom[0][2] == p->color2)
		p->layer = 2;
	else if (cube->front[2][0] == p->color && cube->left[2][2] == p->color2)
		p->layer = 3;
	else
		cornerOnRight(p, cube);
}

void	findCorner(t_arete *p, t_cube *cube)
{
	p->side = -1;
	if (cube->bottom[0][0] == p->color && cube->front[2][0] == p->color2)
		p->layer = 0;
	else if (cube->bottom[0][2] == p->color && cube->right[2][0] == p->color2)
		p->layer = 1;
	else if (cube->bottom[2][2] == p->color && cube->back[0][2] == p->color2)
		p->layer = 2;
	else if (cube->bottom[2][0] == p->color && cube->left[2][0] == p->color2)
		p->layer = 3;
	else
		cornerOnFront(p, cube);
}
