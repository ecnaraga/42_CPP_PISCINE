/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:39:33 by galambey          #+#    #+#             */
/*   Updated: 2024/04/11 15:51:25 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

/* ************************************************************************** */
/* *******  METHOD 1: USE OF THE ITERATOR OF THE UNDERLYING CONTAINER ******* */
/* ************************************************************************** */

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

/* ************************************************************************** */
/* ********************  METHOD 1: NESTED CLASS ITERATOR ******************** */
/* ************************************************************************** */

// template <typename T, typename U = std::deque<T> >
// class MutantStack : public std::stack<T, U> {
	
// 	private :

// 	public :
		
// 		/* ***************************************************************** */
// 		/* ******************** Constructor & Destructor ******************* */
// 		/* ***************************************************************** */
// 		MutantStack<T, U>() : std::stack<T, U>() {}
		
// 		MutantStack<T, U>(U const & container) : std::stack< T, U >(container) {
// 			(void) container;
// 		}
		
// 		MutantStack<T, U>(MutantStack<T, U> const & orig) : std::stack<T, U>(orig) {
// 			(void) orig;
// 		}

// 		~MutantStack<T, U>() {}
		

// 		/* ***************************************************************** */
// 		/* ********************** OPERATOR OVERLOADING ********************* */
// 		/* ***************************************************************** */

// 		/* ********************** Assignment Operator ********************** */
		
// 		MutantStack<T, U> & operator=(MutantStack<T , U> rhs) {
// 			this->c = rhs.c;
// 			return (*this);
// 		}

// 		/* ***************************************************************** */
// 		/* **************************** Iterator *************************** */
// 		/* ***************************************************************** */
		
// 		class iterator : public std::iterator<std::input_iterator_tag, T>
// 		{
// 			T* p;
// 			public:
// 			iterator() {}
// 			iterator(T* x) :p(x) {}
// 			iterator(const iterator& mit) : p(mit.p) {}
// 			iterator& operator++() {++p;return *this;}
// 			iterator operator++(int) {iterator tmp(*this); operator++(); return tmp;}
// 			iterator& operator--() {--p;return *this;}
// 			iterator operator--(int) {iterator tmp(*this); operator--(); return tmp;}
// 			bool operator==(const iterator& rhs) const {return p==rhs.p;}
// 			bool operator!=(const iterator& rhs) const {return p!=rhs.p;}
// 			T& operator*() {return *p;}
// 		};
		
// 		iterator begin() {
// 			MutantStack<T, U>::iterator ite = this->end();
// 			int size = this->size();
			
// 			for (int i = 0; i < size; i++) {
// 				ite--;
// 			}
// 			return (ite);
// 		};

// 		iterator end() {
// 			MutantStack<T, U>::iterator ite = &std::stack<T, U>::top();
// 			return (++ite);
// 		};

// 		class reverse_iterator : public std::iterator<std::input_iterator_tag, T>
// 		{
// 			T* p;
// 			public:
// 			reverse_iterator() {}
// 			reverse_iterator(T* x) :p(x) {}
// 			reverse_iterator(const reverse_iterator& mit) : p(mit.p) {}
// 			reverse_iterator& operator++() {--p;return *this;}
// 			reverse_iterator operator++(int) {reverse_iterator tmp(*this); operator++(); return tmp;}
// 			reverse_iterator& operator--() {++p;return *this;}
// 			reverse_iterator operator--(int) {reverse_iterator tmp(*this); operator--(); return tmp;}
// 			bool operator==(const reverse_iterator& rhs) const {return p==rhs.p;}
// 			bool operator!=(const reverse_iterator& rhs) const {return p!=rhs.p;}
// 			T& operator*() {return *p;}
// 		};
		
// 		reverse_iterator rbegin() {
// 			MutantStack<T, U>::reverse_iterator rite = &std::stack<T, U>::top();
// 			return (rite);
// 		};

// 		reverse_iterator rend() {
// 			MutantStack<T, U>::reverse_iterator ite = this->rbegin();
// 			int size = this->size();
			
// 			for (int i = 0; i < size; i++) {
// 				ite++;
// 			}
// 			return (ite);
// 		};
// };

// #endif