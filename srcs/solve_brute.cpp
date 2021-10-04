#include "../includes/rubik.hpp"

std::vector<std::string>	ft_recur(rubik cube, std::vector<std::string> solution, int beginning, size_t level)
{
	if (beginning == 0)
		cube.handleMovement(solution[solution.size() - 1]);
	if (solution.size() == level && cube.isResolved() == 1)
		return (solution);
	if (solution.size() >= level)
		return (std::vector<std::string>());
	for (size_t i = 0; i < possible_moves.size(); i++)
	{
		if ((solution.empty() == 1) || possible_moves[i][0] != solution[solution.size() - 1][0])
		{
			std::vector<std::string> tmp(solution);
			tmp.push_back(possible_moves[i]);
			std::vector<std::string> new_solution = ft_recur(rubik(cube), tmp, 0, level);
			if (!new_solution.empty())
				return (new_solution);
		}
	}
	return (std::vector<std::string>());
}