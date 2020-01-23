#include "../rubik.h"

void	solveRedBlueCorner(t_cube *cube)
{
	t_arete p;

	p.color = WHITE;
	p.color2 = RED;
	p.color3 = BLUE;
	findCorner(&p, cube);
	if (p.side == -2)
	{
		p.layer == 0 ? doAlgo(cube, "R U R' F' U' F", 0, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "U R U' R' F' U2 F", 0, 1) : 0;
		p.layer == 2 ? doAlgo(cube, "R U' R' F' U2 F", 0, 1) : 0;
		p.layer == 3 ? doAlgo(cube, "R U2 R' F' U' F", 0, 1) : 0;
	}
	else if (p.side == 0)
	{
		p.layer == 0 ? doAlgo(cube, "U' R U R'", 0, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "F' U' F", 0, 1) : 0;
		p.layer == 2 ? doAlgo(cube, "R U' R' F' U' F", 0, 1) : 0;
	}
	else if (p.side == 1)
	{
		p.layer == 0 ? doAlgo(cube, "F U F'", 1, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "U F' U' F", 0, 1) : 0;
		p.layer == 3 ? doAlgo(cube, "L' U L F U F'", 1, 1) : 0;
	}
	else if (p.side == 2)
	{
		p.layer == 0 ? doAlgo(cube, "B' U B", 2, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "L U2 L'", 2, 1) : 0;
	}
	else if (p.side == 3)
	{
		p.layer == 0 ? doAlgo(cube, "R' U2 R", 3, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "B U' B'", 3, 1) : 0;
	}
}

void	solveGreenRedCorner(t_cube *cube)
{
	t_arete		p;

	p.color = WHITE;
	p.color2 = GREEN;
	p.color3 = RED;
	findCorner(&p, cube);
	if (p.side == -1)
		p.layer == 1 ? doAlgo(cube, "F' U' F B U B'", 0, 1) : 0;
	else if (p.side == -2)
	{
		p.layer == 0 ? doAlgo(cube, "U2 L U' L2 U L", 2, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "U L U' L2 U L", 2, 1) : 0;
		p.layer == 2 ? doAlgo(cube, "L U' L2 U L", 2, 1) : 0;
		p.layer == 3 ? doAlgo(cube, "U' L U' L2 U L", 2, 1) : 0;
	}
	else if (p.side == 0)
	{
		p.layer == 0 ? doAlgo(cube, "R' U2 R", 0, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "B U' B'", 0, 1) : 0;
		p.layer == 2 ? doAlgo(cube, "F' B U' F B'", 0, 1) : 0;
	}
	else if (p.side == 1)
	{
		p.layer == 0 ? doAlgo(cube, "U' R U R'", 1, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "F' U' F", 1, 1) : 0;
		p.layer == 2 ? doAlgo(cube, "F' U2 F R U2 R'", 1, 1) : 0;
		p.layer == 3 ? doAlgo(cube, "F U F2 U2 F", 1, 1) : 0;
	}
	else if (p.side == 2)
	{
		p.layer == 0 ? doAlgo(cube, "F U F'", 2, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "U' F U2 F'", 2, 1) : 0;
		p.layer == 3 ? doAlgo(cube, "L' U L F U F'", 2, 1) : 0;
	}
	else if (p.side == 3)
	{
		p.layer == 0 ? doAlgo(cube, "B' U B", 3, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "L U2 L'", 3, 1) : 0;
	}
}

