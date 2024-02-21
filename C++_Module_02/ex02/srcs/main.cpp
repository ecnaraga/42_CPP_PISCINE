/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:25:01 by galambey          #+#    #+#             */
/*   Updated: 2024/02/21 17:49:23 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

int main( void ) {
	
	/* ********************************************************************* */
	/* ************************** MAIN_TEST_SUJET ************************** */
	/* ********************************************************************* */
	
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;

	/* ********************************************************************* */
	/* *************************** MAIN_TEST_MINE ************************** */
	/* ********************************************************************* */
	
	Fixed c;
	Fixed d(0.5f);
	Fixed e(c);
	Fixed f(-1);

	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "f = " << f << std::endl << std::endl;
	
	/* ***************************** Operator > **************************** */

	std::cout << "Operator >" << std::endl;

	if (e > f)
		std::cout << "e > f" << std::endl;
	else
		std::cout << "e <= f" << std::endl;
	if (f > d)
		std::cout << "f > d" << std::endl;
	else
		std::cout << "f <= d" << std::endl;
	if (c > e)
		std::cout << "c > e" << std::endl << std::endl;
	else
		std::cout << "c <= e" << std::endl << std::endl;

	/* ***************************** Operator < **************************** */

	std::cout << "Operator <" << std::endl;

	if (e < f)
		std::cout << "e < f" << std::endl;
	else
		std::cout << "e >= f" << std::endl;
	if (f < d)
		std::cout << "f < d" << std::endl;
	else
		std::cout << "f >= d" << std::endl;
	if (c < e)
		std::cout << "c < e" << std::endl << std::endl;
	else
		std::cout << "c >= e" << std::endl << std::endl;

	/* **************************** Operator >= **************************** */

	std::cout << "Operator >=" << std::endl;

	if (e >= f)
		std::cout << "e >= f" << std::endl;
	else
		std::cout << "e < f" << std::endl;
	if (f >= d)
		std::cout << "f >= d" << std::endl;
	else
		std::cout << "f < d" << std::endl;
	if (c >= e)
		std::cout << "c >= e" << std::endl << std::endl;
	else
		std::cout << "c < e" << std::endl << std::endl;

	/* **************************** Operator <= **************************** */

	std::cout << "Operator <=" << std::endl;

	if (e <= f)
		std::cout << "e <= f" << std::endl;
	else
		std::cout << "e > f" << std::endl;
	if (f <= d)
		std::cout << "f <= d" << std::endl;
	else
		std::cout << "f > d" << std::endl;
	if (c <= e)
		std::cout << "c <= e" << std::endl << std::endl;
	else
		std::cout << "c > e" << std::endl << std::endl;
	
	/* **************************** Operator == **************************** */
	
	std::cout << "Operator ==" << std::endl;

	if (c == e)
		std::cout << "c == e" << std::endl;
	else
		std::cout << "c != e" << std::endl;
	if (c == d)
		std::cout << "c == d" << std::endl << std::endl;
	else
		std::cout << "c != d" << std::endl << std::endl;
	
	/* **************************** Operator != **************************** */
	
	std::cout << "Operator !=" << std::endl;

	if (c != e)
		std::cout << "c != e" << std::endl;
	else
		std::cout << "c == e" << std::endl;
	if (c != d)
		std::cout << "c != d" << std::endl << std::endl;
	else
		std::cout << "c == d" << std::endl << std::endl;
	
	/* ***************************** Operator + **************************** */
	
	Fixed g(Fixed(4) + Fixed(16));
	Fixed h(Fixed(10.5f) + Fixed(16));
	Fixed i(Fixed(10.5f) + Fixed (50.3568f));
	Fixed j = g + h + i;

	std::cout << "Fixed(4) = " << Fixed(4) << std::endl;
	std::cout << "Fixed(16) = " << Fixed(16) << std::endl;
	std::cout << "g = " << g << std::endl;
	std::cout << "h = " << h << std::endl;
	std::cout << "i = " << i << std::endl;
	std::cout << "j = " << j << std::endl;
	std::cout << "g + h + i = " << g + h + i << std::endl;
	
	/* ***************************** Operator - **************************** */
	
	Fixed ga(Fixed(4) - Fixed(16));
	Fixed ha(Fixed(10.5f) - Fixed(16));
	Fixed ia(Fixed(50.3568f) - Fixed (11.254f));
	Fixed ja = ga - ha - ia;

	std::cout << "ga = " << ga << std::endl;
	std::cout << "ha = " << ha << std::endl;
	std::cout << "ia = " << ia << std::endl;
	std::cout << "ja = " << ja << std::endl;
	std::cout << "ga - ha - ia = " << ga - ha - ia << std::endl;
	
	/* ***************************** Operator * **************************** */
	
	Fixed gb(Fixed(4) * Fixed(16));
	Fixed hb(Fixed(10.5f) * Fixed(16));
	Fixed ib(Fixed(50.3568f) * Fixed (11.254f));
	Fixed jb = gb * hb * ib;

	std::cout << "gb = " << gb << std::endl;
	std::cout << "hb = " << hb << std::endl;
	std::cout << "ib = " << ib << std::endl;
	std::cout << "jb = " << jb << std::endl;
	std::cout << "gb * hb * ib = " << gb * hb * ib << std::endl;
	
	/* ***************************** Operator / **************************** */
	
	Fixed gc(Fixed(4) / Fixed(16));
	Fixed hc(Fixed(16) / Fixed(4));
	Fixed ic(Fixed(10.5f) / Fixed(2));
	Fixed jc(Fixed(2.25f) / Fixed(10));
	Fixed kc(Fixed(36.47f) / Fixed (0.5f));
	Fixed lc = gc / hc / ic;

	std::cout << "gc = " << gc << std::endl;
	std::cout << "hc = " << hc << std::endl;
	std::cout << "ic = " << ic << std::endl;
	std::cout << "jc = " << jc << std::endl;
	std::cout << "kc = " << kc << std::endl;
	std::cout << "lc = " << lc << std::endl;
	std::cout << "gc / hc / ic = " << gc / hc / ic << std::endl;
	
	return 0;

}
