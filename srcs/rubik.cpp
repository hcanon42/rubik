#include "../includes/rubik.hpp"

rubik::rubik() : _up(std::vector<char>{'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'}),
				_down(std::vector<char>{'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y'}),
				_right(std::vector<char>{'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'}),
				_left(std::vector<char>{'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r'}),
				_front(std::vector<char>{'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'}),
				_back(std::vector<char>{'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g'})
{
}

rubik::~rubik()
{
}

rubik::rubik(const rubik &ref)
{
	*this = ref;
}

std::vector<char>	rubik::getUp(void) const
{
	return (this->_up);
}

std::vector<char>	rubik::getDown(void) const
{
	return (this->_down);
}

std::vector<char>	rubik::getLeft(void) const
{
	return (this->_left);
}

std::vector<char>	rubik::getRight(void) const
{
	return (this->_right);
}

std::vector<char>	rubik::getFront(void) const
{
	return (this->_front);
}

std::vector<char>	rubik::getBack(void) const
{
	return (this->_back);
}

rubik   &rubik::operator=(rubik const &rhs)
{
	this->_up = rhs.getUp();
	this->_down = rhs.getDown();
	this->_left = rhs.getLeft();
	this->_right = rhs.getRight();
	this->_front = rhs.getFront();
	this->_back = rhs.getBack();
	return (*this);
}

void	rubik::basicMovement(std::vector<char> &face)
{
	char	tmp;

	tmp = face[8];
	face[8] = face[2];
	face[2] = face[0];
	face[0] = face[6];
	face[6] = tmp;
	tmp = face[1];
	face[1] = face[3];
	face[3] = face[7];
	face[7] = face[5];
	face[5] = tmp;
}

void	rubik::reverseMovement(std::vector<char> &face)
{
	char	tmp;

	tmp = face[8];
	face[8] = face[6];
	face[6] = face[0];
	face[0] = face[2];
	face[2] = tmp;
	tmp = face[1];
	face[1] = face[5];
	face[5] = face[7];
	face[7] = face[3];
	face[3] = tmp;
}

void	rubik::twiceMovement(std::vector<char> &face)
{
	ft_swap(face[0], face[8]);
	ft_swap(face[1], face[7]);
	ft_swap(face[2], face[6]);
	ft_swap(face[3], face[5]);
}

void	rubik::circularSwap(char &a0, char &a1, char &a2, char &b0, char &b1, char &b2, char &c0, char &c1, char &c2, char &d0, char &d1, char &d2)
{
	char tmp;

	tmp = a0;
	a0 = d0;
	d0 = c0;
	c0 = b0;
	b0 = tmp;
	tmp = a1;
	a1 = d1;
	d1 = c1;
	c1 = b1;
	b1 = tmp;
	tmp = a2;
	a2 = d2;
	d2 = c2;
	c2 = b2;
	b2 = tmp;
}

void	rubik::oppositeSwap(char &a0, char &a1, char &a2, char &b0, char &b1, char &b2, char &c0, char &c1, char &c2, char &d0, char &d1, char &d2)
{
	ft_swap(a0, c0);
	ft_swap(a1, c1);
	ft_swap(a2, c2);
	ft_swap(b0, d0);
	ft_swap(b1, d1);
	ft_swap(b2, d2);
}

