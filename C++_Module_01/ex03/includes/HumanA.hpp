/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:32:56 by garance           #+#    #+#             */
/*   Updated: 2024/02/04 18:58:45 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class    HumanA {

    private:
        std::string name;
        Weapon*  weapon;
        
    public:
        HumanA(std::string name, Weapon weapon);
        ~HumanA(void);
        void    attack(void);        
};

#endif