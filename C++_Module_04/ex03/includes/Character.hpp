/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:03:51 by galambey          #+#    #+#             */
/*   Updated: 2024/03/01 11:15:10 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
// # include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
	
	private :
		std::string 	_name;
		AMateria** 		_item;
		
	public:
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		Character();
		Character(Character const & orig);
		Character(std::string const & name);
		~Character();
		
		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		Character & operator=(Character const & rhs);

		/* ***************************************************************** */
		/* **************************** Accessor *************************** */
		/* ***************************************************************** */

		std::string const & getName() const;
		static AMateria* getItem( int idx , Character * character );
		
		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		void equip( AMateria* m );
		void unequip( int idx );
		static void throwMateria( AMateria * materia );
		void use( int idx, ICharacter& target );
} ;

#endif