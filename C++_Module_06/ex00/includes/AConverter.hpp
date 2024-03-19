/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AConverter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:46:10 by galambey          #+#    #+#             */
/*   Updated: 2024/03/18 14:11:50 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACONVERTER_HPP
# define ACONVERTER_HPP

# include <iostream>
# include <limits>
# include <sstream>

class AConverter {
	
	protected :
	
		char c;
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

		char getChar() const;
		int getInt() const;
		float getFloat() const;
		double getDouble() const;
		
		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		static int isChar( std::string const & s, int *err);
		static int isInt( std::string const & s, int *err );
		static int isFloat( std::string const & s);
		static int isDouble( std::string const & s);
		
		/* ***************************************************************** */
		/* ************************ Pure Functions ************************* */
		/* ***************************************************************** */

		virtual void toChar() = 0;
		virtual void toInt() = 0;
		virtual void toFloat() = 0;
		virtual void toDouble() = 0;
};

#endif
