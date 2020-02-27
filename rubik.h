#ifndef RCS_H
# define RCS_H

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "ft_printf/ft_printf.h"

#define SEPARATOR "\n"

#define WHITE -1
#define YELLOW -2
#define BLUE 0
#define GREEN 2
#define ORANGE 3
#define RED 1

typedef struct		s_pars
{
	int			silent;  // -s        n'affiche pas chaque coup
	int			infinite; //-ixx      aff melange + random scramble illiminte
	int			random; //-rxx        affiche le melange de xx coup
	int			count; //-c           afficher nombre de coup
	int			visual;//-vw          peut etre faire 2 modes, dont un qui affiche seulement les etapes
	int			stat; //-t            affiche des stats
	int			i;
}					t_pars;

typedef struct		s_cube
{
	int			bottom[3][3];		//white
	int			top[3][3];			//yellow
	int			front[3][3];		//blue
	int			back[3][3];			//green
	int			left[3][3];			//orange
	int			right[3][3];		//red
	int			buffer[3][3];		//rotation buffer
	int			count;
	int			countall;
	int			lowestcount;
	int			biggestcount;
	int			cubeNumber;
	t_pars		p;
}					t_cube;

typedef struct		s_rotation
{
	char		rotType;
	int			P;
	int			two;
}					t_rotation;

typedef struct		s_arete
{
	int			color;
	int			color2;
	int			color3;
	int			side;
	int			layer;
}					t_arete;

void	parser(t_cube *cube, char **av);

void	showCube(t_cube *cube);
void	checkCube(t_cube *cube);
int		checkSecondLayer(t_cube *cube);
void	usage();
void	randomScrambler(int moveNumber, t_cube *cube);


void	doAlgo(t_cube *cube, char *algo, int side, int aff);


void	rotateFace(int *face);
void	rotateFace2(int *face);
void	copyFaceToFace(int src[3][3], int *dest);


void	rotationF(t_cube *cube, int aff);
void	rotationFP(t_cube *cube, int aff);
void	rotationF2(t_cube *cube, int aff);

void	rotationR(t_cube *cube, int aff);
void	rotationRP(t_cube *cube, int aff);
void	rotationR2(t_cube *cube, int aff);

void	rotationU(t_cube *cube, int aff);
void	rotationUP(t_cube *cube, int aff);
void	rotationU2(t_cube *cube, int aff);

void	rotationB(t_cube *cube, int aff);
void	rotationBP(t_cube *cube, int aff);
void	rotationB2(t_cube *cube, int aff);

void	rotationL(t_cube *cube, int aff);
void	rotationLP(t_cube *cube, int aff);
void	rotationL2(t_cube *cube, int aff);

void	rotationD(t_cube *cube, int aff);
void	rotationDP(t_cube *cube, int aff);
void	rotationD2(t_cube *cube, int aff);


void	solveWhiteCross(t_cube *cube);
void	solveWhiteFace(t_cube *cube);
void	solveSecondLayer(t_cube *cube);
void	solveYellowCross(t_cube *cube);
void	solveYellowFace(t_cube *cube);
void	orientCorners(t_cube *cube);
void	orientMiddle(t_cube *cube);

void	findArete(t_arete *ar, t_cube *cube);
void	findCorner(t_arete *ar, t_cube *cube);

#endif
