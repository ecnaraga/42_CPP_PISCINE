/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:55:42 by galambey          #+#    #+#             */
/*   Updated: 2024/03/01 14:32:19 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"

int main()
{
	
	std::string title = "\e[1;6;34m";
	std::string reset = "\e[0m";
	
	/* SUBJECT MAIN */
	std::cout << title << "╔═══════════════════════════════════════════════════════╗" << reset << std::endl;
	std::cout << title << "║			SUBJECT MAIN			║" << reset << std::endl;
	std::cout << title << "╚═══════════════════════════════════════════════════════╝" << reset << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");
		AMateria* tmp;
		
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		ICharacter* bob = new Character("bob");
		
		me->use(0, *bob);
		me->use(1, *bob);
		
		delete bob;
		delete me;
		delete src;
	}
	
	/* MY MAIN */
		std::cout << title << "╔═══════════════════════════════════════════════════════╗" << reset << std::endl;
	std::cout << title << "║			   MY MAIN   			║" << reset << std::endl;
	std::cout << title << "╚═══════════════════════════════════════════════════════╝" << reset << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		
		/* Check learnMateria + MateriaSource Inventory full*/
		std::cout << title << "Check learnMateria + MateriaSource Inventory full" << reset << std::endl;
		
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter* me = new Character("me");
		AMateria* tmp;
		
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		
		ICharacter* bob = new Character("bob");
		
		/* Check use and Character Inventory not full */
		std::cout << title << "Check use and Character Inventory not full" << reset << std::endl;
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);

		/* Check unequip in existing element, not existing element and wrong idx */
		std::cout << title << "Check unequip in existing element, not existing element and wrong idx" << reset << std::endl;
		tmp = Character::getItem(0, (Character *)me);
		me->unequip(0);
		Character::throwMateria(tmp);
		tmp = Character::getItem(0, (Character *)me);
		me->unequip(0);
		Character::throwMateria(tmp);
		tmp = Character::getItem(-1, (Character *)me);
		me->unequip(-1);
		Character::throwMateria(tmp);
		tmp = Character::getItem(4, (Character *)me);
		me->unequip(4);
		Character::throwMateria(tmp);
		
		/* Check if unequip element has been really unequip */
		std::cout << title << "Check if unequip element has been really unequip" << reset << std::endl;
		me->use(0, *bob);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		me->use(0, *bob);

		Character *kix = new Character("Kix");

		/* Check equip + Character Inventory full*/
		std::cout << title << "Check equip + Character Inventory full" << reset << std::endl;
		for (int i = 0; i < 6; i++) {
			if (i % 2 == 0)
				tmp = src->createMateria("cure");
			else
				tmp = src->createMateria("ice");	
			kix->equip(tmp);
		}
		
		/* Check use + wrong and valid index */
		std::cout << title << "Check use + wrong and valid index" << reset << std::endl;
		for (int i = -1; i < 6; i++)
			kix->use(i, *me);
			
		tmp = Character::getItem(0, (Character *)me);
		me->unequip(0);
		Character::throwMateria(tmp);
		
		/* Check Character CopyConstructor  deep copy*/
		std::cout << title << "Check Character CopyConstructor  deep copy" << reset << std::endl;
		Character *rmy = new Character(*kix);
		for (int i = -1; i < 6; i++)
			rmy->use(i, *kix);
		
		IMateriaSource* empty = new MateriaSource();
		/* Check unequip + wrong index */
		std::cout << title << "Check unequip + wrong index" << reset << std::endl;
		for (int i = -1; i < 6; i++) {
			tmp = Character::getItem(0, (Character *)rmy);
			rmy->unequip(0);
			rmy->use(0, *kix);
			Character::throwMateria(tmp);
		}

		/* Check create materia on Empty MateriaSource + equip + use */
		std::cout << title << "Check create materia on Empty MateriaSource" << reset << std::endl;
		std::cout << "" << std::endl;
		tmp = empty->createMateria("cure");
		rmy->equip(tmp);
		rmy->use(0, *kix);
		
		/* Check learnMateria + create materia on Empty MateriaSource + equip + use */
		std::cout << title << "Check learnMateria + create materia on Empty MateriaSource + equip + use" << reset << std::endl;
		empty->learnMateria(new Cure());
		tmp = empty->createMateria("cure");
		rmy->equip(tmp);
		rmy->use(0, *kix);

		/* Check create wrong materia on MateriaSource + equip + use */
		std::cout << title << "Check learnMateria + create materia on Empty MateriaSource + equip + use" << reset << std::endl;
		tmp = empty->createMateria("cuuure");
		rmy->equip(tmp);
		rmy->use(1, *kix);
		
		delete empty;
		delete rmy;
		delete kix;
		delete bob;
		delete me;
		delete src;
	}
	return 0;
}
