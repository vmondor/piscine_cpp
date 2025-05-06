/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:55:56 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/06 14:09:43 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
    return ;
}

AAnimal::AAnimal(std::string type): _type(type)
{
    std::cout << "Animal Constructor with type called" << std::endl;
    return ;
}

AAnimal::AAnimal(AAnimal const& src): _type(src._type)
{
    std::cout << "Animal copy constructor called" << std::endl;
    return ;
}

AAnimal& AAnimal::operator=(AAnimal const& src)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    this->_type = src._type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal destructor called" << std::endl;
    return ;
}

void    AAnimal::setType(std::string type)
{
    this->_type = type;
    return ;
}

std::string AAnimal::getType(void) const
{
    return this->_type;
}