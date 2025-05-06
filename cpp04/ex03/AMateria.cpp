/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:56:25 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/12 11:32:43 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"


AMateria::AMateria(): _type("default")
{
    return ;
}
AMateria::AMateria(std::string const& type): _type(type)
{
    return ;
}

AMateria::AMateria(AMateria const& cpy)
{
    *this = cpy;
    return ;
}

AMateria& AMateria::operator=(AMateria const& src)
{
    if (this != &src)
        this->_type = src._type;
    return *this;
}

AMateria::~AMateria()
{
    return ;
}

std::string const & AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* use a materia on " << target.getName() << " *" << std::endl;
    return ;
}