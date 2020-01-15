#include "../rubik.h"

void	copyFaceToFace(int src[3][3], int *dest)
{
	*(dest + 0) = src[0][0];
	*(dest + 1) = src[0][1];
	*(dest + 2) = src[0][2];
	*(dest + 3) = src[1][0];
	*(dest + 4) = src[1][1];
	*(dest + 5) = src[1][2];
	*(dest + 6) = src[2][0];
	*(dest + 7) = src[2][1];
	*(dest + 8) = src[2][2];
}

/*    ->
    O O O
    O O O |
    O O O v
*/

void	rotateFace(int *face)
{
	int		buffer[3][3];

	buffer[0][0] = *(face + 6);
	buffer[0][1] = *(face + 3);
	buffer[0][2] = *(face + 0);
	buffer[1][0] = *(face + 7);
	buffer[1][1] = *(face + 4);
	buffer[1][2] = *(face + 1);
	buffer[2][0] = *(face + 8);
	buffer[2][1] = *(face + 5);
	buffer[2][2] = *(face + 2);
	copyFaceToFace(buffer, face);
}

void	rotateFace2(int *face)
{
	int		buffer[3][3];

	buffer[0][0] = *(face + 2);
	buffer[0][1] = *(face + 5);
	buffer[0][2] = *(face + 8);
	buffer[1][0] = *(face + 1);
	buffer[1][1] = *(face + 4);
	buffer[1][2] = *(face + 7);
	buffer[2][0] = *(face + 0);
	buffer[2][1] = *(face + 3);
	buffer[2][2] = *(face + 6);
	copyFaceToFace(buffer, face);
}
