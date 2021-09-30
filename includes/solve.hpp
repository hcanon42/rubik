#ifndef SOLVE_HPP
# define SOLVE_HPP

# include <string>
# include <vector>
# include <iostream>
# include <random>
# include <time.h>

# define WHITE "\033[0m"
# define ORANGE "\033[0;95m"
# define BLUE "\033[0;94m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define RED "\033[0;91m"
# define SQUARE "\u25A0"

std::vector<std::string> const possible_moves({
	"F", "F'", "F2", "B", "B'", "B2", "R", "R'", "R2", "L", "L'", "L2", "U", "U'", "U2", "D", "D'", "D2",
});

void						ft_swap(char &a, char &b);

#endif