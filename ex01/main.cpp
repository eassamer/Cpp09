#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        RPN rpn;
        rpn.add_data(av[1]);
    }
    else
        std::cout << "Error" << std::endl;
    return 0;
}