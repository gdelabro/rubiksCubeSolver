#include "../rubik.h"

int		searchPieceOnTop(t_arete *p, t_cube *cube)
{
	int ret;

	ret = 1;
	if (cube->top[1][0] != YELLOW && cube->left[0][1] != YELLOW)
	{
		p->color = cube->top[1][0];
		p->color2 = cube->left[0][1];
		p->side = 3;
	}
	else if (cube->top[2][1] != YELLOW && cube->front[0][1] != YELLOW)
	{
		p->color = cube->top[2][1];
		p->color2 = cube->front[0][1];
		p->side = 0;
	}
	else if (cube->top[1][2] != YELLOW && cube->right[0][1] != YELLOW)
	{
		p->color = cube->top[1][2];
		p->color2 = cube->right[0][1];
		p->side = 1;
	}
	else if (cube->top[0][1] != YELLOW && cube->back[2][1] != YELLOW)
	{
		p->color = cube->top[0][1];
		p->color2 = cube->back[2][1];
		p->side = 2;
	}
	else
		ret = 0;
	if (ret)
	{
		p->layer = (p->color + 2) % 4;
		p->layer = (4 + p->layer - p->side) % 4;
		p->side = 1;
		if ((p->color > p->color2 || (p->color == BLUE && p->color2 == ORANGE))
		&& (p->color != ORANGE || p->color2 != BLUE))
			p->side = 0;
	}
	return (ret);
}

void	solveSecondLayer(t_cube *cube)
{
	t_arete		p;

	while (!checkSecondLayer(cube))
	{
		if (searchPieceOnTop(&p, cube))
		{
			p.layer == 1 ? doAlgo(cube, "U'", 0, 1) : 0;
			p.layer == 2 ? doAlgo(cube, "U2", 0, 1) : 0;
			p.layer == 3 ? doAlgo(cube, "U", 0, 1) : 0;
			doAlgo(cube, p.side ? "L' U L U F U' F'" : "R U' R' U' F' U F",
			p.color2, 1);
		}
		else if (cube->front[1][2] != BLUE || cube->right[1][0] != RED)
			doAlgo(cube, "R U' R' U' F' U F", 0, 1);
		else if (cube->right[1][2] != RED || cube->back[1][2] != GREEN)
			doAlgo(cube, "R U' R' U' F' U F", 1, 1);
		else if (cube->back[1][0] != GREEN || cube->left[1][0] != ORANGE)
			doAlgo(cube, "R U' R' U' F' U F", 2, 1);
		else
			doAlgo(cube, "R U' R' U' F' U F", 3, 1);
	}
}
