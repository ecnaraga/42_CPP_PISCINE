/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FloatConverter.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:18:24 by galambey          #+#    #+#             */
/*   Updated: 2024/03/18 14:12:32 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOATCONVERTER_HPP
# define FLOATCONVERTER_HPP

#include "AConverter.hpp"

class FloatConverter : public AConverter {
	private:
		FloatConverter();
		FloatConverter(FloatConverter const & orig);
		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		FloatConverter & operator=(FloatConverter const & rhs);
		
	public:
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		FloatConverter(float n);
		~FloatConverter();
		
		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		void	toChar();
		void	toInt();
		void	toFloat();
		void	toDouble();
};

#endif
