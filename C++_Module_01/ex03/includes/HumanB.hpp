/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:54:12 by garance           #+#    #+#             */
/*   Updated: 2024/02/04 13:17:45 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANb_HPP
#define HUMANb_HPP

#include "Weapon.hpp"

class    HumanB {

    private:
        std::string name;
        Weapon  weapon;
        
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void    attack(void);
        void    setWeapon(Weapon weapon);   
};

#endif