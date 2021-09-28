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
	rubik cube;
	cube.print_cube();
	cube.handleMovement("R'");
	std::cout <<"R'"<<std::endl;
	cube.print_cube();
	cube.handleMovement("L");
	std::cout <<"L"<<std::endl;
	cube.print_cube();
	cube.handleMovement("D2");
	std::cout << "D2" <<std::endl;
	cube.print_cube();
	cube.handleMovement("F'");
	std::cout <<"F'"<<std::endl;
	cube.print_cube();
	return (0);
}