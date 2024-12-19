/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:50:00 by galambey          #+#    #+#             */
/*   Updated: 2024/06/07 11:08:36 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <map>
#include <iomanip>
#include <string>

class BitCoinExchange {
	
	private :
		std::map< std::string, float>	_database;

		std::string & ft_get_date(std::string line);
		
	public :
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		BitCoinExchange();
		BitCoinExchange(BitCoinExchange & orig);
		~BitCoinExchange();

		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		BitCoinExchange & operator=(BitCoinExchange & rhs);
		
		/* ***************************************************************** */
		/* *************************** EXCEPTIONS ************************** */
		/* ***************************************************************** */
		
		class InvalidDatabase : public std::exception {
			const char * what() const throw();
		} ;
		
		class NotAValidFile : public std::exception {
			const char * what() const throw();
		} ;
		
		class BadInputException : public std::exception {
			const char * what() const throw();
		} ;

		class NotAValidDateException : public std::exception {
			const char * what() const throw();
		} ;

		class NotAPositiveNumberException : public std::exception {
			const char * what() const throw();
		} ;

		class TooLargeNumberException : public std::exception {
			const char * what() const throw();
		} ;

		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		void	get_database();
		void	get_input(std::ifstream & input);
		void	check_date(std::string const & date);
		double	check_value(std::string const & value);
		void	check_ymd(int date, int year, int i);
};

#endif