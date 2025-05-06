/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:08:55 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/05 12:36:47 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->_type = "Dog";
    return ;
}

Dog::Dog(std::string type)
{
    std::cout << "Dog constructor with type called" << std::endl;
    this->_type = type;
    return ;
}

Dog::Dog(Dog const& src)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_type = src.getType();
    return ;
}

Dog& Dog::operator=(Dog const& src)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &src)
        this->_type = src._type;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    return ;
}

void    Dog::makeSound(void) const
{
    std::cout << this->_type << " : Wouaaf Wouaaf !!" << std::endl;
    return ;
}
