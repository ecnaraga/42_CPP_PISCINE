/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:31:17 by galambey          #+#    #+#             */
/*   Updated: 2024/03/25 17:03:03 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <class T> class Array {

	private :
		T* _array;
		unsigned int _size;
		

	public:
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		Array() {
			this->_array = new T[0]();
			this->_size = 0;
		}

		Array(Array const & orig) {
			this->_array = new T[orig.size()]();
			*this = orig;
		}
		
		Array(unsigned int n) {
			this->_array = new T[n](); // les parentheses permettent d initialiser par default toutes les valeurs du tableau
			this->_size = n;
		}
		
		~Array() {
			delete[] _array;
		}

		/* ***************************************************************** */
		/* *************************** EXCEPTIONS ************************** */
		/* ***************************************************************** */

		class NotValidIndexException : public std::exception {
			const char * what() const throw() {
				return ("Index is not valid");
			}	
		};
		
		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		Array & operator=(Array const & rhs) {
			this->_size = rhs.size();
			for(unsigned int i = 0; i < this->_size ; i++) {
				this->_array[i] = rhs._array[i];
			}
			return *this;
		}

		unsigned int size() const {
			return (this->_size);
		}

		T & operator[](int i) {
			if (i < 0 || static_cast<unsigned int>(i) >= this->size())
				throw(NotValidIndexException());
			return (this->_array[i]);
		}

};

#endif