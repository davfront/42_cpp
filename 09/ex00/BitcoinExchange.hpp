/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dapereir <dapereir@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:41:22 by dapereir          #+#    #+#             */
/*   Updated: 2023/09/24 11:03:17 by dapereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <cstdlib>
# include <ctime>
# include <exception>
# include <fstream>
# include <iostream>
# include <limits>
# include <sstream>
# include <string>
# include <map>

class BitcoinExchange {

	private:

		std::map<std::time_t, float>	_data;

		float	_findRate(std::time_t date) const;

		static std::time_t						_parseDate(std::string dateStr);
		static float							_parseNumber(std::string rateStr, float numMax);
		static std::pair<std::time_t, float>	_parseEntry(std::string entryStr, std::string separator, float numMax);
		static std::map<std::time_t, float>		_parseDatabaseFile(std::string filePath);

	public:

		BitcoinExchange(void);
		BitcoinExchange(std::string filePath);
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange(void);

		BitcoinExchange &	operator=(BitcoinExchange const & rhs);

		std::map<std::time_t, float> const &	getData(void) const;

		void	importDataFile(std::string filePath);
		void	clear(void);
		void	printData(void) const;
		void	convertBtcFile(std::string filePath) const;

		static std::string	formatDate(time_t date);

		class ReadFileException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "could not open file";
				}
		};
		
		class InvalidEntryException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "bad input";
				}
		};
		
		class InvalidDateException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "invalid date";
				}
		};
		
		class NotAllowedDateException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "dates before 1900 are not allowed";
				}
		};
		
		class NegativeNumberException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "not a positive number";
				}
		};
		
		class TooLargeNumberException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "too large number";
				}
		};
		
		class InvalidNumberException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "invalid number";
				}
		};
		
		class NoRateFound: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "no rate found";
				}
		};

		class EmptyDatabaseException: public std::exception {
			public:
				virtual const char* what() const throw() {
					return "empty database";
				}
		};

};

std::ostream &	operator<<(std::ostream & o, BitcoinExchange const & x);

#endif