void    rubik::handleMovement(std::string move)
{
	if (move.compare("R") == 0)
	{
		basicMovement(this->_right);
		circularSwap(this->_front[2], this->_front[5], this->_front[8], this->_up[2], this->_up[5], this->_up[8], this->_back[6], this->_back[3], this->_back[0], this->_down[2], this->_down[5], this->_down[8]);
	}
	else if (move.compare("R'") == 0)
	{
		reverseMovement(this->_right);
		circularSwap(this->_front[2], this->_front[5], this->_front[8], this->_down[2], this->_down[5], this->_down[8], this->_back[6], this->_back[3], this->_back[0], this->_up[2], this->_up[5], this->_up[8]);
	}
	else if (move.compare("R2") == 0)
	{
		twiceMovement(this->_right);
		oppositeSwap(this->_front[2], this->_front[5], this->_front[8], this->_up[2], this->_up[5], this->_up[8], this->_back[6], this->_back[3], this->_back[0], this->_down[2], this->_down[5], this->_down[8]);
	}
	else if (move.compare("L") == 0)
	{
		basicMovement(this->_left);
		circularSwap(this->_front[0], this->_front[3], this->_front[6], this->_down[0], this->_down[3], this->_down[6], this->_back[8], this->_back[5], this->_back[2], this->_up[0], this->_up[3], this->_up[6]);
	}
	else if (move.compare("L'") == 0)
	{
		reverseMovement(this->_left);
		circularSwap(this->_front[0], this->_front[3], this->_front[6], this->_up[0], this->_up[3], this->_up[6], this->_back[8], this->_back[5], this->_back[2], this->_down[0], this->_down[3], this->_down[6]);
	}
	else if (move.compare("L2") == 0)
	{
		twiceMovement(this->_left);
		oppositeSwap(this->_front[0], this->_front[3], this->_front[6], this->_up[0], this->_up[3], this->_up[6], this->_back[8], this->_back[5], this->_back[2], this->_down[0], this->_down[3], this->_down[6]);
	}
	else if (move.compare("U") == 0)
	{
		basicMovement(this->_up);
		circularSwap(this->_front[0], this->_front[1], this->_front[2], this->_left[0], this->_left[1], this->_left[2], this->_back[0], this->_back[1], this->_back[2], this->_right[0], this->_right[1], this->_right[2]);
	}
	else if (move.compare("U'") == 0)
	{
		reverseMovement(this->_up);
		circularSwap(this->_front[0], this->_front[1], this->_front[2], this->_right[0], this->_right[1], this->_right[2], this->_back[0], this->_back[1], this->_back[2], this->_left[0], this->_left[1], this->_left[2]);
	}
	else if (move.compare("U2") == 0)
	{
		twiceMovement(this->_up);
		oppositeSwap(this->_front[0], this->_front[1], this->_front[2], this->_left[0], this->_left[1], this->_left[2], this->_back[0], this->_back[1], this->_back[2], this->_right[0], this->_right[1], this->_right[2]);
	}
	else if (move.compare("D") == 0)
	{
		basicMovement(this->_down);
		circularSwap(this->_front[6], this->_front[7], this->_front[8], this->_right[6], this->_right[7], this->_right[8], this->_back[6], this->_back[7], this->_back[8], this->_left[6], this->_left[7], this->_left[8]);
	}
	else if (move.compare("D'") == 0)
	{
		reverseMovement(this->_down);
		circularSwap(this->_front[6], this->_front[7], this->_front[8], this->_left[6], this->_left[7], this->_left[8], this->_back[6], this->_back[7], this->_back[8], this->_right[6], this->_right[7], this->_right[8]);
	}
	else if (move.compare("D2") == 0)
	{
		twiceMovement(this->_down);
		oppositeSwap(this->_front[6], this->_front[7], this->_front[8], this->_right[6], this->_right[7], this->_right[8], this->_back[6], this->_back[7], this->_back[8], this->_left[6], this->_left[7], this->_left[8]);
	}
	else if (move.compare("F") == 0)
	{
		basicMovement(this->_front);
		circularSwap(this->_up[6], this->_up[7], this->_up[8], this->_right[0], this->_right[3], this->_right[6], this->_down[2], this->_down[1], this->_down[0], this->_left[8], this->_left[5], this->_left[2]);
	}
	else if (move.compare("F'") == 0)
	{
		reverseMovement(this->_front);
		circularSwap(this->_up[6], this->_up[7], this->_up[8], this->_left[8], this->_left[5], this->_left[2], this->_down[2], this->_down[1], this->_down[0], this->_right[0], this->_right[3], this->_right[6]);
	}
	else if (move.compare("F2") == 0)
	{
		twiceMovement(this->_front);
		oppositeSwap(this->_up[6], this->_up[7], this->_up[8], this->_right[0], this->_right[3], this->_right[6], this->_down[2], this->_down[1], this->_down[0], this->_left[8], this->_left[5], this->_left[2]);
	}
	else if (move.compare("B") == 0)
	{
		basicMovement(this->_back);
		circularSwap(this->_up[0], this->_up[1], this->_up[2], this->_left[6], this->_left[3], this->_left[0], this->_down[8], this->_down[7], this->_down[6], this->_right[2], this->_right[5], this->_right[8]);
	}
	else if (move.compare("B'") == 0)
	{
		reverseMovement(this->_back);
		circularSwap(this->_up[0], this->_up[1], this->_up[2], this->_right[2], this->_right[5], this->_right[8], this->_down[8], this->_down[7], this->_down[6], this->_left[6], this->_left[3], this->_left[0]);
	}
	else if (move.compare("B2") == 0)
	{
		twiceMovement(this->_back);
		oppositeSwap(this->_up[0], this->_up[1], this->_up[2], this->_left[6], this->_right[3], this->_right[0], this->_down[8], this->_down[7], this->_down[6], this->_right[2], this->_right[5], this->_right[8]);
	}
	else
	{
		std::cerr << "Illegal Move !" << std::endl;
		exit(1);
	}
}

