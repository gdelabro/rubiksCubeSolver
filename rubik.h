#ifndef RCS_H
# define RCS_H

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

#define WHITE 0
#define YELLOW 1
#define BLUE 2
#define GREEN 3
#define ORANGE 4
#define RED 5

typedef struct		s_cube
{
	int			bottom[3][3];		//white
	int			top[3][3];			//yellow
	int			front[3][3];		//blue
	int			back[3][3];			//green
	int			left[3][3];			//orange
	int			right[3][3];		//red
	int			buffer[3][3];		//rotation buffer
}					t_cube;

typedef struct		s_rotation
{
	char		rotType;
	int			P;
	int			two;
}					t_rotation;

void	showCube(t_cube *cube);
void	usage();


void	doAlgo(t_cube *cube, char *algo, int side);


void	rotateFace(int *face);
void	rotateFace2(int *face);
void	copyFaceToFace(int src[3][3], int *dest);


void	rotationF(t_cube *cube);
void	rotationFP(t_cube *cube);
void	rotationF2(t_cube *cube);

void	rotationR(t_cube *cube);
void	rotationRP(t_cube *cube);
void	rotationR2(t_cube *cube);

void	rotationU(t_cube *cube);
void	rotationUP(t_cube *cube);
void	rotationU2(t_cube *cube);

void	rotationB(t_cube *cube);
void	rotationBP(t_cube *cube);
void	rotationB2(t_cube *cube);

void	rotationL(t_cube *cube);
void	rotationLP(t_cube *cube);
void	rotationL2(t_cube *cube);

void	rotationD(t_cube *cube);
void	rotationDP(t_cube *cube);
void	rotationD2(t_cube *cube);

#endif