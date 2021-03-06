#include "../rubik.h"

void	transformRotation(t_rotation *rot, int side)
{
	char c;

	c = rot->rotType;
	if (side == 1)
	{
		c == 'F' ? rot->rotType = 'R' : 0;
		c == 'R' ? rot->rotType = 'B' : 0;
		c == 'B' ? rot->rotType = 'L' : 0;
		c == 'L' ? rot->rotType = 'F' : 0;
	}
	if (side == 2)
	{
		c == 'F' ? rot->rotType = 'B' : 0;
		c == 'R' ? rot->rotType = 'L' : 0;
		c == 'B' ? rot->rotType = 'F' : 0;
		c == 'L' ? rot->rotType = 'R' : 0;
	}
	if (side == 3)
	{
		c == 'F' ? rot->rotType = 'L' : 0;
		c == 'R' ? rot->rotType = 'F' : 0;
		c == 'B' ? rot->rotType = 'R' : 0;
		c == 'L' ? rot->rotType = 'B' : 0;
	}
}

void	doRotation(t_cube *cube, t_rotation rot, int aff)
{
	if (rot.rotType == 'F')
	{
		!rot.P && !rot.two ? rotationF(cube, aff): 0;
		rot.P && !rot.two ? rotationFP(cube, aff): 0;
		!rot.P && rot.two ? rotationF2(cube, aff): 0;
	}
	if (rot.rotType == 'R')
	{
		!rot.P && !rot.two ? rotationR(cube, aff): 0;
		rot.P && !rot.two ? rotationRP(cube, aff): 0;
		!rot.P && rot.two ? rotationR2(cube, aff): 0;
	}
	if (rot.rotType == 'U')
	{
		!rot.P && !rot.two ? rotationU(cube, aff): 0;
		rot.P && !rot.two ? rotationUP(cube, aff): 0;
		!rot.P && rot.two ? rotationU2(cube, aff): 0;
	}
	if (rot.rotType == 'B')
	{
		!rot.P && !rot.two ? rotationB(cube, aff): 0;
		rot.P && !rot.two ? rotationBP(cube, aff): 0;
		!rot.P && rot.two ? rotationB2(cube, aff): 0;
	}
	if (rot.rotType == 'L')
	{
		!rot.P && !rot.two ? rotationL(cube, aff): 0;
		rot.P && !rot.two ? rotationLP(cube, aff): 0;
		!rot.P && rot.two ? rotationL2(cube, aff): 0;
	}
	if (rot.rotType == 'D')
	{
		!rot.P && !rot.two ? rotationD(cube, aff): 0;
		rot.P && !rot.two ? rotationDP(cube, aff): 0;
		!rot.P && rot.two ? rotationD2(cube, aff): 0;
	}
}

void	doAlgo(t_cube *cube, char *algo, int side, int aff)
{
	t_rotation	rot;
	int			i;
	char		c;

	i = -1;
	while (algo[++i])
	{
		c = algo[i];
		ft_memset(&rot, 0, sizeof(t_rotation));
		if (c != ' ' && c != 'F' && c != 'R' && c != 'U'
		&& c != 'B' && c != 'L' && c != 'D' && c != '\'' && c != '2')
			usage();
		if (c == ' ')
			continue;
		if (c == '2' || c == '\'')
			usage();
		rot.rotType = algo[i];
		if (algo[i + 1] == '2' || algo[i + 1] == '\'')
			algo[++i] == '2' ? rot.two = 1 : (rot.P = 1);
		transformRotation(&rot, side);
		doRotation(cube, rot, aff);
	}
}
