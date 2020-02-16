#include "../rubik.h"

void	solveRedWhite(t_cube *cube)
{
	t_arete ar;

	ar.color = WHITE;
	ar.color2 = RED;
	findArete(&ar, cube);
	if (ar.side == -1)
		;
	else if (ar.side == -2)
	{
		ar.layer == 0 ? doAlgo(cube, "U'", 0, 1) : 0;
		ar.layer == 2 ? doAlgo(cube, "U", 0, 1) : 0;
		ar.layer == 3 ? doAlgo(cube, "U2", 0, 1) : 0;
		doAlgo(cube, "R2", 0, 1);
	}
	else if (ar.layer == 1)
	{
		ar.side == 1 ? doAlgo(cube, "D", 0, 1) : 0;
		ar.side == 2 ? doAlgo(cube, "D2", 0, 1) : 0;
		ar.side == 3 ? doAlgo(cube, "D'", 0, 1) : 0;
		doAlgo(cube, "R'", ar.side, 1);
		ar.side == 1 ? doAlgo(cube, "D'", 0, 1) : 0;
		ar.side == 2 ? doAlgo(cube, "D2", 0, 1) : 0;
		ar.side == 3 ? doAlgo(cube, "D", 0, 1) : 0;
	}
	else if (ar.layer == 3)
	{
		ar.side == 0 ? doAlgo(cube, "D2", 0, 1) : 0;
		ar.side == 1 ? doAlgo(cube, "D'", 0, 1) : 0;
		ar.side == 3 ? doAlgo(cube, "D", 0, 1) : 0;
		doAlgo(cube, "L", ar.side, 1);
		ar.side == 0 ? doAlgo(cube, "D2", 0, 1) : 0;
		ar.side == 1 ? doAlgo(cube, "D", 0, 1) : 0;
		ar.side == 3 ? doAlgo(cube, "D'", 0, 1) : 0;
	}
	else if (ar.layer == 0)
	{
		ar.side == 0 ? doAlgo(cube, "U'", 0, 1) : 0;
		ar.side == 2 ? doAlgo(cube, "U", 0, 1) : 0;
		ar.side == 3 ? doAlgo(cube, "U2", 0, 1) : 0;
		doAlgo(cube, "R", 0, 1);
		solveRedWhite(cube);
	}
	else if (ar.layer == 2)
		doAlgo(cube, "R' D B' D'", 0, 1);
}

void	solveOrangeWhite(t_cube *cube)
{
	t_arete ar;

	ar.color = WHITE;
	ar.color2 = ORANGE;
	findArete(&ar, cube);
	if (ar.side == -1 && ar.layer != 3)
	{
		doAlgo(cube, "F2", ar.layer, 1);
		solveOrangeWhite(cube);
	}
	else if (ar.side == -2)
	{
		ar.layer == 0 ? doAlgo(cube, "U", 0, 1) : 0;
		ar.layer == 1 ? doAlgo(cube, "U2", 0, 1) : 0;
		ar.layer == 2 ? doAlgo(cube, "U'", 0, 1) : 0;
		doAlgo(cube, "L2", 0, 1);
	}
	else if (ar.side != -1 && ar.layer == 3)
	{
		ar.side == 3 ? doAlgo(cube, "D'", 0, 1) : 0;
		ar.side == 2 ? doAlgo(cube, "D2", 0, 1) : 0;
		ar.side == 1 ? doAlgo(cube, "D", 0, 1) : 0;
		doAlgo(cube, "L", ar.side, 1);
		ar.side == 3 ? doAlgo(cube, "D", 0, 1) : 0;
		ar.side == 2 ? doAlgo(cube, "D2", 0, 1) : 0;
		ar.side == 1 ? doAlgo(cube, "D'", 0, 1) : 0;
	}
	else if (ar.side != -1 && ar.layer == 1)
	{
		ar.side == 1 ? doAlgo(cube, "D'", 0, 1) : 0;
		ar.side == 0 ? doAlgo(cube, "D2", 0, 1) : 0;
		ar.side == 3 ? doAlgo(cube, "D", 0, 1) : 0;
		doAlgo(cube, "R'", ar.side, 1);
		ar.side == 1 ? doAlgo(cube, "D", 0, 1) : 0;
		ar.side == 0 ? doAlgo(cube, "D2", 0, 1) : 0;
		ar.side == 3 ? doAlgo(cube, "D'", 0, 1) : 0;
	}
	else if (ar.side != -1 && ar.layer == 0)
	{
		ar.side == 0 ? doAlgo(cube, "U2", 0, 1) : 0;
		ar.side == 1 ? doAlgo(cube, "U'", 0, 1) : 0;
		ar.side == 3 ? doAlgo(cube, "U", 0, 1) : 0;
		doAlgo(cube, "B L'", 0, 1);
	}
	else if (ar.side != -1 && ar.layer == 2)
	{
		doAlgo(cube, "F", ar.side, 1);
		solveOrangeWhite(cube);
	}
}

