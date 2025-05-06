/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:27:09 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/11 14:28:31 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character(): _name("Jean")
{
    for (int i = 0; i < 4; i++)
    {
        this->_materias[i] = NULL;
        this->_saveAdress[i] = NULL;
    }
    return ;
}

Character::Character(std::string name): _name(name)
{
    for (int i = 0; i < 4; i++)
    {
        this->_materias[i] = NULL;
        this->_saveAdress[i] = NULL;
    }
    return ;
}

Character::Character(Character const& cpy)
{
    for (int i = 0; i < 4; i++)
    {
        if (cpy._materias[i])
            this->_materias[i] = cpy._materias[i]->clone();
        else
            this->_materias[i] = NULL;
    }
    return ;
}

Character& Character::operator=(Character const& src)
{
    if (this == &src)
        return *this;
    this->_name = src._name;
    for (int i = 0; i <= 3; i++)
    {
        if (this->_materias[i])
            delete this->_materias[i];
        if (src._materias[i])
            this->_materias[i] = src._materias[i]->clone();
        else
            this->_materias[i] = NULL;
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_materias[i])
            delete this->_materias[i];
    }
    return ;
}

std::string const&  Character::getName() const
{
    return this->_name;
}

void    Character::equip(AMateria *m)
{
    int i = 0;
    if (!m)
        return ;
    while (this->_materias[i] != NULL)
        i++;
    if (i > 3)
        std::cout << "Materias full" << std::endl;
    else
        this->_materias[i] = m;
    return ;
}

void    Character::saveAdress(int idx)
{
    this->_saveAdress[idx] = this->_materias[idx];
    delete this->_materias[idx];
    return ;
}

void    Character::unequip(int idx)
{
    if (this->_materias[idx] && (idx >= 0 && idx <= 3))
    {
        this->saveAdress(idx);
        this->_materias[idx] = NULL;
    }
    else
        std::cout << "This item is NULL" << std::endl;
    return ;
}

void    Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx <= 3 && this->_materias[idx])
        this->_materias[idx]->use(target);
    else
        std::cout << "Don't use the use method" << std::endl;
    return ;
}