/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:14:31 by galambey          #+#    #+#             */
/*   Updated: 2024/03/26 16:44:07 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Array.hpp"

/*
Type par default :
	Possibilite de definir par default le type du template:
	template < typename = int > => Signifie que si l'instanciation du template n'est pas
	explicite, il considerera que le type fourni est un int, dans le cas contraire il utilisera
	le type "precise"
	MyClass<float> : le type sera converti en float
	MyClass<> : le type sera converti en int soit le type par default 
*/
int main() {
	
	std::string title = "\e[34m";
	std::string error = "\e[31m";
	std::string reset = "\e[0m";
	
	
	Array<int> int_arr(4);
	
	try {
		std::cout << std::endl << title << "Array of int - Default values" << reset << std :: endl;
		for (unsigned int i = 0; i < int_arr.size(); i++)
			std::cout << int_arr[i] << std::endl;
		
		std::cout << std::endl << title << "Array initialization - array[i] = i" << reset << std :: endl;
		for (unsigned int i = 0; i < int_arr.size(); i++)
			int_arr[i] = i;
		for (unsigned int i = 0; i < int_arr.size(); i++)
			std::cout << int_arr[i] << std::endl;
		
		std::cout << std::endl << title << "Copy constructor" << reset << std :: endl;
		Array<int> int_arr_cpy(int_arr);
		for (unsigned int i = 0; i < int_arr_cpy.size(); i++)
			std::cout << int_arr_cpy[i] << std::endl;
		
		std::cout << std::endl << title << "Array's copy initialization - array_cpy[i] = i + 1" << reset << std :: endl;
		for (unsigned int i = 0; i < int_arr_cpy.size(); i++)
			int_arr_cpy[i] = i + 1;
		for (unsigned int i = 0; i < int_arr_cpy.size(); i++)
			std::cout << int_arr_cpy[i] << std::endl;
		
		std::cout << std::endl << title << "Print array : Values must not been changed" << reset << std :: endl;
		for (unsigned int i = 0; i < int_arr.size(); i++)
			std::cout << int_arr[i] << std::endl;
		
		std::cout << std::endl << title << "Size function" << reset << std :: endl;
		std::cout << "Size of int_array = " << int_arr.size() <<std::endl;
		std::cout << "Size of int_array_cpy = " << int_arr_cpy.size() <<std::endl;
		
		std::cout << std::endl << title << "Print array[-1]" << reset << std :: endl;
		std::cout << int_arr[-1] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << error << e.what() << reset << std::endl;
	}

	try {
		std::cout << std::endl << title << "Print array[5]" << reset << std :: endl;
		std::cout << int_arr[5] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << error << e.what() << reset << std::endl;
	}
	
	Array<char> char_arr(10);
	
	try {
		std::cout << std::endl << title << "Array of char - Default values" << reset << std :: endl;
		for (unsigned int i = 0; i < char_arr.size(); i++)
			std::cout << char_arr[i] << std::endl;
		
		std::cout << std::endl << title << "Array initialization - array[i] = i + 65" << reset << std :: endl;
		for (unsigned int i = 0; i < char_arr.size(); i++)
			char_arr[i] = i + 65;
		for (unsigned int i = 0; i < char_arr.size(); i++)
			std::cout << char_arr[i] << std::endl;
		
		std::cout << std::endl << title << "Copy constructor" << reset << std :: endl;
		Array<char> char_arr_cpy(char_arr);
		for (unsigned int i = 0; i < char_arr_cpy.size(); i++)
			std::cout << char_arr_cpy[i] << std::endl;
		
		std::cout << std::endl << title << "Array's copy initialization - array_cpy[i] = i + 66" << reset << std :: endl;
		for (unsigned int i = 0; i < char_arr_cpy.size(); i++)
			char_arr_cpy[i] = i + 66;
		for (unsigned int i = 0; i < char_arr_cpy.size(); i++)
			std::cout << char_arr_cpy[i] << std::endl;
		
		std::cout << std::endl << title << "Print array : Values must not been changed" << reset << std :: endl;
		for (unsigned int i = 0; i < char_arr.size(); i++)
			std::cout << char_arr[i] << std::endl;
		
		std::cout << std::endl << title << "Size function" << reset << std :: endl;
		std::cout << "Size of char_array = " << char_arr.size() <<std::endl;
		std::cout << "Size of char_array_cpy = " << char_arr_cpy.size() <<std::endl;
		
		std::cout << std::endl << title << "Print array[-1]" << reset << std :: endl;
		std::cout << char_arr[-1] << std::endl;
	}
	catch (std::exception & e) {
		std::cout << error << e.what() << reset << std::endl;
	}
	try {
		std::cout << std::endl << title << "Print array[5]" << reset << std :: endl;
		std::cout << char_arr[10] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << error << e.what() << reset << std::endl;
	}

	Array<std::string> string_arr(3);
	
	try {
		std::cout << std::endl << title << "Array of string - Default values" << reset << std :: endl;
		for (unsigned int i = 0; i < string_arr.size(); i++)
			std::cout << string_arr[i] << std::endl;
		
		std::cout << std::endl << title << "Array initialization - {''Hello'', ''my'', ''friends''}" << reset << std :: endl;
		std::string tmp1[] = {"Hello", "my", "friend"};
		for (unsigned int i = 0; i < string_arr.size(); i++)
			string_arr[i] = tmp1[i];
		for (unsigned int i = 0; i < string_arr.size(); i++)
			std::cout << string_arr[i] << std::endl;
		
		std::cout << std::endl << title << "Copy constructor" << reset << std :: endl;
		Array<std::string> string_arr_cpy(string_arr);
		for (unsigned int i = 0; i < string_arr_cpy.size(); i++)
			std::cout << string_arr_cpy[i] << std::endl;
		
		std::cout << std::endl << title << "Array's copy initialization - {''Goodbye'', ''you'', ''two''}" << reset << std :: endl;
		std::string tmp2[] = {"Goodbye", "you", "two"};
		for (unsigned int i = 0; i < string_arr.size(); i++)
			string_arr_cpy[i] = tmp2[i];
		for (unsigned int i = 0; i < string_arr_cpy.size(); i++)
			std::cout << string_arr_cpy[i] << std::endl;
		
		std::cout << std::endl << title << "Print array : Values must not been changed" << reset << std :: endl;
		for (unsigned int i = 0; i < string_arr.size(); i++)
			std::cout << string_arr[i] << std::endl;
		
		std::cout << std::endl << title << "Size function" << reset << std :: endl;
		std::cout << "Size of string_array = " << string_arr.size() <<std::endl;
		std::cout << "Size of string_array_cpy = " << string_arr_cpy.size() <<std::endl;
		
		std::cout << std::endl << title << "Print array[-1]" << reset << std :: endl;
		std::cout << string_arr[-1] << std::endl;
	}
	catch (std::exception & e) {
		std::cout << error << e.what() << reset << std::endl;
	}
	try {
		std::cout << std::endl << title << "Print array[5]" << reset << std :: endl;
		std::cout << string_arr[5] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << error << e.what() << reset << std::endl;
	}
	return (0);
}
