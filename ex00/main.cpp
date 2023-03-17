#include "BitcoinExchange.hpp"
#include <fstream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 0;
    }
    std::queue<BitcoinExchange> a;
    std::ifstream f(av[1]);
    if (!f.is_open())
    {
        std::cout << "Error: could not open file." << std::endl;
        return 0;
    }
    std::string line;
    while(getline(f, line))
    {
        if (line.size() == 0 || line[0] == 'd')
            continue;
        BitcoinExchange b(line);
        a.push(b);
    }
    while(!a.empty())
    {
        
        a.pop();
    }
}