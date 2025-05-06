/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:16:33 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/12 11:13:01 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"


MateriaSource::MateriaSource()
{
    for (int i = 0; i <= 3; i++)
        this->_materias[i] = NULL;
    return ;
}

MateriaSource::MateriaSource(MateriaSource const& cpy)
{
    *this = cpy;
    return ;
}

MateriaSource& MateriaSource::operator=(MateriaSource const& src)
{
    if (this != &src)
    {
        for (int i = 0; i <= 3; i++)
        {
            if (this->_materias[i])
                delete _materias[i];
            if (src._materias[i])
                this->_materias[i] = src._materias[i]->clone();
            else
                this->_materias[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i <= 3; i++)
    {
        if (this->_materias[i])
            delete this->_materias[i];
    }
    return ;
}

void MateriaSource::learnMateria(AMateria* cpy)
{
    if (!cpy)
        return ;
    for (int i = 0; i <= 3; i++)
    {
        if (!this->_materias[i])
        {
            this->_materias[i] = cpy;
            return ;
        }
    }
    return ;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i <= 3; i++)
    {
        if (this->_materias[i] && this->_materias[i]->getType() == type)
            return this->_materias[i]->clone();
    }
    return NULL;
}