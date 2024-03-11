/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:55:42 by galambey          #+#    #+#             */
/*   Updated: 2024/03/05 11:37:03 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"

int ft_error( void ) {
	
	std::cout << "Dynamic allocation failure" << std::endl;
	return (1);
}

int main()
{
	
	std::string title = "\e[1;6;34m";
	std::string reset = "\e[0m";
	
	/* SUBJECT MAIN */
	std::cout << title << "╔═══════════════════════════════════════════════════════╗" << reset << std::endl;
	std::cout << title << "║			SUBJECT MAIN			║" << reset << std::endl;
	std::cout << title << "╚═══════════════════════════════════════════════════════╝" << reset << std::endl;
	
	IMateriaSource* src = NULL;
	ICharacter* me = NULL;
	ICharacter* bob = NULL;
	{
		try {
			src = new MateriaSource();
			if (!src)
				return (ft_error());
			
			src->learnMateria(new Ice());
			src->learnMateria(new Cure());

			me = new Character("me");
			if (!me)
				return (delete src, ft_error());
			
			AMateria* tmp;
			
			tmp = src->createMateria("ice");
			me->equip(tmp);
			tmp = src->createMateria("cure");
			me->equip(tmp);
			
			bob = new Character("bob");
			if (!bob)
				return (delete me, delete src, ft_error());
			
			me->use(0, *bob);
			me->use(1, *bob);
			
			delete bob;
			bob = NULL;
			delete me;
			me = NULL;
			delete src;
			src = NULL;
		}
		catch (int e) {
			delete bob;
			delete me;
			delete src;
			ft_error();
		}
	}
	
	/* MY MAIN */
		std::cout << title << "╔═══════════════════════════════════════════════════════╗" << reset << std::endl;
	std::cout << title << "║			   MY MAIN   			║" << reset << std::endl;
	std::cout << title << "╚═══════════════════════════════════════════════════════╝" << reset << std::endl;
	
	Character *kix = NULL;
	Character *rmy = NULL;
	IMateriaSource* empty = NULL;
	{
		try {
			src = new MateriaSource();
			if (!src)
				return (ft_error());
			
			/* Check learnMateria + MateriaSource Inventory full*/
			std::cout << title << "Check learnMateria + MateriaSource Inventory full" << reset << std::endl;
			
			src->learnMateria(new Ice());
			src->learnMateria(new Cure());
			src->learnMateria(new Ice());
			src->learnMateria(new Cure());
			src->learnMateria(new Ice());
			src->learnMateria(new Cure());
			
			me = new Character("me");
			if (!me)
				return (delete src, ft_error());
			AMateria* tmp;
			
			tmp = src->createMateria("ice");
			me->equip(tmp);
			tmp = src->createMateria("cure");
			me->equip(tmp);
			
			bob = new Character("bob");
			if (!bob)
				return (delete me, delete src, ft_error());
			
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

			kix = new Character("Kix");
			if (!kix)
				return (delete bob, delete me, delete src, ft_error());

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
			{
				Character kix_cpy = Character(*kix);
				std::cout << "kix_cpy : " << std:: endl;
				for (int i = -1; i < 6; i++)
					kix_cpy.use(i, *kix);
			}
			std::cout << std:: endl << "kix_original : " << std:: endl;
			for (int i = -1; i < 6; i++)
				kix->use(i, *kix);
			
			rmy = new Character(*kix);
			if (!rmy)
				return (delete kix, delete bob, delete me, delete src, ft_error());
			for (int i = -1; i < 6; i++)
				rmy->use(i, *kix);
			
			empty = new MateriaSource();
			if (!empty)
				return (delete rmy, delete kix, delete bob, delete me, delete src, ft_error());
			/* Check unequip + wrong index */
			std::cout << title << "Check unequip + wrong index" << reset << std::endl;
			for (int i = -1; i < 6; i++) {
				tmp = Character::getItem(i, (Character *)rmy);
				rmy->unequip(i);
				rmy->use(i, *kix);
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
			std::cout << title << "Check create wrong materia on Empty MateriaSource + equip + use" << reset << std::endl;
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
		catch (int e) {
			delete empty;
			delete rmy;
			delete kix;
			delete bob;
			delete me;
			delete src;
			ft_error();
		}
	}
	return 0;
}
