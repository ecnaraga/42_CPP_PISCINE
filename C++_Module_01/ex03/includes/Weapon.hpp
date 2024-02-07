/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:49:54 by garance           #+#    #+#             */
/*   Updated: 2024/02/07 10:38:55 by galambey         ###   ########.fr       */
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
        // std::string    getType() const;
        const std::string    getType() const; // a checker // le dernier const est necessaire car la fonction membre ne va pas modifier les attributs de la classe
        void            setType(std::string new_type);
} ;

#endif