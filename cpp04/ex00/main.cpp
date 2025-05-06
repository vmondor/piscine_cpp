/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:56:03 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/05 14:02:41 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* chien = new Dog();
	const Animal* chien2 = new Dog("Le chien");
	const Animal* chat = new Cat();
	const Animal* chat2 = new Cat("Le chat");
	const WrongAnimal* wrongcat = new WrongCat();
	WrongCat* truecat = new WrongCat();
	std::cout << chien->getType() << " " << std::endl;
	std::cout << chat->getType() << " " << std::endl;
	chat->makeSound();
	chat2->makeSound();
	chien->makeSound();
	chien2->makeSound();
	meta->makeSound();
	std::cout << wrongcat->getType() << " " << std::endl;
	std::cout << truecat->getType() << " " << std::endl;
	wrongcat->makeSound();
	truecat->setType("The true cat");
	truecat->makeSound();
	delete meta;
	delete chien;
	delete chien2;
	delete chat;
	delete chat2;
	delete wrongcat;
	delete truecat;
	return 0;
}