#ifndef RUBIK_HPP
# define RUBIK_HPP

# include <vector>
# include <string>

class rubik
{
    private:
        std::vector<char> up;
        std::vector<char> down;
        std::vector<char> right;
        std::vector<char> left;
        std::vector<char> front;
        std::vector<char> back;

    public:
        rubik();
        rubik(const rubik &ref);
        ~rubik();

        rubik   &operator=(rubik const &rhs);
        void    handle_movement(std::string move);
};

#endif
