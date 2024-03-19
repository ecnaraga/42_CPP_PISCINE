/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:18:24 by galambey          #+#    #+#             */
/*   Updated: 2024/03/19 19:46:17 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLECONVERTER_HPP
# define DOUBLECONVERTER_HPP

#include "AConverter.hpp"

class DoubleConverter : public AConverter {
	private:
		DoubleConverter();
		DoubleConverter(DoubleConverter const & orig);
		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		DoubleConverter & operator=(DoubleConverter const & rhs);
		
	public:
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		DoubleConverter(double n);
		~DoubleConverter();
		
		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */
		
		bool	isRoundFloat() const;
		void	toChar();
		void	toInt();
		void	toFloat();
		void	toDouble();
};

#endif
