#include "../rubik.h"

void	randomScrambler(int moveNumber, t_cube *cube)
{
	int				i;
	int				move;
	int				lastmove;
	static int		call = 0;

	if (moveNumber > 100)
		usage();
	call++;
	char	scramble[moveNumber * 3 + 1];
	memset(scramble, ' ', moveNumber * 3);
	scramble[moveNumber * 3] = 0;
	i = -1;
	if (call == 1)
		srand(time(NULL));
	srand(rand());
	lastmove = -1;
	while (++i < moveNumber)
	{
		move = rand() % 18;
		move % 6 == lastmove % 6 ? move = move + 1 % 18 : 0;
		move % 6 == 0 ? scramble[i * 3] = 'F' : 0;
		move % 6 == 1 ? scramble[i * 3] = 'R' : 0;
		move % 6 == 2 ? scramble[i * 3] = 'U' : 0;
		move % 6 == 3 ? scramble[i * 3] = 'B' : 0;
		move % 6 == 4 ? scramble[i * 3] = 'L' : 0;
		move % 6 == 5 ? scramble[i * 3] = 'D' : 0;

		move / 6 == 1 ? scramble[i * 3 + 1] = '\'' : 0;
		move / 6 == 2 ? scramble[i * 3 + 1] = '2' : 0;
		lastmove = move;
	}
	doAlgo(cube, scramble, 0, 0);
	ft_printf("%s\n", scramble);
}
