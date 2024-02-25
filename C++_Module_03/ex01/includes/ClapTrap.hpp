/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:15:05 by garance           #+#    #+#             */
/*   Updated: 2024/02/25 12:18:43 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class   ClapTrap {
   
    private :
        std::string const _Name;
        unsigned int         _HitPoints;
        unsigned int         _EnergyPoints;
        unsigned int         _AttackDamage;
    
    protected :

    /* **************************** Accessor *************************** */
        
        void    setHitPoints(int hit);
        void    setEnergyPoints(int energy);
        void    setAttackDamage(int attack);
            
    public :
		/* ******************** Constructor & Destructor ******************* */
        
        ClapTrap();
        ClapTrap(ClapTrap const & orig);
        ClapTrap(std::string const & name);
        ~ClapTrap();
        
        
		/* ********************** Assignment Operator  ********************* */
        
        ClapTrap & operator=(ClapTrap const & rhs);

		/* **************************** Accessor *************************** */
        
        // void    setHitPoints(int hit);
        // void    setEnergyPoints(int energy);
        // void    setAttackDamage(int attack);
        std::string getName(void) const;
        int    getHitPoints(void) const;
        int    getEnergyPoints(void) const;
        int    getAttackDamage(void) const;
        
		/* ************************ Action Function ************************ */
        
        void    attack(const std::string & target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
} ;

#endif
