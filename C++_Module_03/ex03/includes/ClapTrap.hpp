/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 11:15:05 by garance           #+#    #+#             */
/*   Updated: 2024/02/26 17:50:54 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class   ClapTrap {
   
    private :
        std::string const 	_name;
        unsigned int        _hitPoints;
        unsigned int        _energyPoints;
        unsigned int        _attackDamage;
    
    protected :
    /* **************************** Accessor *************************** */
        
        void    			setHitPoints( int hit );
        void    			setEnergyPoints( int energy );
        void    			setAttackDamage( int attack );
		
	/* ************************ Action Function ************************ */
		
		void				attack_action( std::string const & message, std::string const & target );
            
    public :
		/* ******************** Constructor & Destructor ******************* */
        
        ClapTrap();
        ClapTrap( ClapTrap const & orig );
        ClapTrap( std::string const & name );
        virtual ~ClapTrap();
        
		/* ********************** Assignment Operator  ********************* */
        
        ClapTrap & 			operator=( ClapTrap const & rhs );

		/* **************************** Accessor *************************** */
        
        virtual std::string	getName( void ) const;
        virtual int    		getHitPoints( void ) const;
        virtual int    		getEnergyPoints( void ) const;
        virtual int    		getAttackDamage( void ) const;
        
		/* ************************ Action Function ************************ */
        
        virtual void    	attack( std::string const & target );
        void    			takeDamage( unsigned int amount );
        void   				beRepaired( unsigned int amount );
} ;

#endif
