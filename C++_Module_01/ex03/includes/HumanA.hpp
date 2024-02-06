/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:32:56 by garance           #+#    #+#             */
/*   Updated: 2024/02/05 14:45:09 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class    HumanA {

    private:
        std::string name;
        Weapon  &weapon;
        
    public:
        HumanA(const std::string &name, Weapon &weapon);
        ~HumanA(void);
        void    attack(void);        
};

#endif