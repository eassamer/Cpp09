#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string str) {
	this->data = str;
	add_data(str);
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs) {
	if (this != &rhs) {
		this->data = rhs.data;
	}
	return *this;
}

int	BitcoinExchange::check_time(std::string time) {
		int count;

	count = 0;
	for (size_t i = 0; i < time.length(); i++) {
		if (time[i] == '-') {
			count++;
		}
	}
	if (count != 2) {
		std::cout << "Invalid time" << std::endl;
		return 0;
	}
	return (1);
}

int	BitcoinExchange::check_price(std::string price)
{
	int count;

	count = 0;
	for (size_t i = 0; i < price.length(); i++) {
		if (price[i] == '.') {
			count++;
		}
	}
	if (count > 1) {
		std::cout << "Invalid price" << std::endl;
		return 0;
	}
	if (price[0] == '-')
	{
		std::cout << "Error: not a positive number." << std::endl;
		return 0;
	}
	//std::cout << price << std::endl;
	for (size_t i = 0; i < price.length(); i++) {
		if (price[i] != '.')
		{
			if (isdigit(price[i]) == 0)
			{
				std::cout << "Error: not a number." << std::endl;
				return 0;
			}
		}
	}
	return 1;
}


void BitcoinExchange::add_data(std::string data) {
	int count;
	float _value;
	std::string _time;
	count = 0;
	for (size_t i = 0; i < data.length(); i++) {
		if (data[i] == '|') {
			count++;
		}
	}
	if (count != 1) {
		std::cout << "Error: bad input => " << data << std::endl;
		return ;
	}
	_time = data.substr(0,data.find('|') - 1);
	//std::cout << _time << std::endl;
	if (check_time(_time) == 0) {
		return ;
	}
	if (check_price(data.substr(data.find('|') + 2, data.length())) == 0) {
		return ;
	}
	_value = atof(data.substr(data.find('|') + 2, data.length()).c_str());
	if (_value > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return ;
	}
	this->time = _time;
	this->value = _value;
	std::ifstream f("data.csv");
	if (!f.is_open())
	{
		std::cout << "Error: file not found." << std::endl;
		return ;
	}
	std::string line;
	float price = -1;
	while(getline(f, line))
	{
		if (strcmp(_time.c_str(), line.substr(0, line.find(',')).c_str()) == 0)
		{

			price = atof(line.substr(line.find(',') + 1, line.size() - 1).c_str());
		}
		else if (strcmp(_time.c_str(), line.substr(0, line.find(',')).c_str()) > 0)
		{
			price = atof(line.substr(line.find(',') + 1, line.size() - 1).c_str());
		}
	}
	if (price == -1)
	{
		std::cout << "Error: no price for this time." << std::endl;
		return ;
	}
	std::cout << this->time << " => " << this->value << " = " << (float)(price * value) << std::endl;
}