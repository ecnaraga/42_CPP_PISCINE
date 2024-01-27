/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garance <garance@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:57:09 by garance           #+#    #+#             */
/*   Updated: 2024/01/27 12:11:06 by garance          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account(int deposit) {
    
    this->_amount = deposit;    
    std::cout << "index" << this->_accountIndex << ";amount:" << deposit << ";created" << std::endl;
}

Account::~Account(void) {
    
}

void	Account::displayAccountsInfos( void ) {

    std::cout << "index" << Account::_accountIndex << ";amount:" << this->amount << ";created" << std::endl;
}
