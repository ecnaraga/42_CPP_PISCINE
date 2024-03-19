/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConverter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:18:24 by galambey          #+#    #+#             */
/*   Updated: 2024/03/18 14:12:49 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARCONVERTER_HPP
# define CHARCONVERTER_HPP

#include "AConverter.hpp"

class CharConverter : public AConverter {
	private:
		CharConverter();
		CharConverter(CharConverter const & orig);
		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		CharConverter & operator=(CharConverter const & rhs);
		
	public:
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		CharConverter(char n);
		~CharConverter();
		
		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		void	toChar();
		void	toInt();
		void	toFloat();
		void	toDouble();
};

#endif
