/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharConverter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:18:24 by galambey          #+#    #+#             */
/*   Updated: 2024/03/19 19:46:17 by garance          ###   ########.fr       */
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

		bool	isRoundFloat() const;
		void	toChar();
		void	toInt();
		void	toFloat();
		void	toDouble();
};

#endif
