/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:03:26 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/11 14:21:55 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
    this->_type = "cure";
    return ;
}

Cure::Cure(Cure const& cpy)
{
    this->_type = cpy._type;
    return ;
}

Cure& Cure::operator=(Cure const& src)
{
    this->_type = src._type;
    return *this;
}

Cure::~Cure()
{
    return ;
}

AMateria* Cure::clone() const
{
    AMateria* clone = new Cure();
    *clone = *this;
    return (clone);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
    return ;
}