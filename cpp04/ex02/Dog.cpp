/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:08:55 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/05 18:16:46 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog default constructor called" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
    return ;
}

Dog::Dog(std::string type)
{
    std::cout << "Dog constructor with type called" << std::endl;
    this->_type = type;
    this->_brain = new Brain();
    return ;
}

Dog::Dog(Dog const& src)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_type = src.getType();
    this->_brain = new Brain(*(src._brain));
    return ;
}

Dog& Dog::operator=(Dog const& src)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &src)
    {
        this->_type = src._type;
        this->_brain = new Brain(*(src._brain));
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain;
    return ;
}

void    Dog::makeSound(void) const
{
    std::cout << this->_type << " : Wouaaf Wouaaf !!" << std::endl;
    return ;
}
