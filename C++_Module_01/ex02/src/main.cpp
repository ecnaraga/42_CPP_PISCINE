/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galambey <galambey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:03:16 by garance           #+#    #+#             */
/*   Updated: 2024/02/08 16:00:28 by galambey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/* 
A pointer is a variable that holds the memory address of another variable.
    A pointer needs to be dereferenced with the * operator to access the memory
    location it points to.
    
A reference variable is an alias, that is, another name for an already existing
    variable. A reference, like a pointer, is also implemented by storing the
    address of an object. 
    A reference can be thought of as a constant pointer (not to be confused
    with a pointer to a constant value!) with automatic indirection, i.e.,
    the compiler will apply the * operator for you.

DIFFERENCES:
1.Memory Address: A pointer has its own memory address and size on the stack,
    whereas a reference shares the same memory address with the original variable
    and takes up no space on the stack.
    
2.NULL value: A pointer can be assigned NULL directly, whereas a reference cannot be.
    The constraints associated with references (no NULL, no reassignment) ensure that
    the underlying operations do not run into an exception situation.
    
3.Indirection: You can have a pointer to pointer (known as a double pointer) offering
    extra levels of indirection, whereas references only offer one level of indirection.

4.Reassignement: The variable can be reassigned in pointers but NOT IN REFERENCE

USE:
1.Use references: 
    In function parameters and return types.
2.Use pointers: 
    If pointer arithmetic or passing a NULL pointer is needed. For example, for arrays
    (Note that accessing an array is implemented using pointer arithmetic).
    To implement data structures like a linked list, a tree, etc. and their algorithms.
    This is so because, in order to point to different cells, we have to use the concept
    of pointers.

*/

int main(void) {

    std::string     s = "HI THIS IS BRAIN";
    std::string     *ptr = &s;
    std::string     &ref = s; // has to be declared And initialised in a SINGLE step

    /* Adresse */
    std::cout << &s << std::endl;
    std::cout << ptr << std::endl;
    std::cout << &ref << std::endl;
    
    /* Valeur */
    std::cout << s << std::endl;
    std::cout << *ptr << std::endl;
    std::cout << ref << std::endl;
    
    return (0);
}
