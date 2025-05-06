/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:55:56 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/05 13:56:33 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
    return ;
}

Animal::Animal(std::string type): _type(type)
{
    std::cout << "Animal Constructor with type called" << std::endl;
    return ;
}

Animal::Animal(Animal const& src): _type(src._type)
{
    std::cout << "Animal copy constructor called" << std::endl;
    return ;
}

Animal& Animal::operator=(Animal const& src)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    this->_type = src._type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
    return ;
}

void    Animal::makeSound(void) const
{
    std::cout << "Animal makesound called" << std::endl;
    return ;
}

void    Animal::setType(std::string type)
{
    this->_type = type;
    return ;
}

std::string Animal::getType(void) const
{
    return this->_type;
}