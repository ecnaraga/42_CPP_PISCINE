/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:43:01 by galambey          #+#    #+#             */
/*   Updated: 2024/02/27 12:38:57 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMOND TRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap , public FragTrap {
	
	private :
        std::string const 	_name;
		
	public :
        /* ******************** Constructor & Destructor ******************* */
		
		DiamondTrap();
		DiamondTrap(std::string const & name);
		DiamondTrap(DiamondTrap const & orig);
		~DiamondTrap();

		/* ********************** Assignment Operator  ********************* */
		
		DiamondTrap & 	operator=(DiamondTrap const & rhs);

		/* **************************** Accessor *************************** */
		
		std::string		getName( void ) const;
				
		/* ************************ Action Function ************************ */

		void 			whoAmI( void ) const;
} ;

#endif