std::string	rubik::print_square(char square) const
{
	std::string to_ret;

	to_ret = "";
	if (square == 'w')
		to_ret = WHITE;
	else if (square == 'r')
		to_ret = RED;
	else if (square == 'y')
		to_ret = YELLOW;
	else if (square == 'g')
		to_ret = GREEN;
	else if (square == 'b')
		to_ret = BLUE; 
	else if (square == 'o')
		to_ret = ORANGE;
	to_ret += SQUARE;
	return (to_ret);
}

void	rubik::print_cube(void) const
{
	std::cout << "      " << print_square(this->_up[0]) << " " << print_square(this->_up[1]) << " " << print_square(this->_up[2]) << "      " << std::endl;
	std::cout << "      " << print_square(this->_up[3]) << " " << print_square(this->_up[4]) << " " << print_square(this->_up[5]) << "      " << std::endl;
	std::cout << "      " << print_square(this->_up[6]) << " " << print_square(this->_up[7]) << " " << print_square(this->_up[8]) << "      " << std::endl;
	std::cout << print_square(this->_left[0]) << " " << print_square(this->_left[1]) << " " << print_square(this->_left[2]) << " " << print_square(this->_front[0]) << " " << print_square(this->_front[1]) << " " << print_square(this->_front[2]) << " " << print_square(this->_right[0]) << " " << print_square(this->_right[1]) << " " << print_square(this->_right[2]) << std::endl;
	std::cout << print_square(this->_left[3]) << " " << print_square(this->_left[4]) << " " << print_square(this->_left[5]) << " " << print_square(this->_front[3]) << " " << print_square(this->_front[4]) << " " << print_square(this->_front[5]) << " " << print_square(this->_right[3]) << " " << print_square(this->_right[4]) << " " << print_square(this->_right[5]) << std::endl;
	std::cout << print_square(this->_left[6]) << " " << print_square(this->_left[7]) << " " << print_square(this->_left[8]) << " " << print_square(this->_front[6]) << " " << print_square(this->_front[7]) << " " << print_square(this->_front[8]) << " " << print_square(this->_right[6]) << " " << print_square(this->_right[7]) << " " << print_square(this->_right[8]) << std::endl;
	std::cout << "      " << print_square(this->_down[0]) << " " << print_square(this->_down[1]) << " " << print_square(this->_down[2]) << "      " << std::endl;
	std::cout << "      " << print_square(this->_down[3]) << " " << print_square(this->_down[4]) << " " << print_square(this->_down[5]) << "      " << std::endl;
	std::cout << "      " << print_square(this->_down[6]) << " " << print_square(this->_down[7]) << " " << print_square(this->_down[8]) << "      " << std::endl;
	std::cout << "      " << print_square(this->_back[8]) << " " << print_square(this->_back[7]) << " " << print_square(this->_back[6]) << "      " << std::endl;
	std::cout << "      " << print_square(this->_back[5]) << " " << print_square(this->_back[4]) << " " << print_square(this->_back[3]) << "      " << std::endl;
	std::cout << "      " << print_square(this->_back[2]) << " " << print_square(this->_back[1]) << " " << print_square(this->_back[0]) << "      " << std::endl;
	std::cout << WHITE << std::endl << std::endl;

}