
#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe p;
    try
    {
        (void)ac;
        p.sorter(av);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}