#include "rubik.hpp"

rubik::rubik() : _up(std::vector<char>{'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'}),
				_down(std::vector<char>{'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y'}),
				_front(std::vector<char>{'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'}),
				_back(std::vector<char>{'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g', 'g'}),
				_right(std::vector<char>{'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'}),
				_left(std::vector<char>{'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r'})
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

void	rubik::basicMovement(std::vector<char> face)
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

void	rubik::reverseMovement(std::vector<char> face)
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

void	rubik::twiceMovement(std::vector<char> face)
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
	if (move.compare("R"))
	{
		basicMovement(this->_right);
		circularSwap(this->_front[2], this->_front[5], this->_front[8], this->_up[2], this->_up[5], this->_up[8], this->_back[6], this->_back[3], this->_back[0], this->_down[2], this->_down[5], this->_down[8]);
	}
	else if (move.compare("R'"))
	{
		reverseMovement(this->_right);
		circularSwap(this->_front[2], this->_front[5], this->_front[8], this->_down[2], this->_down[5], this->_down[8], this->_back[6], this->_back[3], this->_back[0], this->_up[2], this->_up[5], this->_up[8]);
	}
	else if (move.compare("R2"))
	{
		twiceMovement(this->_right);
		oppositeSwap(this->_front[2], this->_front[5], this->_front[8], this->_up[2], this->_up[5], this->_up[8], this->_back[6], this->_back[3], this->_back[0], this->_down[2], this->_down[5], this->_down[8]);
	}
	else if (move.compare("L"))
	{
		basicMovement(this->_left);
		circularSwap(this->_front[0], this->_front[3], this->_front[6], this->_down[0], this->_down[3], this->_down[6], this->_back[8], this->_back[5], this->_back[2], this->_up[0], this->_up[3], this->_up[6]);
	}
	else if (move.compare("L'"))
	{
		reverseMovement(this->_left);
		circularSwap(this->_front[0], this->_front[3], this->_front[6], this->_up[0], this->_up[3], this->_up[6], this->_back[8], this->_back[5], this->_back[2], this->_down[0], this->_down[3], this->_down[6]);
	}
	else if (move.compare("L2"))
	{
		twiceMovement(this->_left);
		oppositeSwap(this->_front[0], this->_front[3], this->_front[6], this->_up[0], this->_up[3], this->_up[6], this->_back[8], this->_back[5], this->_back[2], this->_down[0], this->_down[3], this->_down[6]);
	}
}