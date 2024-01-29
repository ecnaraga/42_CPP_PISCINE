/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:57:09 by garance           #+#    #+#             */
/*   Updated: 2024/01/29 20:36:05 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int index = 0;

void	Account::_displayTimestamp() {
	
	std::time_t timestamp;
	char buffer[18];
	
	time(&timestamp);
	strftime(buffer, 18, "[%Y%m%d_%H%M%S]", localtime(&timestamp));
	std::cout << buffer;
}

Account::Account(int initial_deposit) {
    
	this->_accountIndex = index;
	index += 1;
    this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_nbAccounts += 1; 
	this->_totalAmount += initial_deposit;
	_displayTimestamp();
    std::cout << " index" << this->_accountIndex;
	std::cout << ";amount:" << initial_deposit;
	std::cout << ";created" << std::endl;
}

Account::~Account(void) {
    
	_displayTimestamp();
	std::cout << " index:" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;
}

int	Account::getNbAccounts( void ) {
	
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	
	return (Account::_totalAmount);
}
int	Account::getNbDeposits( void ) {
	
	return (Account::_totalNbDeposits);
}
int	Account::getNbWithdrawals( void ) {

	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {

	int tmp;
	
	_displayTimestamp();
	std::cout << " accounts:";
	tmp = getNbAccounts();
	std::cout << tmp << ";total:";
	tmp = getTotalAmount();
	std:: cout << tmp << ";deposits:";
	tmp = getNbDeposits();
	std:: cout << tmp << ";withdrawals:";
	tmp = getNbWithdrawals();
	std::cout << tmp << std::endl;
}

int		Account::checkAmount( void ) const {
	
	return (this->_amount);
}

void	Account::displayStatus(void) const {
	
	_displayTimestamp();
    std::cout << " index" << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits;
	std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit) {
	
	_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex;	
	std::cout << ";p_amount:" << Account::_amount;	
	std::cout << ";deposits:" << deposit;
	Account::_amount += deposit;	
	Account::_totalAmount += deposit;	
	std::cout << ";amount:" << Account::_amount;
	Account::_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	std::cout << ";nb_deposits:" << Account::_amount << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	
	_displayTimestamp();
	std::cout << " index:" << Account::_accountIndex;	
	std::cout << ";p_amount:" << Account::_amount;
	if (Account::_amount - withdrawal < 0) {
		std::cout << ";withdrawal:refused" << std::endl;
		return (1);
	}
	std::cout << ";withdrawal:" << withdrawal;
	Account::_amount -= withdrawal;	
	Account::_totalAmount -= withdrawal;	
	std::cout << ";amount:" << Account::_amount;
	Account::_nbWithdrawals += 1;
	Account::_totalNbWithdrawals += 1;
	std::cout << ";nb_deposits:" << Account::_amount << std::endl;
	return (0);
}
