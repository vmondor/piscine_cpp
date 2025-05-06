/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:03:26 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/11 16:33:36 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
    this->_type = "ice";
    return ;
}

Ice::Ice(Ice const& cpy)
{
    this->_type = cpy._type;
    return ;
}

Ice& Ice::operator=(Ice const& src)
{
    this->_type = src._type;
    return *this;
}

Ice::~Ice()
{
    return ;
}

AMateria* Ice::clone() const
{
    AMateria* clone = new Ice();
    *clone = *this;
    return (clone);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    return ;
}