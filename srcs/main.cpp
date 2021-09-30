#include "../includes/rubik.hpp"

void	ft_swap(char &a, char &b)
{
	char tmp;

	tmp = a;
	a = b;
	b = tmp;
}

int		main(int ac, char **argv)
{
	rubik cube;
    std::vector<std::string> possible_moves {
        "F", "F'", "F2", "B", "B'", "B2", "R", "R'", "R2", "L", "L'", "L2", "U", "U'", "U2", "D", "D'", "D2",
    };
	cube.print_cube();

	if (ac == 1)
	{
		static_cast<void>(argv);
		for (std::string line; std::getline(std::cin, line);)
		{
			cube.handleMovement(line);
			std::cout << line << std::endl;
			cube.print_cube();
		}
	}
	else if (ac == 2)
	{
		std::string arg(static_cast<const char *>(argv[1]));
		std::string substring;
		size_t	pos;

		while ((pos = arg.find(" ")) != std::string::npos)
		{
			substring = arg.substr(0, pos);
			cube.handleMovement(substring);
			std::cout << substring << std::endl;
			cube.print_cube();
			arg.erase(0, pos + 1);
		}
		cube.handleMovement(arg);
		std::cout << arg << std::endl;
		cube.print_cube();
	}
	else
	{
		std::cerr << "Usage:\n./rubik [moves_to_make_separated_by_spaces]\n./rubik (reads on stdin)\n./shuffle [0 < number_of_moves < 1000] | ./rubiks (to shuffle randomly)" << std::endl;
		return (1);
	}
	return (0);
}