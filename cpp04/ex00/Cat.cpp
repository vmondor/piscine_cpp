/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:22:46 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/05 12:37:15 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat default constructor called" << std::endl;
    this->_type = "Cat";
    return ;
}

Cat::Cat(std::string type)
{
    std::cout << "Cat constructor with type called" << std::endl;
    this->_type = type;
    return ;
}

Cat::Cat(Cat const& src)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->_type = src.getType();
    return ;
}

Cat& Cat::operator=(Cat const& src)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &src)
        this->_type = src.getType();
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    return ;
}

void    Cat::makeSound(void) const
{
    std::cout << this->_type << " : Miaouuh Miaouuh" << std::endl;
    return ;
}