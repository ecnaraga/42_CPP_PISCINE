/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:08:01 by galambey          #+#    #+#             */
/*   Updated: 2024/03/05 11:51:49 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

/* ************************************************************************* */
/* ************************ Constructor & Destructor *********************** */
/* ************************************************************************* */

Character::Character() : _name("Robot") {
	
	std::string purple = "\e[35m";
	std::string reset = "\e[0m";

	std::cout << purple << "Character constructor" << reset << std::endl << std::endl;
	this->_item = new AMateria*[4];
	if (!this->_item)
		throw 1;
	for (int i = 0; i < 4; i++)
		this->_item[i] = NULL;
}

Character::Character(Character const & orig) : _name(orig._name) {
	
	std::string purple = "\e[35m";
	std::string reset = "\e[0m";

	std::cout << purple << "Character constructor" << reset << std::endl << std::endl;
	this->_item = new AMateria*[4];
	if (!this->_item)
		throw 1;
	*this = orig;
}

Character::Character(std::string const & name) : _name(name) {
	
	std::string purple = "\e[35m";
	std::string reset = "\e[0m";

	std::cout << purple << "Character constructor" << reset << std::endl << std::endl;
	this->_item = new AMateria*[4];
	if (!this->_item)
		throw 1;
	for (int i = 0; i < 4; i++)
		this->_item[i] = NULL;
}

Character::~Character() {

	std::string purple = "\e[35m";
	std::string reset = "\e[0m";

	std::cout << purple << "Character destructor" << reset << std::endl << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->_item[i];
	delete[] this->_item;	
}
		
/* ************************************************************************* */
/* ************************** OPERATOR OVERLOADING ************************* */
/* ************************************************************************* */

/* ************************** Assignment Operator  ************************* */

Character & Character::operator=(Character const & rhs) {
	
	for (int i = 0; i < 4; i++) {
		this->_item[i] = rhs._item[i]->clone();
		if (!this->_item[i])
			throw 1;
	}
	return *this;
}

/* ************************************************************************* */
/* ******************************** Accessor ******************************* */
/* ************************************************************************* */

std::string const & Character::getName() const {
	
	return this->_name;
}

AMateria* Character::getItem( int idx , Character * character) {
	
	if (idx >= 0 && idx < 4 && character->_item[idx])
		return character->_item[idx];
	else
		return NULL;
}

/* ************************************************************************* */
/* ******************************** Actions ******************************** */
/* ************************************************************************* */

void Character::equip(AMateria* m) {
	
	if (m) {
		for (int i = 0; i < 4; i++) {
			
			if (!this->_item[i]) {
				this->_item[i] = m;
				return;
			}
		}
	}
	delete m;
}

void Character::unequip(int idx) {
	
	if (idx >= 0 && idx < 4)
		this->_item[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	
	if (idx >= 0 && idx < 4 && this->_item[idx])
		this->_item[idx]->use(target);
}

void Character::throwMateria( AMateria * materia ) {

	if (materia)
		delete materia;
	materia = NULL;
}
