/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:49:54 by garance           #+#    #+#             */
/*   Updated: 2024/02/05 14:11:00 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class   Weapon {
    private:
        std::string type;
        
    public:
    	Weapon(void);
        Weapon(std::string type);
        ~Weapon(void);
        std::string    getType() const;
        void            setType(std::string new_type);
} ;

#endif