void	solveBlueWhite(t_cube *cube)
{
	t_arete ar;

	ar.color = WHITE;
	ar.color2 = BLUE;
	findArete(&ar, cube);
	if (ar.side == -1)
	{
		ar.layer == 1 ? doAlgo(cube, "D'", 0, 1) : 0;
		ar.layer == 2 ? doAlgo(cube, "D2", 0, 1) : 0;
		ar.layer == 3 ? doAlgo(cube, "D", 0, 1) : 0;
	}
	else if (ar.side == -2)
	{
		ar.layer == 1 ? doAlgo(cube, "U", 0, 1) : 0;
		ar.layer == 2 ? doAlgo(cube, "U2", 0, 1) : 0;
		ar.layer == 3 ? doAlgo(cube, "U'", 0, 1) : 0;
		doAlgo(cube, "F2", 0, 1);
	}
	else
	{
		ar.layer == 0 ? doAlgo(cube, "F' L", ar.side, 1) : 0;
		ar.layer == 1 ? doAlgo(cube, "R'", ar.side, 1) : 0;
		ar.layer == 2 ? doAlgo(cube, "F L", ar.side, 1) : 0;
		ar.layer == 3 ? doAlgo(cube, "L", ar.side, 1) : 0;
		solveBlueWhite(cube);
	}
}

void	solveGreenWhite(t_cube *cube)
{
	t_arete ar;

	ar.color = WHITE;
	ar.color2 = GREEN;
	findArete(&ar, cube);
	if (ar.side == -1)
		ar.layer == 1 ? doAlgo(cube, "R D' R' D", 0, 1): 0;
	else if (ar.side == -2)
	{
		ar.layer == 0 ? doAlgo(cube, "U2", 0, 1) : 0;
		ar.layer == 1 ? doAlgo(cube, "U'", 0, 1) : 0;
		ar.layer == 3 ? doAlgo(cube, "U", 0, 1) : 0;
		doAlgo(cube, "B2", 0, 1);
	}
	else if (ar.layer == 1)
	{
		ar.side == 0 ? doAlgo(cube, "D'", 0, 1) : 0;
		ar.side == 2 ? doAlgo(cube, "D", 0, 1) : 0;
		ar.side == 3 ? doAlgo(cube, "D2", 0, 1) : 0;
		doAlgo(cube, "R'", ar.side, 1);
		ar.side == 0 ? doAlgo(cube, "D", 0, 1) : 0;
		ar.side == 2 ? doAlgo(cube, "D'", 0, 1) : 0;
		ar.side == 3 ? doAlgo(cube, "D2", 0, 1) : 0;
	}
	else if (ar.layer == 3)
	{
		ar.side == 0 ? doAlgo(cube, "D", 0, 1) : 0;
		ar.side == 1 ? doAlgo(cube, "D2", 0, 1) : 0;
		ar.side == 2 ? doAlgo(cube, "D'", 0, 1) : 0;
		doAlgo(cube, "L", ar.side, 1);
		ar.side == 0 ? doAlgo(cube, "D'", 0, 1) : 0;
		ar.side == 1 ? doAlgo(cube, "D2", 0, 1) : 0;
		ar.side == 2 ? doAlgo(cube, "D", 0, 1) : 0;
	}
	else if (ar.layer == 0)
	{
		ar.side == 0 ? doAlgo(cube, "U'", 0, 1) : 0;
		ar.side == 2 ? doAlgo(cube, "U", 0, 1) : 0;
		ar.side == 3 ? doAlgo(cube, "U2", 0, 1) : 0;
		doAlgo(cube, "F R'", 1, 1);
	}
	else if (ar.layer == 2)
	{
		ar.side == 1 ? doAlgo(cube, "R' B'", 0, 1) : 0;
		ar.side == 2 ? doAlgo(cube, "B' D L' D'", 0, 1) : 0;
	}
}

void	solveWhiteCross(t_cube *cube)
{
	solveBlueWhite(cube);
	solveOrangeWhite(cube);
	solveGreenWhite(cube);
	solveRedWhite(cube);
}
