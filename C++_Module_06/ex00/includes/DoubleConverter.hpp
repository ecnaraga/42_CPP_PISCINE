/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DoubleConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:18:24 by galambey          #+#    #+#             */
/*   Updated: 2024/03/18 14:12:41 by galambey         ###   ########.fr       */
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

		void	toChar();
		void	toInt();
		void	toFloat();
		void	toDouble();
};

#endif
