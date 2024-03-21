/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AConverter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:46:10 by galambey          #+#    #+#             */
/*   Updated: 2024/03/20 17:20:01 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACONVERTER_HPP
# define ACONVERTER_HPP

# include <iostream>
# include <limits>
# include <sstream>

/*
	Classe abstraite heritee par IntConverter, CharConverter, FloatConverter et DoubleConverter
*/
class AConverter {
	
	protected :
	
		bool c_ok; // check si c a ete initialise
		char c;
		bool nb_ok; // check si nb a ete initialise
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
		
		/* ***************************************************************** */
		/* *************************** EXCEPTIONS ************************** */
		/* ***************************************************************** */

		class NotThatTypeException : public std::exception {
			char const * what() const throw();
		};
		
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

		/*
		Fonctions non membres, si le type n est pas celui qu elle doivent renvoyer,
		lancent une exception sinon retourne la valeur converti a partir de la string
		*/
		static char 	isChar( std::string const & s);
		static int 		isInt( std::string const & s );
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
