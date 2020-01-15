#include "../rubik.h"

void	rotationF2(t_cube *cube)
{
	rotationF(cube);
	rotationF(cube);
}

void	rotationR2(t_cube *cube)
{
	rotationR(cube);
	rotationR(cube);
}

void	rotationU2(t_cube *cube)
{
	rotationU(cube);
	rotationU(cube);
}

void	rotationB2(t_cube *cube)
{
	rotationB(cube);
	rotationB(cube);
}

void	rotationL2(t_cube *cube)
{
	rotationL(cube);
	rotationL(cube);
}

void	rotationD2(t_cube *cube)
{
	rotationD(cube);
	rotationD(cube);
}
