/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:49:44 by galambey          #+#    #+#             */
/*   Updated: 2024/03/02 12:18:41 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
	
	protected :
		
		std::string	type;
		
	public :
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		Animal();
		Animal(std::string const & type);
		Animal(Animal const & orig);
		virtual ~Animal();
		
		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		Animal &			operator=(Animal const & rhs);

		/* ***************************************************************** */
		/* **************************** Accessor *************************** */
		/* ***************************************************************** */

		std::string const & getType( void ) const;

		/*
		Le mot clef virtual indique que si on stocke un pointeur sur une instance
			de la classe fille dans un pointeur sur un objet de la classe mere,
			la classe mere car la fonction a ete definie de facon dynamique
			et non statique. Donc a la compilation le mot clef virtual indique
			que la resolution de la fonction se fera dynamiquement au moment de
			l execution selon l'objet que l utilisateur aura reellement stocke 
			dans le pointeur "sur l'objet" de la classe mere .
		On a donc ici defini une methode : soit une fonction membre virtuelle
			dont la resolution se fera a l execution si l 'objet a ete declare
			dynamiquement
		*/
		virtual void makeSound( void ) const;
} ;

#endif