#include "../includes/rubik.hpp"

void	ft_swap(char &a, char &b)
{
	char tmp;

	tmp = a;
	a = b;
	b = tmp;
}

void	ft_parse(rubik &cube, char **argv)
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
	if (arg.compare("") != 0)
	{
		cube.handleMovement(arg);
		std::cout << arg << std::endl;
		cube.print_cube();
	}
}

void	ft_handle_cin(rubik &cube)
{
	std::cout << "press ^D (ctrl-D) when you have finished shuffling the cube" << std::endl;
	for (std::string line; std::getline(std::cin, line);)
	{
		cube.handleMovement(line);
		std::cout << line << std::endl;
		cube.print_cube();
	}
}

int		main(int ac, char **argv)
{
	rubik						cube;
	std::vector<std::string>	solution;

	cube.print_cube();
	if (ac == 1)
	{
		static_cast<void>(argv);
		ft_handle_cin(cube);
	}
	else if (ac == 2)
		ft_parse(cube, argv);
	else
	{
		std::cerr << "Usage:\n./rubik [moves_to_make_separated_by_spaces]\n./rubik (reads on stdin)\n./shuffle [0 < number_of_moves < 1000] | ./rubiks (to shuffle randomly)" << std::endl;
		return (1);
	}
	ft_solve_white_cross(cube, solution);
	cube.print_cube();
	for (size_t i = 0; i < solution.size(); i++)
	{
		cube.handleMovement(solution[i]);
		std::cout << solution[i] << std::endl;
		cube.print_cube();
	}
	return (0);
}