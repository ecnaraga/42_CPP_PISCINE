/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:36:27 by galambey          #+#    #+#             */
/*   Updated: 2024/03/26 16:28:45 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/whatever.hpp"
#include <iostream>


/*
0. Le template est instancie avant que la fonction qui a ete instanciee soit utilisee.
	Une fonction template n 'est pas utilisee telle quelle. C 'est le compilateur qui,
	a partir du type "precise", va ecrire le code de la fonction en remplacant le type T
	par int, char, string, une classe ... selon ce qui est demande.

1. Instanciation implicite ou explicite de la fonction template ?
	De preference choisir instanciation explicite.
	L'instantiation implicite est parfois possible lorsque les types "utilises" sont
	simples, mais lorsque les types deviennent trop complexes, le compilateur aura
	besoin qu'ils soient precises

2. ::max() ou max() ?
	Dans le cas des strings, avant d appeler max et min, il faut preciser l espace
	de nom avec "::", alors que pas besoin pour les ints.
	Ceci est du au fait que pour std::string la bibli standard C++ a sa propre implementation
	de std::max et que le compilateur ne sait pas quelle implementation choisir si on
	ne precise pas l espace de nom. En mettant ces :: devant max, on precise au compilateur
	de choisir la fonction max definie dans notre code qui se trouve dans l'espace de nom
	global ( represente par ces ::) et non dans la bibliotheque C++ standard ou d'autres
	espaces de nom

*/
int main( void ) {
	
	int a = 2;
	int b = 3;
	
	::swap<int>( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << min<int>( a, b ) << std::endl; // Instanciation explicite de min
	std::cout << "min( a, b ) = " << min<int const>( a, b ) << std::endl; // Instanciation explicite de min
	std::cout << "min( a, b ) = " << min( a, b ) << std::endl; // Instanciation implicite de min
	std::cout << "max( a, b ) = " << max<int>( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap<std::string>(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	// std::cout << "min( c, d ) = " << min<std::string>( c, d ) << std::endl; => ne marchera pas
	std::cout << "min( c, d ) = " << ::min<std::string>( c, d ) << std::endl;
	std::cout << "min( c, d ) = " << ::min<std::string const>( c, d ) << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	// std::cout << "max( c, d ) = " << max<std::string>( c, d ) << std::endl; => ne marchera pas
	std::cout << "max( c, d ) = " << ::max<std::string>( c, d ) << std::endl;
	return 0;
}
