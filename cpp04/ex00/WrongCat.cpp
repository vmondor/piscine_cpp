/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:35:35 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/05 13:43:39 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    this->_type = "WrongCat";
    return ;
}

WrongCat::WrongCat(std::string type)
{
    std::cout << "WrongCat constructor with type called" << std::endl;
    this->_type = type;
    return ;
}

WrongCat::WrongCat(WrongCat const& src)
{
    std::cout << "WrongCat copy construtor called" << std::endl;
    this->_type = src._type;
    return ;
}

WrongCat& WrongCat::operator=(WrongCat const& src)
{
    std::cout << "WrongCat copy assignment operator called" << std::endl;
    this->_type = src.getType();
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
    return ;
}

void    WrongCat::makeSound(void) const
{
    std::cout << this->_type << " : makesound Miaouh miaouh" << std::endl;
    return ;
}
