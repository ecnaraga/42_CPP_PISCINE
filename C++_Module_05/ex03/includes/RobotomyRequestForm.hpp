/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:31:07 by galambey          #+#    #+#             */
/*   Updated: 2024/03/07 11:14:14 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	
	private :
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */
		
		RobotomyRequestForm();
		
		/* ***************************************************************** */
		/* ********************** OPERATOR OVERLOADING ********************* */
		/* ***************************************************************** */

		/* ********************** Assignment Operator ********************** */
		
		RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
		
	public :
		/* ***************************************************************** */
		/* ******************** Constructor & Destructor ******************* */
		/* ***************************************************************** */
		
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm(RobotomyRequestForm const & orig);
		~RobotomyRequestForm();

		/* ***************************************************************** */
		/* **************************** Actions **************************** */
		/* ***************************************************************** */

		void execute(Bureaucrat const & executor) const;
} ;

#endif
