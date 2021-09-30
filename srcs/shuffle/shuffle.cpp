
#include "../../includes/solve.hpp"

void    print_shuffle(int n)
{
    int move;
    int previous_move;

    srand(time(NULL));
    previous_move = -1;
    for (int i = 0; i < n; i++)
    {
        move = rand() % 18;
        while (move / 3 == previous_move / 3)
            move = rand() % 18;
        std::cout << possible_moves[move] << std::endl;
		previous_move = move;
    }
}

int main(int ac, char **av)
{
    int nb;

    if (ac != 2)
    {
        std::cerr << "Usage: ./shuffle [0 < number_of_moves < 1000]" << std::endl;
        return (1);
    }
    nb = atoi(av[1]);
    if (nb <= 0 || nb > 1000)
    {
        std::cerr << "Usage: ./shuffle [0 < number_of_moves < 1000]" << std::endl;
        return (1);
    }
    print_shuffle(nb);
    return (0);
}
