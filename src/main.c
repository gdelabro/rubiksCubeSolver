#include "../rubik.h"

void	usage()
{
	ft_printf("./rubik \"SCRAMBLE\"\nSCRAMBLE commands:\n\tF R U B L D\n\
command suffix:\n\t': turn the other way\n\t2: turn twice\n");
}

void	init_cube(t_cube *cube)
{
	int i;
	int i2;
	int i3;

	i3 = -1;
	while (++i3 < 6)
	{
		i = -1;
		while (++i < 3)
		{
			i2 = -1;
			while (++i2 < 3)
			{
				i3 == 0 ? cube->bottom[i][i2] = WHITE : 0;
				i3 == 1 ? cube->top[i][i2] = YELLOW : 0;
				i3 == 2 ? cube->front[i][i2] = BLUE : 0;
				i3 == 3 ? cube->back[i][i2] = GREEN : 0;
				i3 == 4 ? cube->left[i][i2] = ORANGE : 0;
				i3 == 5 ? cube->right[i][i2] = RED : 0;
			}
		}
	}
}

void	lunchAlgo(t_cube *cube)
{
	cube->front[1][2] = ORANGE;
	cube->front[0][0] = GREEN;
	showCube(cube);
	rotationF(cube);
	showCube(cube);
}

int		main(int ac, char **av)
{
	t_cube		cube;

	if (ac < 2)
		usage();
	init_cube(&cube);
	lunchAlgo(&cube);
	return (1);
}
