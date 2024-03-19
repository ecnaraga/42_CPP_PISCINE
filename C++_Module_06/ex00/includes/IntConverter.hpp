/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntConverter.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 12:18:24 by galambey          #+#    #+#             */
/*   Updated: 2024/03/19 19:46:17 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTCONVERTER_HPP
# define INTCONVERTER_HPP

#include "AConverter.hpp"

class IntConverter : public AConverter {
	private:
		IntConverter();
		IntConverter(IntConverter const & orig);
		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		IntConverter & operator=(IntConverter const & rhs);
		
	public:
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		IntConverter(int n);
		~IntConverter();
		
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
