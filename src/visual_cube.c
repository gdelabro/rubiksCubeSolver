#include "../rubik.h"

void	print_piece(int piece)
{
	piece == WHITE ? ft_printf("{none}\u25A0 {none}"): 0;
	piece == YELLOW ? ft_printf("{yellow}\u25A0 {none}"): 0;
	piece == BLUE ? ft_printf("{blue}\u25A0 {none}"): 0;
	piece == GREEN ? ft_printf("{green}\u25A0 {none}"): 0;
	piece == ORANGE ? ft_printf("{orange}\u25A0 {none}"): 0;
	piece == RED ? ft_printf("{red}\u25A0 {none}") : 0;
}

void	print_face(int face[3][3])
{
	int i;
	int i2;

	i = -1;
	while (++i < 3)
	{
		i2 = -1;
		ft_printf("       ");
		while (++i2 < 3)
			print_piece(face[i][i2]);
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	print_3face(int face[3][3], int face2[3][3], int face3[3][3])
{
	int i;
	int i2;

	i = -1;
	while (++i < 3)
	{
		i2 = -1;
		while (++i2 < 3)
			print_piece(face[i][i2]);
		ft_printf(" ");
		i2 = -1;
		while (++i2 < 3)
			print_piece(face2[i][i2]);
		ft_printf(" ");
		i2 = -1;
		while (++i2 < 3)
			print_piece(face3[i][i2]);
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	showCube(t_cube *cube)
{
	ft_printf("\e[1;1H\e[2J");
	print_face(cube->back);
	print_face(cube->top);
	print_3face(cube->left, cube->front, cube->right);
	print_face(cube->bottom);
	ft_printf("\n");
	cube->p.visual == 2 ? usleep(500000) : 0;
}