void	solveOrangeGreenCorner(t_cube *cube)
{
	t_arete		p;

	p.color = WHITE;
	p.color2 = ORANGE;
	p.color3 = GREEN;
	findCorner(&p, cube);
	if (p.side == -1)
	{
		p.layer == 1 ? doAlgo(cube, "F' B' U2 B F", 0, 1) : 0;
		p.layer == 2 ? doAlgo(cube, "L' U' L R U R'", 2, 1) : 0;
	}
	else if (p.side == -2)
	{
		p.layer == 0 ? doAlgo(cube, "U L U' L2 U L", 3, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "L U' L2 U L", 3, 1) : 0;
		p.layer == 2 ? doAlgo(cube, "U' L U' L2 U L", 3, 1) : 0;
		p.layer == 3 ? doAlgo(cube, "U2 L U' L2 U L", 3, 1) : 0;
	}
	else if (p.side == 0)
	{
		p.layer == 0 ? doAlgo(cube, "B' U B", 0, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "L U2 L'", 0, 1) : 0;
		p.layer == 2 ? doAlgo(cube, "F' U' F L U' L'", 0, 1) : 0;
	}
	else if (p.side == 1)
	{
		p.layer == 0 ? doAlgo(cube, "B' U2 B", 0, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "L U' L'", 0, 1) : 0;
		p.layer == 2 ? doAlgo(cube, "R L' U' L R'", 2, 1) : 0;
		p.layer == 3 ? doAlgo(cube, "R U R' B' U B", 0, 1) : 0;
	}
	else if (p.side == 2)
	{
		p.layer == 0 ? doAlgo(cube, "U' R U R'", 2, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "F' U' F", 2, 1) : 0;
		p.layer == 2 ? doAlgo(cube, "R U' R' F' U' F", 2, 1) : 0;
		p.layer == 3 ? doAlgo(cube, "F U F2 U2 F", 2, 1) : 0;
	}
	else if (p.side == 3)
	{
		p.layer == 0 ? doAlgo(cube, "F U F'", 3, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "U L' U' L", 3, 1) : 0;
		p.layer == 3 ? doAlgo(cube, "L' U L F U F'", 3, 1) : 0;
	}
}

void	solveBlueOrangeCorner(t_cube *cube)
{
	t_arete		p;

	p.color = WHITE;
	p.color2 = BLUE;
	p.color3 = ORANGE;
	findCorner(&p, cube);
	if (p.side == -1)
	{
		p.layer == 1 ? doAlgo(cube, "R U R' L' U' L", 0, 1) : 0;
		p.layer == 2 ? doAlgo(cube, "R U2 R' B' U' B", 1, 1) : 0;
		p.layer == 3 ? doAlgo(cube, "B' U' B F U F'", 0, 1) : 0;
	}
	else if (p.side == -2)
	{
		p.layer == 0 ? doAlgo(cube, "L U' L2 U L", 0, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "U' L U' L2 U L", 0, 1) : 0;
		p.layer == 2 ? doAlgo(cube, "U2 L U' L2 U L", 0, 1) : 0;
		p.layer == 3 ? doAlgo(cube, "U L U'L2 U L", 0, 1) : 0;
	}
	else if (p.side == 0)
	{
		p.layer == 0 ? doAlgo(cube, "F U F'", 0, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "U L' U' L", 0, 1) : 0;
		p.layer == 2 ? doAlgo(cube, "F' U' F2 U2 F'", 0, 1) : 0;
		p.layer == 3 ? doAlgo(cube, "F U F' U' F U F'", 0, 1) : 0;
	}
	else if (p.side == 1)
	{
		p.layer == 0 ? doAlgo(cube, "L' U L", 0, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "F U2 F'", 0, 1) : 0;
		p.layer == 2 ? doAlgo(cube, "R' U' R F U' F'", 0, 1) : 0;
		p.layer == 3 ? doAlgo(cube, "R L' U L R'", 0, 1) : 0;
	}
	else if (p.side == 2)
	{
		p.layer == 0 ? doAlgo(cube, "L' U2 L", 0, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "F U' F'", 0, 1) : 0;
		p.layer == 2 ? doAlgo(cube, "F B' U' B F'", 0, 1) : 0;
		p.layer == 3 ? doAlgo(cube, "B U B' L' U L", 0, 1) : 0;
	}
	else if (p.side == 3)
	{
		p.layer == 0 ? doAlgo(cube, "U' F U F'", 0, 1) : 0;
		p.layer == 1 ? doAlgo(cube, "L' U' L", 0, 1) : 0;
		p.layer == 2 ? doAlgo(cube, "F U' F' L' U' L", 0, 1) : 0;
		p.layer == 3 ? doAlgo(cube, "L U2 L2 U L", 0, 1) : 0;
	}
}

void	solveWhiteFace(t_cube *cube)
{
	solveBlueOrangeCorner(cube);
	solveOrangeGreenCorner(cube);
	solveGreenRedCorner(cube);
	solveRedBlueCorner(cube);
}
