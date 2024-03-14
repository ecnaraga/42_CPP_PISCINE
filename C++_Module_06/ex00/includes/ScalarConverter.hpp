/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:36:11 by galambey          #+#    #+#             */
/*   Updated: 2024/03/14 15:58:16 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <limits>
# include <cctype>
# include <iomanip>

class ScalarConverter {
	private :
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		ScalarConverter();
		ScalarConverter(ScalarConverter const & orig);
		~ScalarConverter();
		
		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		ScalarConverter & operator=(ScalarConverter const & rhs);
		
	public :
		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		static void convert(std::string s); // mettre en const?
};

#endif

/*
promotion en C = upcast en CPP : reinterpretation ascendante : conversion avec gain en precision ex : double = int
demotion en C = downcast en CPP : reinterpretation desscendante : conversion avec perte en precision ex : int = double
*/