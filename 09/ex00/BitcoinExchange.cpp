/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:41:19 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/24 11:03:16 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(std::string filePath):
	_data(BitcoinExchange::_parseDatabaseFile(filePath))
{
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src):
	_data(src.getData())
{
	return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

BitcoinExchange &	BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	if (this != &rhs)
		this->_data = rhs.getData();
	return (*this);
}

std::map<std::time_t, float> const &	BitcoinExchange::getData(void) const
{
	return (this->_data);
}

std::string	BitcoinExchange::formatDate(time_t date)
{
	struct tm* timeinfo;
	char buffer[11];

	timeinfo = localtime(&date);
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);

	return (buffer);
}

void	BitcoinExchange::importDataFile(std::string filePath)
{
	this->_data = BitcoinExchange::_parseDatabaseFile(filePath);
}

void	BitcoinExchange::clear(void)
{
	this->_data.clear();
}

void	BitcoinExchange::convertBtcFile(std::string filePath) const
{
	if (this->_data.empty())
		throw BitcoinExchange::EmptyDatabaseException();

	std::ifstream ifs(filePath.c_str());
	if (!ifs)
		throw BitcoinExchange::ReadFileException();

	std::string	line;
	bool isFirstLine = true;
	while (std::getline(ifs, line))
	{
		try {
			if (!isFirstLine) {
				std::pair<std::time_t, float>	entry;
				entry = BitcoinExchange::_parseEntry(line, " | ", 1000);

				float rate = this->_findRate(entry.first);
				std::string	timestamp = BitcoinExchange::formatDate(entry.first);

				std::cerr << timestamp << " => " << entry.second << " = " << entry.second * rate << std::endl;
			} else {
				isFirstLine = false;
			}
		} catch(std::runtime_error & e) {
			std::cerr << "Error: " << e.what() << std::endl;
		} catch(std::exception & e) {
			std::cerr << "Error: " << e.what() << "." << std::endl;
		}
	}
	ifs.close();
}

float	BitcoinExchange::_findRate(std::time_t date) const
{
	if (this->_data.size() == 0)
		throw NoRateFound();

	std::map<std::time_t, float>::const_iterator	begin = this->_data.begin();
	if (date < begin->first)
		throw NoRateFound();
	std::map<std::time_t, float>::const_iterator	end = this->_data.end();
	std::map<std::time_t, float>::const_iterator	it = begin;
	float rate = begin->second;
	for (it = begin; it != end; it++) {
		if (date < it->first)
			break;
		rate = it->second;
	}
	return (rate);
}

std::time_t	BitcoinExchange::_parseDate(std::string dateStr)
{
	if (dateStr.size() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
		throw BitcoinExchange::InvalidDateException();
	for (size_t i = 0; i < 10; i++) {
		if (i != 4 && i != 7 && !isdigit(dateStr[i]))
			throw BitcoinExchange::InvalidDateException();
	}

	int year = atoi(dateStr.substr(0, 4).c_str());
	if (year < 1900)
		throw BitcoinExchange::NotAllowedDateException();
	int month = atoi(dateStr.substr(5, 2).c_str());
	if (month < 1 || month > 12)
		throw BitcoinExchange::InvalidDateException();
	int day = atoi(dateStr.substr(8, 2).c_str());
	if (day < 1 || day > 31)
		throw BitcoinExchange::InvalidDateException();
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		throw BitcoinExchange::InvalidDateException();
	if (month == 2) {
		bool isLeapYear = ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
		if (day > 28 + isLeapYear)
			throw BitcoinExchange::InvalidDateException();
	}

	std::tm date = {};
	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;

	return (std::mktime(&date));
}

float	BitcoinExchange::_parseNumber(std::string numStr, float numMax)
{
	if (numStr.empty())
		throw BitcoinExchange::InvalidNumberException();
	bool isDecimalPart = false;
	bool isNegative = (numStr[0] == '-');
	for (size_t i = isNegative; i < numStr.size(); i++) {
		if (!isdigit(numStr[i]) && (numStr[i] != '.' || isDecimalPart))
			throw BitcoinExchange::InvalidNumberException();
		if (numStr[i] == '.')
			isDecimalPart = true;
	}

	float	num = std::atof(numStr.c_str());
	if (num < 0)
		throw BitcoinExchange::NegativeNumberException();
	if (num > numMax)
		throw BitcoinExchange::TooLargeNumberException();
	return (num);
}

std::pair<std::time_t, float>	BitcoinExchange::_parseEntry(std::string entryStr, std::string separator, float numMax)
{
	size_t sepPos = entryStr.find(separator);
	if (sepPos == std::string::npos || sepPos == 0 || sepPos == entryStr.size() - separator.size())
		throw std::runtime_error(std::string("bad input => ") + entryStr);

	std::pair<std::time_t, float> entry;

	std::string dateStr = entryStr.substr(0, sepPos);
	entry.first = BitcoinExchange::_parseDate(dateStr);

	std::string numStr = entryStr.substr(sepPos + separator.size());
	entry.second = BitcoinExchange::_parseNumber(numStr, numMax);
	
	return (entry);
}

std::map<std::time_t, float>	BitcoinExchange::_parseDatabaseFile(std::string filePath)
{
	std::ifstream ifs(filePath.c_str());
	if (!ifs)
		throw BitcoinExchange::ReadFileException();

	std::map<std::time_t, float> data;
	std::string	line;
	int line_nb = 1;
	while (std::getline(ifs, line))
	{
		try {
			if (line_nb > 1)
				data.insert(BitcoinExchange::_parseEntry(line, ",", std::numeric_limits<float>::infinity()));
		} catch(std::exception & e) {
			std::cerr << "Database Import Error: Line " << line_nb << ": `" << line << "`: " << e.what() << std::endl;
		}
		line_nb++;
	}
	ifs.close();

	return (data);
}

std::ostream &	operator<<(std::ostream & o, BitcoinExchange const & x)
{
	std::map<std::time_t, float>	data = x.getData();
	std::map<std::time_t, float>::const_iterator	begin = data.begin();
	std::map<std::time_t, float>::const_iterator	end = data.end();
	std::map<std::time_t, float>::const_iterator	it;
	for (it = begin; it != end; it++)
		std::cout << BitcoinExchange::formatDate(it->first) << "," << it->second << std::endl;
	return (o);
}
