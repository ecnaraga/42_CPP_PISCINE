/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:52:18 by galambey          #+#    #+#             */
/*   Updated: 2024/03/05 12:01:29 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include "Brain.hpp"

/*
Abstract class :
	- An abstract class is a class with one or more pure virtual function.
	- It can't be instancied so NO CONSTRUCTOR
	- In order to be able to use pointers on it, it has to have a VIRTUAL destructor
		(virtual because the class is abstract, and it will automaticly called the destructor 
			of the object stocked in the abstrcat class pointer declared)
	- It can have attributes, static resolution function, and dynamic resolution function 
	- One of the difference of a interface (purely abstract class) and an abstract class,
		is that in a interface (see next ex) all of the functions are purely virtual and
		there's no attributes.   
*/
class AAnimal {
	
	private :
		AAnimal();
		AAnimal & operator=(AAnimal const &);
		
	protected :
		AAnimal(std::string const & type);
		AAnimal(AAnimal const & orig);
		std::string	type;
		
	public :
		/* ***************************************************************** */
		/* *************************** Destructor ************************** */
		/* ***************************************************************** */

		virtual ~AAnimal();

		/* ***************************************************************** */
		/* **************************** Accessor *************************** */
		/* ***************************************************************** */

		std::string const & getType( void ) const; // static resolution function

		virtual void	setBrain(std::string idea) = 0; // To test deep copy
		virtual void	printBrain( void ) const = 0; // To test deep copy

		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		virtual void makeSound( void ) const = 0; // pure virtual function
} ;

#endif