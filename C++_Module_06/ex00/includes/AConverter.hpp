/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AConverter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:46:10 by galambey          #+#    #+#             */
/*   Updated: 2024/03/19 19:46:17 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACONVERTER_HPP
# define ACONVERTER_HPP

# include <iostream>
# include <limits>
# include <sstream>

class AConverter {
	
	protected :
	
		bool c_ok;
		char c;
		bool nb_ok;
		int nb;
		float f;
		double d;
		
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		AConverter();
		AConverter(AConverter const & orig);
		
		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		AConverter & operator=(AConverter const & rhs);
	
	public :
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		virtual ~AConverter();
		
		/* ***************************************************************** */
		/* **************************** Accessor *************************** */
		/* ***************************************************************** */

		bool getCharOk() const;
		bool getIntOk() const;
		char getChar() const;
		int getInt() const;
		float getFloat() const;
		double getDouble() const;
		
		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		static char 	isChar( std::string const & s, int *err);
		static int 		isInt( std::string const & s, int *err );
		static float 	isFloat( std::string const & s);
		static double 	isDouble( std::string const & s);
		
		/* ***************************************************************** */
		/* ************************ Pure Functions ************************* */
		/* ***************************************************************** */

		virtual bool isRoundFloat() const = 0;
		virtual void toChar() = 0;
		virtual void toInt() = 0;
		virtual void toFloat() = 0;
		virtual void toDouble() = 0;
};

std::ostream & operator<<(std::ostream & oo, AConverter *rhs);

#endif
