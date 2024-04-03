/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:39:33 by galambey          #+#    #+#             */
/*   Updated: 2024/04/03 11:33:33 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T, typename U = std::deque<T> >
class MutantStack : public std::stack<T, U> {
	
	private :

	public :
		
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */
		MutantStack<T, U>() : std::stack<T, U>() {}
		
		MutantStack<T, U>(U const & container) : std::stack< T, U >(container) {
			(void) container;
		}
		
		MutantStack<T, U>(MutantStack<T, U> const & orig) : std::stack<T, U>(orig) {
			(void) orig;
		}

		~MutantStack<T, U>() {}
		

		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		MutantStack<T, U> & operator=(MutantStack<T , U> rhs) {
			this->c = rhs.c;
			return (*this);
		}

		/* ***************************************************************** */
		/* **************************** Iterator *************************** */
		/* ***************************************************************** */
		
		typedef typename MutantStack::stack::container_type::iterator iterator;
		
		iterator begin() {
			return (this->c.begin());
		};

		iterator end() {
			return (this->c.end());
		};

		typedef typename MutantStack::stack::container_type::reverse_iterator reverse_iterator;
		
		reverse_iterator rbegin() {
			return (this->c.rbegin());
		};

		reverse_iterator rend() {
			return (this->c.rend());
		};
};

#endif

/*

Stack est un container adaptor, c est a dire qu il utilise un objet encapsule
d'une classe de container specifique, deque par default ( si pas de classe container
precise au constructeur ), pour stocker les elements. Ce container specifique
encapsule a partir duquel la stack est implementee est le underlying container (=
container sousjacent).

Le type du container sousjacent (ou sont stockes les elements ) est stocke dans
le membre "Container c" de la stack accessible en protected.
Pour acceder au fonctionalites de l'underlying container, on y accedera avec la
definition : stack::container_type

*/