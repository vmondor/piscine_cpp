/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:12:04 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/05 13:48:24 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("WrongAnimal")
{
    std::cout << "WrongAnimal default Constructor called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(std::string type): _type(type)
{
    std::cout << "WrongAnimal Constructor with type called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const& src): _type(src._type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    return ;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& src)
{
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    this->_type = src._type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
    return ;
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal makeSound called" << std::endl;
    return ;
}

void    WrongAnimal::setType(std::string type)
{
    this->_type = type;
    return ;
}

std::string WrongAnimal::getType(void) const
{
    return this->_type;
}