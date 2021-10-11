#include "../includes/rubik.hpp"

void	ft_flip_edge(rubik cube, std::vector<std::string> solution)
{
	cube.handleMovement("F");
	cube.handleMovement("U'");
	cube.handleMovement("R");
	cube.handleMovement("U");
}

void	ft_from_bottom_layer(rubik cube, std::vector<std::string> solution)
{
	cube.handleMovement("F'");
	cube.handleMovement("U'");
	cube.handleMovement("R");
	cube.handleMovement("U");	
}

void	ft_from_right_layer(rubik cube, std::vector<std::string> solution)
{
	cube.handleMovement("U'");
	cube.handleMovement("R");
	cube.handleMovement("U");	
}

void	ft_from_left_layer(rubik cube, std::vector<std::string> solution)
{
	cube.handleMovement("U");
	cube.handleMovement("L'");
	cube.handleMovement("U'");	
}

int		ft_solve_white_cross(rubik cube, std::vector<std::string> solution)
{
	
}