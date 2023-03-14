#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>

class BitcoinExchange {
    private :
        std::string data;
        int value;
        std::string time;
    public :
        BitcoinExchange();
        BitcoinExchange(std::string str);
        BitcoinExchange(BitcoinExchange const & src);
        ~BitcoinExchange();
        BitcoinExchange & operator=(BitcoinExchange const & rhs);
        void add_data(std::string data);
        std::string get_data();
        void print_data();
        int check_data(std::string data);
        int check_time(std::string time);
        int check_price(std::string price);
        
};
#endif