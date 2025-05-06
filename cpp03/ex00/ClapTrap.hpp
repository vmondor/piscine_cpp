#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
    public :
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(ClapTrap const& src);
        ClapTrap& operator=(ClapTrap const& src);
        void    attack(const std::string& target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        ~ClapTrap();
    
    private :
        std::string     _name;
        unsigned int    _hitPoints;
        unsigned int    _energyPoints;
        unsigned int    _attackDamage;
};
