/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:19:23 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/11 14:28:17 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include "ICharacter.hpp"

class Character : public ICharacter
{
    public:
        Character();
        Character(std::string name);
        Character(Character const& cpy);
        Character& operator=(Character const& src);
        ~Character();
        std::string const& getName() const;
        void equip(AMateria* m);
        void saveAdress(int idx);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
    
    private:
        std::string _name;
        AMateria    *_materias[4];
        AMateria    *_saveAdress[4];
};
