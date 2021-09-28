#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <time.h>

void    print_shuffle(int n)
{
    int move;
    int previous_move;
    std::vector<std::string> possible_moves{
        "F",
        "F'",
        "F2",
        "B",
        "B'",
        "B2",
        "R",
        "R'",
        "R2",
        "L",
        "L'",
        "L2",
        "U",
        "U'",
        "U2",
        "D",
        "D'",
        "D2",
    };

    srand(time(NULL));
    previous_move = -1;
    for (int i = 0; i < n; i++)
    {
        move = rand() % 18;
        while (move % 3 == previous_move % 3)
            move = rand() % 18;
        std::cout << possible_moves[move] << std::endl;
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
