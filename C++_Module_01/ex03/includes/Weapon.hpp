/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:49:54 by garance           #+#    #+#             */
/*   Updated: 2024/02/08 17:01:51 by galambey         ###   ########.fr       */
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
        const std::string    &getType() const; // le dernier const est necessaire car la fonction membre ne va pas modifier les attributs de la classe
        void            setType(std::string new_type);
} ;

#endif