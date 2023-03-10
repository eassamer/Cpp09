#include "BitcoinExchange.hpp"
#include <queue>
#include <fstream>
#include <iostream>
int main(int ac, char **av)
{

    (void)ac;
    std::queue<BitcoinExchange> a;
    std::ifstream f(av[1]);
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