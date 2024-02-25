/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:31:31 by garance           #+#    #+#             */
/*   Updated: 2024/02/25 12:23:08 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : protected ClapTrap {
  
    public :
        /* ******************** Constructor & Destructor ******************* */
        
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap const & orig);    
        ~ScavTrap();
        
		/* ********************** Assignment Operator  ********************* */
        
        ScavTrap & operator=(ScavTrap const & rhs);
        
		/* **************************** Accessor *************************** */
        
        std::string getName() const;
        int getHitPoints() const;
        int getEnergyPoints() const;
        int getAttackDamage() const;
        
		/* ************************ Action Function ************************ */
        
        void   attack(std::string const & target);
        void   guardGate ();
} ;

#endif