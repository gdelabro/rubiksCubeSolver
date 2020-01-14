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

void	showCube(t_cube *cube);

void	rotateFace(t_cube *cube);
void	copyFaceToBuf(int face[3][3], t_cube *cube);
void	copyBufToFront(t_cube *cube);
void	rotationF(t_cube *cube);

#endif
