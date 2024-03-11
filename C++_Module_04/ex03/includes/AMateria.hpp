/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:22:22 by galambey          #+#    #+#             */
/*   Updated: 2024/03/02 12:18:41 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"

/* VIRTUAL COPY CONSTRUCTOR :
What if we can’t decide from which type of object, the copy construction to be made? For example, virtual constructor creates an object of class hierarchy at runtime based on some input. When we want to copy construct an object from another object created by virtual constructor, we can’t use usual copy constructor. We need a special cloning function that can duplicate the object at runtime.
As an example, consider a drawing application. You can select an object already drawn on the canvas and paste one more instance of the same object. From the programmer perspective, we can’t decide which object will be copy-pasted as it is runtime decision. We need virtual copy constructor to help.
Similarly, consider clip board application. A clip board can hold different type of objects, and copy objects from existing objects, pastes them on application canvas. Again, what type of object to be copied is a runtime decision. Virtual copy constructor fills the gap here.
*/
class AMateria
{
	protected:
		std::string	type;

	public:
		// Forme canonienne pour class virtuelle?
		AMateria(std::string const & type);
		virtual ~AMateria(); // Destructeur ? en virtual ?

		
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0; // => Virtual copy constructor
		virtual void use(ICharacter& target);
} ;

#endif