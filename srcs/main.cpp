#include "../includes/rubik.hpp"

void	ft_swap(char &a, char &b)
{
	char tmp;

	tmp = a;
	a = b;
	b = tmp;
}

int main()
{
    std::vector<std::string> possible_moves {
        "F", "F'", "F2", "B", "B'", "B2", "R", "R'", "R2", "L", "L'", "L2", "U", "U'", "U2", "D", "D'", "D2",
    };
	rubik cube;

	cube.print_cube();
    for (std::string line; std::getline(std::cin, line);)
	{
		cube.handleMovement(line);
		std::cout << line <<std::endl;
		cube.print_cube();
    }
	return (0);
}