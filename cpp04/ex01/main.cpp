/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:56:03 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/12 11:42:10 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	Dog basic;
	Dog tmp = basic;
	Animal	*animal = new Cat();
	Animal	*animal2 = new Dog();
	animal->makeSound();
	animal2->makeSound();
	delete animal;
	delete animal2;
	
	Animal* array[4];
	for (int i = 0; i < 2; i++)
		array[i] = new Dog();
	for (int i = 2; i < 4; i++)
		array[i] = new Cat();
	for (int i = 0; i < 4; i++)
		delete array[i];
	return 0;
}