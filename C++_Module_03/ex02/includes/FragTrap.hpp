/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:47:47 by galambey          #+#    #+#             */
/*   Updated: 2024/02/26 12:32:16 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ScavTrap.hpp"

class FragTrap : public ClapTrap {
	
	public :
		/* ******************** Constructor & Destructor ******************* */
		
		FragTrap();
		FragTrap( std::string const & name );
		FragTrap( FragTrap const & orig );
		virtual ~FragTrap();
		
		/* ********************** Assignment Operator  ********************* */
		
		FragTrap & 	operator=( FragTrap const & rhs );
		
		/* ************************ Action Function ************************ */
		
		void 		highFivesGuys( void ) const;
} ;

#endif