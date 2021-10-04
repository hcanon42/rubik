#ifndef RUBIK_HPP
# define RUBIK_HPP

# include "solve.hpp"

class rubik
{
    private:
        std::vector<char> _up;
        std::vector<char> _down;
        std::vector<char> _right;
        std::vector<char> _left;
        std::vector<char> _front;
        std::vector<char> _back;

    public:
        rubik();
        rubik(const rubik &ref);
        ~rubik();

        rubik   			&operator=(rubik const &rhs);
		std::vector<char>	getUp(void) const;
		std::vector<char>	getDown(void) const;
		std::vector<char>	getLeft(void) const;
		std::vector<char>	getRight(void) const;
		std::vector<char>	getFront(void) const;
		std::vector<char>	getBack(void) const;

        void    			handleMovement(std::string move);
		void				basicMovement(std::vector<char> &face);
		void				reverseMovement(std::vector<char> &face);
		void				twiceMovement(std::vector<char> &face);
		void				circularSwap(char &a0, char &a1, char &a2, char &b0, char &b1, char &b2, char &c0, char &c1, char &c2, char &d0, char &d1, char &d2);
		void				oppositeSwap(char &a0, char &a1, char &a2, char &b0, char &b1, char &b2, char &c0, char &c1, char &c2, char &d0, char &d1, char &d2);

		std::string			print_square(char square) const;
		void				print_cube(void) const;

		int					isResolved(void) const;
};

std::vector<std::string>	ft_recur(rubik cube, std::vector<std::string> solution, int beginning, size_t level);
std::vector<std::string>	ft_scale(rubik cube, size_t level);
int							ft_solve(rubik cube, std::vector<std::string> solution);

#endif
