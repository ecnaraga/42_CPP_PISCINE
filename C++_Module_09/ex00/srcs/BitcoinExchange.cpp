/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:57:35 by galambey          #+#    #+#             */
/*   Updated: 2024/06/07 11:47:21 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

BitCoinExchange::BitCoinExchange() {
	try
	{
		this->get_database();
	}
	catch(std::bad_alloc const & e) { throw; }
	catch (std::exception const & e) { throw ; }
}

BitCoinExchange::BitCoinExchange(BitCoinExchange & orig) {
	try
	{
		*this = orig;
	}
	catch(std::bad_alloc const & e) { throw; }
}

BitCoinExchange::~BitCoinExchange() {}

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

BitCoinExchange & BitCoinExchange::operator=(BitCoinExchange & rhs) {
	try
	{
		this->_database = rhs._database;
	}
	catch(std::bad_alloc const & e) { throw; }
	return (*this);
}


/* ************************************************************************* */
/* ******************************* EXCEPTIONS ****************************** */
/* ************************************************************************* */
const char * BitCoinExchange::InvalidDatabase::what() const throw() {
	return ("Error: invalid database file");
}

const char * BitCoinExchange::NotAValidFile::what() const throw() {
	return ("Error: invalid file");
}

const char * BitCoinExchange::BadInputException::what() const throw() {
	return ("Error: bad input => ");
}

const char * BitCoinExchange::NotAValidDateException::what() const throw() {
	return ("Error: not a valid date.");
}

const char * BitCoinExchange::NotAPositiveNumberException::what() const throw() {
	return ("Error: not a positive number.");
}

const char * BitCoinExchange::TooLargeNumberException::what() const throw() {
	return ("Error: too large a number.");
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

void	BitCoinExchange::get_database(void) {
	
	std::ifstream 	database;
	std::string 	line;
	std::string 	date;
	
	database.exceptions(std::ifstream::failbit);
	try {
		database.open("data.csv", std::ifstream::in);
	}
	catch(std::ifstream::failure) { throw (InvalidDatabase()); }
	if (!database.good())
		throw (InvalidDatabase());
	getline(database, line, '\n');
	if (line.empty())
		throw (InvalidDatabase());
	while (1)
	{
		try
		{
			/* Get the date and the change rate */
			getline(database, date, ',');
			if (date.empty())
				break;
			getline(database, line, '\n');
			if (line.empty())
				break;
				
			/* Stock it into the map container database */
			std::istringstream iss(line);
			iss >> this->_database[date];
		}
		catch(std::bad_alloc const & e) { throw; }
		catch(std::ifstream::failure const & e) { break; }
	}
}

void	BitCoinExchange::check_ymd(int date, int year, int i) {
	
	switch (i)
	{
		case 0:
		{
			if (date < 0 || date > 2024)
				throw (NotAValidDateException());
			break;
		}
		case 1:
		{
			if (date < 1 || date > 12)
				throw (NotAValidDateException());
			break;
		}
		case 2:
		{
			if (date < 1 || (year % 4 != 0 && date > 30) || (year % 4 == 0 && date > 31))
				throw (NotAValidDateException());
			break;
		}
		default:
			break;
	}
}

void	BitCoinExchange::check_date(std::string const & date) {
	
	std::istringstream iss(date);
	int nb;
	int year = 0;

	for (int i = 0; date[i] && date[i]; i++)
	{
		if ((i == 4 || i == 7) && date[i] != '-')
			throw (NotAValidDateException());
		else if (!(i == 4 || i == 7) && !isdigit(date[i]))	
			throw (NotAValidDateException());
	}
	for (int i = 0; i < 3; i++)
	{
		iss >> nb;
		try
		{
			check_ymd(nb, year, i);
			if (i == 0)
				year = nb;
		}
		catch (std::exception & e)
		{
			throw ;
		}
		iss.get();
	}
}
double	BitCoinExchange::check_value(std::string const & value) {
	
	std::istringstream	iss(value);
	double				value_f;
	int					pt = 0;

	for (int i = 0; value[i]; i++)
	{
		if ((!isdigit(value[i]) && value[i] != '.') || (value[i] == '.' && (i == 0 || !value[i + 1] || pt > 0)))
			throw (NotAPositiveNumberException());
		if (value[i] == '.')
			pt++;
	}
	iss >> value_f;
	if (value_f < 0.000)
		throw (NotAPositiveNumberException());
	if (value_f > 1000.000)
		throw (TooLargeNumberException());
	return (value_f);
}

void	BitCoinExchange::get_input(std::ifstream & input) {
	
	std::string	line;
	std::string	date;
	std::string	value;
	float		value_f;
	std::string::size_type found;
	
	input.exceptions(std::ifstream::failbit);
	try
	{
		getline(input, line, '\n'); // ATTENTION PAS PROTEGE
		if (line != "date | value")
			throw(NotAValidFile());
	}
	catch (std::ifstream::failure const & e)
	{
		std::cerr << "Error: empty file" << std::endl;
		return ;
	}
	while(1)
	{
		try
		{
			getline(input, line, '\n');
			found = line.find(" | ");
			try
			{
				if (found == std::string::npos || found != 10 || line.length() < 14) // Permet de check si  le " | " est bien positionner + si assez de char dans la date
					throw(BadInputException());
			}
			catch (std::exception const & e)
			{
				std::cout << e.what() << line << std::endl;
				continue;
			}
			std::istringstream iss(line);
			getline(iss, date, ' '); // recupere la date
			try
			{
				this->check_date(date);
			}
			catch (std::exception const & e)
			{
				std::cout << e.what() << std::endl;
				continue;
			}
			iss.get(); // skip '|'
			iss.get(); // skip ' '
			getline(iss, value); //recupere la valeur
			if (!isdigit(value[0]) && value[0] != '-')
			{
				std::cout << "Error: bad input => " << line << std::endl;
				continue;
			}
			try
			{
				value_f = this->check_value(value);
			}
			catch (std::exception const & e)
			{
				std::cout << e.what() << std::endl;
				continue;
			}
			std::map<std::string, float>::iterator itlow;
			std::map<std::string, float>::iterator first;
			
			itlow = this->_database.lower_bound(date);
			first = this->_database.begin();
			try
			{
				
				if (itlow->first != date)
				{	
					if (itlow->first == first->first)
						throw (NotAValidDateException());
					itlow--;
				}
			}
			catch(std::exception const & e)
			{
				std::cout << e.what() << std::endl;
				continue;
			}
			value_f = value_f * itlow->second;
			// std::cout << std::setprecision(2) << std::fixed;
			std::cout << date << " => " << value << " = " << value_f << std::endl;
		}
		catch(std::ifstream::failure const & e) { break; }
		
	}
}
