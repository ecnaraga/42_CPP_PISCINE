/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:26:18 by galambey          #+#    #+#             */
/*   Updated: 2024/05/15 11:36:28 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <stack>

class 	RPN {
	
	private:
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */

		RPN();
		RPN(RPN & orig);
		~RPN();

		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		RPN &	operator=(RPN & rhs);
		
	public :
		/* ***************************************************************** */
		/* ***************************** ENUM ****************************** */
		/* ***************************************************************** */

		enum type { NB, ADD, SUB, MULT, DIV, ERR};
		
		/* ***************************************************************** */
		/* *************************** EXCEPTIONS ************************** */
		/* ***************************************************************** */

		class Error : public std::exception {
			const char * what() const throw();
		} ;
		
		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		static short int check_elem(std::string & elem);
		
		static void push_nb(std::stack<int> & rpn, int & nb, int & rule);
		
		static int calcul_expression(std::string & arg);
} ;

#endif