/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:31:31 by garance           #+#    #+#             */
/*   Updated: 2024/02/26 12:32:47 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
  
    public :
        /* ******************** Constructor & Destructor ******************* */
        
        ScavTrap();
        ScavTrap( std::string name );
        ScavTrap( ScavTrap const & orig );    
        ~ScavTrap();
        
		/* ********************** Assignment Operator  ********************* */
        
        ScavTrap & 	operator=( ScavTrap const & rhs );
        
		/* ************************ Action Function ************************ */
        
        void   		attack( std::string const & target );
        void   		guardGate() const;
} ;

#endif