/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:25:47 by galambey          #+#    #+#             */
/*   Updated: 2024/05/15 11:41:11 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/RPN.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

RPN::RPN() {};

RPN::RPN(RPN & orig) {
	(void) orig;
};

RPN::~RPN() {};

/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

RPN &	RPN::operator=(RPN & rhs) {
	(void) rhs;
	return (*this);
}

/* ************************************************************************* */
/* ******************************* EXCEPTIONS ****************************** */
/* ************************************************************************* */

const char * RPN::Error::what() const throw() {
	return ("Error");
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

int	RPN::calcul_expression(std::string & arg) {
	
	std::stack<int> 		rpn;
	std::istringstream   	expression(arg);
	std::string				elem;
	int						nb;
	int						rule;
	
	expression.exceptions(std::istringstream::failbit);
	try {
		while (1) {
			
			nb = 0;
			getline(expression, elem, ' ');
			rule = check_elem(elem);
			if (rule == RPN::ERR)
				throw(RPN::Error());
			if (rule == RPN::NB) {
				
				std::istringstream nb_iss(elem);
				nb_iss >> nb;
				rpn.push(nb);
			}
			else
			{
				try {
					RPN::push_nb(rpn, nb, rule);
				}
				catch (std::exception const & e) {
					throw ;
				}
			}
		}
	}
	catch (std::iostream::failure & e) {
		if (rpn.empty())
			throw (RPN::Error());
		nb = rpn.top();
		rpn.pop();
		if (!rpn.empty())
			throw (RPN::Error());
		std::cout << nb << std::endl;
		return (nb);
	}
	return (0);
}

void RPN::push_nb(std::stack<int> & rpn, int & nb, int & rule) {
	
	if (rpn.empty())
		throw (RPN::Error());
	nb = rpn.top();
	rpn.pop();
	if (rpn.empty())
		throw (RPN::Error());
	switch (rule)
	{
		case RPN::ADD : {
			nb = rpn.top() + nb;
			break;
		}
		case RPN::SUB : {
			nb = rpn.top() - nb;
			break;
		}
		case RPN::MULT : {
			nb = rpn.top() * nb;
			break;
		}
		case RPN::DIV : {
			if (nb == 0)
				throw (RPN::Error());
			nb = rpn.top() / nb;
			break;
		}
	}
	rpn.pop();
	rpn.push(nb);
}

short int RPN::check_elem(std::string & elem) {
	
	if (elem.length() == 1)
	{
		if (elem[0] == '+')
			return (RPN::ADD);
		if (elem[0] == '-')
			return (RPN::SUB);
		if (elem[0] == '*')
			return (RPN::MULT);
		if (elem[0] == '/')
			return (RPN::DIV);
		if (isdigit(elem[0]))
			return (RPN::NB);
	}
	return (RPN::ERR);
}
