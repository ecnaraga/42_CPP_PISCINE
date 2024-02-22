/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:25:01 by galambey          #+#    #+#             */
/*   Updated: 2024/02/22 17:24:44 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

float	tofloat( int raw ) {
	
	float tmp = static_cast<float>(raw);
	return (tmp / (1 << 8));
}

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
	
	std::cout << "Operator +" << std::endl;
	
	Fixed g(Fixed(4) + Fixed(16));
	// Fixed g=Fixed(4) + Fixed(16);
	Fixed h(Fixed(10.5f) + Fixed(16));
	Fixed i(Fixed(10.5f) + Fixed (50.3568f));
	Fixed j = g + h + i;

	std::cout << "4 + 16 = " << g << std::endl;
	std::cout << "10.5 + 16 = " << h << std::endl;
	std::cout << "10.5 + 50.3568 = " << i << std::endl;
	std::cout << "20 + 26.5 + 60.8568 = " << j << std::endl;
	std::cout << "20 + 26.5 + 60.8568 = " << g + h + i << std::endl << std::endl;
	
	/* ***************************** Operator - **************************** */
	
	std::cout << "Operator -" << std::endl;
	
	Fixed k(Fixed(4) - Fixed(16));
	Fixed l(Fixed(10.5f) - Fixed(16));
	Fixed m(Fixed(50.3568f) - Fixed (11.254f));
	Fixed n = k - l - m;

	std::cout << "4 - 16 = " << k << std::endl;
	std::cout << "10.5 - 16 = " << l << std::endl;
	std::cout << "50.3568 - 10.5 = " << m << std::endl;
	std::cout << "-12 - (-5.5) - 39.1016 = " << n << std::endl;
	std::cout << "-12 - (-5.5) - 39.1016 = " << k - l - m << std::endl << std::endl;
	
	/* ***************************** Operator * **************************** */
	
	std::cout << "Operator *" << std::endl;

	Fixed o(Fixed(4) * Fixed(16));
	Fixed p(Fixed(10.5f) * Fixed(16));
	Fixed q(Fixed(50.3568f) * Fixed (11.254f));
	Fixed r(2);
	Fixed s(15);
	Fixed t(0.5f);
	Fixed u = r * s * t;

	std::cout << "4 * 16 = " << o << std::endl;
	std::cout << "10.5 * 16 = " << p << std::endl;
	std::cout << "50.3568 * 10.5 = " << q << std::endl;
	std::cout << "2 * 15 * 0.5 = " << u << std::endl;
	std::cout << "2 * 15 * 0.5 = " << r * s * t << std::endl << std::endl;
	
	/* ***************************** Operator / **************************** */
	
	std::cout << "Operator /" << std::endl;

	Fixed v(Fixed(4) / Fixed(16));
	Fixed w(Fixed(16) / Fixed(4));
	Fixed x(Fixed(9.0f) / Fixed(2));
	Fixed y(Fixed(9.25f) / Fixed (0.5f));
	Fixed z = Fixed(100) / Fixed(0.5f) / Fixed(3);

	std::cout << "4 / 16 = " << v << std::endl;
	std::cout << "16 / 4 = " << w << std::endl;
	std::cout << "9.0f / 2 = " << x << std::endl;
	std::cout << "9.25f / 0.5f = " << y << std::endl;
	std::cout << "100 / 0.5f / 3 = " << z << std::endl;
	
	return 0;

}
