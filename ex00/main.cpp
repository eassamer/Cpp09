#include "BitcoinExchange.hpp"
#include <fstream>

int main(int ac, char **av)
{

    (void)ac;
    std::queue<BitcoinExchange> a;
    std::ifstream f(av[1]);
    if (!f.is_open())
    {
        std::cout << "Error: file not found." << std::endl;
        return 0;
    }
    std::string line;
    while(getline(f, line))
    {
        BitcoinExchange b(line);
        a.push(b);
    }
    while(!a.empty())
    {
        a.pop();
    }
}