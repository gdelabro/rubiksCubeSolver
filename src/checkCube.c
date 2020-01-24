#include "../rubik.h"

int		checkSecondLayer(t_cube *cube)
{
	 if (cube->front[1][0] != BLUE || cube->front[1][2] != BLUE)
		return (0);
	 if (cube->right[1][0] != RED || cube->right[1][2] != RED)
		return (0);
	 if (cube->back[1][0] != GREEN || cube->back[1][2] != GREEN)
		return (0);
	 if (cube->left[1][0] != ORANGE || cube->left[1][2] != ORANGE)
		return (0);
	return (1);
}

void	checkWhiteFace(t_cube *cube)
{
	if (cube->bottom[0][1] != WHITE || cube->bottom[1][2] != WHITE
	|| cube->bottom[2][1] != WHITE || cube->bottom[1][0] != WHITE)
		usage();
	if (cube->back[0][1] != GREEN || cube->left[2][1] != ORANGE
	|| cube->right[2][1] != RED || cube->front[2][1] != BLUE)
		usage();
	if (cube->bottom[0][0] != WHITE || cube->front[2][0] != BLUE)
		usage();
	if (cube->bottom[2][0] != WHITE || cube->left[2][0] != ORANGE)
		usage();
	if (cube->bottom[2][2] != WHITE || cube->back[0][2] != GREEN)
		usage();
	if (cube->bottom[0][2] != WHITE || cube->right[2][0] != RED)
		usage();
}

void	checkCube(t_cube *cube)
{
	checkWhiteFace(cube);
	!checkSecondLayer(cube) ? usage() : 0;
}
