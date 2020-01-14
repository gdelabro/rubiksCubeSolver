#include "../rubik.h"

void	copyBufToFront(t_cube *cube)
{
	cube->front[0][0] = cube->buffer[0][0];
	cube->front[0][1] = cube->buffer[0][1];
	cube->front[0][2] = cube->buffer[0][2];
	cube->front[1][0] = cube->buffer[1][0];
	cube->front[1][1] = cube->buffer[1][1];
	cube->front[1][2] = cube->buffer[1][2];
	cube->front[2][0] = cube->buffer[2][0];
	cube->front[2][1] = cube->buffer[2][1];
	cube->front[2][2] = cube->buffer[2][2];
}

void	copyFaceToBuf(int face[3][3], t_cube *cube)
{
	cube->buffer[0][0] = face[0][0];
	cube->buffer[0][1] = face[0][1];
	cube->buffer[0][2] = face[0][2];
	cube->buffer[1][0] = face[1][0];
	cube->buffer[1][1] = face[1][1];
	cube->buffer[1][2] = face[1][2];
	cube->buffer[2][0] = face[2][0];
	cube->buffer[2][1] = face[2][1];
	cube->buffer[2][2] = face[2][2];
}

void	rotateFace(t_cube *cube)
{
	int		buffer[3][3];

	buffer[0][0] = cube->buffer[2][0];
	buffer[0][1] = cube->buffer[1][0];
	buffer[0][2] = cube->buffer[0][0];
	buffer[1][0] = cube->buffer[2][1];
	buffer[1][1] = cube->buffer[1][1];
	buffer[1][2] = cube->buffer[0][1];
	buffer[2][0] = cube->buffer[2][2];
	buffer[2][1] = cube->buffer[1][2];
	buffer[2][2] = cube->buffer[0][2];
	copyFaceToBuf(buffer, cube);
}
