# 42_CPP_PISCINE

Goal

    - Discover and learn cpp language

Rules

    - Compile with c++ and the flags -Wall -Wextra -Werror
    - C++98 library allowed only
    - STL library allowed for Module 8 and 9
    - From module 2 to 9 use the canonical form to build the classes
    - Implement functions in a cpp file (except for function template)

Module 00 => Write .cpp and .hpp file and create classes
    
    - ex00 : Implement a program that takes strings in argument and write it in uppercase
    - ex01 : Implement a PhoneBook program who can takes up to 8 contacts and implement the rule ADD (add Contact), SEARCH (search contact0 end EXIT (exit the program)
    - ex02 : Write the Account.cpp file corresponding to the Account.hpp and tests.cpp files (given)

Module 01 => CPP pointers, CPP references, dynamic allocation and free memmory, private/public specifiers,  accessors, log levels, pointer to function, switch statement
    
    - ex00 : Implement a class Zombie, and two functions one which allocate on the heap and the other on the stack
    - ex01 : Implement a function that allocate at once n zombies and return the pointer to the first one
    - ex02 : Implement a main with a string, a pointer and a reference to that string and print both values and adresses pointed/helded by the pointers and references
    - ex03 : Implement the three classes to make the main.cpp work. HumanA has always a weapon, HumanB no. Use weapon's reference in one of the human class and weapon's pointer in the other
    - ex04 : Create a program that takes three parameters and copy the file in a new file with all the occurences of the first string replaced by the second string
            ./sed <filename> <string_to_be_replace> <string_to_replace>
    - ex05 : Implement a class that handle logs levels (DEBUG, INFO, WARNING, ERROR) and a function that call the good one using pointers to function
            ./harl "log level"
    - ex06 : Same exercice as precedent except this time it will display all messages from the level given in parameter and above
            ./harlFilter "log level"

Module 02 => Class 'cannonical orthodox copien form, create and use a fixed class with a fractional bits value of 8, operators overloading, static member functions
    
    - ex00 : Implement a class Fixed with coplien form. for now there's only default and copy constructor, and the attribut RawBit has to be set at 0. Fractional bit is initialized to 8. The main.cpp (given) has to work
    - ex01 : Add to the Fixed class a constructor that take a const int as parameter, another one taking a const float, functions to convert the fixed point to float value or to integer value, functions to convert the integer or float value to fixed point, and overload left shift operator (<<) that insert a float representation of the fixed point number
    - ex02 : Add to the fixed class comparison operators (>, <, >=, <=, ==, !=), arithmetic operators (+, -, *, /), increment and decrement operators (pre and post),  min and max functions that takes two references on fixed-point numbers or const fixed-point numbers and return the smallest/greatest one
    - ex03 : Implement a function that say if a point is inside or outside of a triangle using the fixed class implemented above
    
Module 03 => Heritage
    
    - ex00 : Implement a class ClapTrap with 4 attributs (Name, Hit points = 10, Energy points = 10 Attack damage = 0), and three functions attack, takeDamage, beRepaired. using attack and beRepaired cost 1 energy point. When a ClapTrap attack, the target takes dammage. Implement a main to test the class
    - ex01 : Add a ScavTrap clas that inherit the ClapTrap class (update ClapTrap in this case : Hit points = 100, Energy points = 50 Attack damage = 20). ScavTrap has sis own capacity : guardGat that display a message. Add more tests in the main
    - ex02 : Add a FragTrap clas that inherit the ClapTrap class (update ClapTrap in this case : Hit points = 100, Energy points = 100 Attack damage = 30). FragTrap has sis own capacity : highFivesGuy that display a message. Add more tests in the main
    - ex03 : Add a DiamondTrap clas that inherit both of ScavTrap and FragTrap classes (update ClapTrap in this case : Name = Diamond'sTrap name + "_clap_name" , Hit points = FragTrap's, Energy points = ScavTrap 's, Attack damage = FragTrap's). He can use the attack() of the ScavTrap, but not of the FragTrap. DiamondTrap has his own name and his own capacity : whoAmI that display both the name of the clapTrap and the name of the diamondTrap. The constructor of ClapTrap can't be cal twice. Add more tests in the main

Module 04 => Polymorphisme, Abstract class, Interface (or pure abstract class), protected specifier
    
    - ex00 : Implement a baseclass Animal, a dog and a cat classes that inherits of Animal. Animal 's makeSound has to be the good sound depending its a cat or a dog. Implement a baseclass WrongAnimal, and a WrongCat class that inherits of WrongAnimal. Animal 's makeSound has to be the one of Wrong Animal even if WrongAnimal's pointer to a WrongCat. The main.cpp (given) has to work
    - ex01 : Erase WrongAnimal and WrongCat classes, and add a Brain class that contains an array of 100 std::string. Cat and Dog classes have a private attribute *Brain that they have to allocate/delete. Implement a main to test it
    - ex02 : Transform Animal class into an abstractClass that can't be instantiated. All functionalities still have to work. Add more tests in the main
    - ex03 : Implement :
        - Abstract class AMateria with among otherthing a clone() pure function that return a pointer to AMateria
        - Concrete class Ice and Cure that inherit of AMateria
        - Interface ICharacter and a concrete class Character that have an inventory with 4 slot to store 4 Materia at most
        - Concrete class MateriaSource which have two functionalities : LearnMateria and createMateria and that can learn and store 4 materias at most
        => To be able to use a Materia, the character has to be equip of a Materia in his inventory.
        => To be able to equip a charcater wich a Materia, a Materia Source has to learn first the materia then to create it.
        => Copies must be deep copies
        => unequip() function can't delete a Materia
        => No memmory leaks
    
Module 05 => Exception
    
    - ex00 : Implement a Bureaucrat class, with a constant name and a grade from 1(highest) to 150 (lowest). Implements two exception in case grade is too low or too high. Implement a main to test it
    - ex01 : Add a Form class , with a constant name, a bool indicate if the form is sign, a grade require to be signed, a grade require to be executed. Implements two exception in case one of form grade is too high or to low, and one in case Bureaucrat's grade is too low to sign the form. Add more tests to the main
    - ex02 : Transform the Form class into an abstract class and add 3 concrete form classes :
        - ShrubberyCreationForm: Required grades: sign 145, exec 137 that create a file and draw an ascii tree inside
        - RobotomyRequestForm: Required grades: sign 72, exec 45 that make a noise 550% of the time
        - PresidentialPardonForm: Required grades: sign 25, exec 5 that grant pardon to the target
        Implement a main to test it
    - ex03 : Implement an Intern class with no attribute that have one fonction to create the good form depending the parameter given and return its pointer
    
Module 06 => Static cast, Reinterpret cast, Dynamic cast
    
    - ex00 : Implement a ScalarConverter class that contain only one static method convert who take as parameter a string representation of a char, int, float or double and display the string representation in the 4 forms. Write a program to test it
        => You can do "make test" to run some tests in the shell
    - ex01 : Implement a Serialize class with two statics methods serialize that take a pointer and return the conversion in a uintptr_ and deserialize that do the opposite thing.
    - ex02 : Create three empty classes that inherit of a Base class who has only a virtual destructor. Implement a generate function that randomly return a pointer to A, B or C instance, and two indentify function one takin a pointer to the Base class and the other one the reference and print the type of Base pointer/reference passing in parameter 

Module 07 => Functions templates and class templates
    
    - ex00 : Implement the following functions templates : swap, min and max
    - ex01 : Implement a function template iter that takes the adress of an array, the length of an array and a function that will be called on all elements of the array
    - ex02 : Implement a class template Array that contain elements of type T, and overload among other things the operator [] 

Module 08 => Templated containers (stack, list, vector, deque), iterators, algorithms library
    
    - ex00 : Implement a template function  taking two parameter, a type T and an integer. Assuming T is a container of integers, find the first occurence of the second parameter
    - ex01 : Implement a Span class that store n integers max. Implements two members functions that will find the shortest/greatest span between all numbers stored. Implement a function that fill the span using a range of iterators at once.
    - ex02 : Create a MutantStack class that inherit of std::stack and implements iterators for the MutantStack
    
Module 09 => Templated containers (maps, stack, vector, deque), STL library
    
    - ex00 : Write a program that take an input file in arguments and will outputs the value of a certain amount of bitcoin according a dadatabase provided with the subject
    =>  ./btc input.txt
    - ex01 : Implement a Reverse Polish Notation
    =>  ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
    - ex02 : Implement with two differents containers the ford-johnson algorythm
    
