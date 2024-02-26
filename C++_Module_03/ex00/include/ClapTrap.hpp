/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:15:05 by garance           #+#    #+#             */
/*   Updated: 2024/02/26 17:44:52 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class   ClapTrap {
   
    private :
        std::string const _name;
        unsigned int         _hitPoints;
        unsigned int         _energyPoints;
        unsigned int         _attackDamage;
        
    public :
		/* ******************** Constructor & Destructor ******************* */
        
        ClapTrap();
        ClapTrap( ClapTrap const & orig );
        ClapTrap( std::string const & name );
        ~ClapTrap();
        
		/* ********************** Assignment Operator  ********************* */
        
        ClapTrap & operator=( ClapTrap const & rhs );

		/* **************************** Accessor *************************** */
        
        std::string getName( void ) const;
        int    getHitPoints( void ) const;
        int    getEnergyPoints( void ) const;
        int    getAttackDamage( void ) const;
        
		/* ************************ Action Function ************************ */
        
        void    attack( const std::string & target );
        void    takeDamage( unsigned int amount );
        void    beRepaired( unsigned int amount );
} ;

#endif
