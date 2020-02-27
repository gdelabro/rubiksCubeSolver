#include "../rubik.h"

void	rotationF2(t_cube *cube, int aff)
{
	rotationF(cube, 0);
	rotationF(cube, 0);
	!cube->p.silent && aff ? ft_printf("F2"SEPARATOR) : 0;
	cube->p.visual == 1 && aff ? showCube(cube) : 0;
	aff ? cube->count++ : 0;
}

void	rotationR2(t_cube *cube, int aff)
{
	rotationR(cube, 0);
	rotationR(cube, 0);
	!cube->p.silent && aff ? ft_printf("R2"SEPARATOR) : 0;
	cube->p.visual == 1 && aff ? showCube(cube) : 0;
	aff ? cube->count++ : 0;
}

void	rotationU2(t_cube *cube, int aff)
{
	rotationU(cube, 0);
	rotationU(cube, 0);
	!cube->p.silent && aff ? ft_printf("U2"SEPARATOR) : 0;
	cube->p.visual == 1 && aff ? showCube(cube) : 0;
	aff ? cube->count++ : 0;
}

void	rotationB2(t_cube *cube, int aff)
{
	rotationB(cube, 0);
	rotationB(cube, 0);
	!cube->p.silent && aff ? ft_printf("B2"SEPARATOR) : 0;
	cube->p.visual == 1 && aff ? showCube(cube) : 0;
	aff ? cube->count++ : 0;
}

void	rotationL2(t_cube *cube, int aff)
{
	rotationL(cube, 0);
	rotationL(cube, 0);
	!cube->p.silent && aff ? ft_printf("L2"SEPARATOR) : 0;
	cube->p.visual == 1 && aff ? showCube(cube) : 0;
	aff ? cube->count++ : 0;
}

void	rotationD2(t_cube *cube, int aff)
{
	rotationD(cube, 0);
	rotationD(cube, 0);
	!cube->p.silent && aff ? ft_printf("D2"SEPARATOR) : 0;
	cube->p.visual == 1 && aff ? showCube(cube) : 0;
	aff ? cube->count++ : 0;
}
