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

void	checkYellowFace(t_cube *cube)
{
	if (cube->top[0][1] != YELLOW || cube->top[1][2] != YELLOW
	|| cube->top[2][1] != YELLOW || cube->top[1][0] != YELLOW)
		usage();
	if (cube->top[0][0] != YELLOW || cube->top[0][2] != YELLOW
	|| cube->top[2][0] != YELLOW || cube->top[2][2] != YELLOW)
		usage();
}

void	checkLastLayer(t_cube *cube)
{
	if (cube->front[0][0] != cube->front[0][2] || cube->front[0][1] != BLUE)
		usage();
	if (cube->right[0][0] != cube->right[0][2] || cube->right[0][1] != RED)
		usage();
	if (cube->back[2][0] != cube->back[2][2]  || cube->back[2][1] != GREEN)
		usage();
	if (cube->left[0][0] != cube->left[0][2] || cube->left[0][1] != ORANGE)
		usage();
}

void	checkCube(t_cube *cube)
{
	checkWhiteFace(cube);
	!checkSecondLayer(cube) ? usage() : 0;
	checkYellowFace(cube);
	checkLastLayer(cube);
}
