#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    public:
        DiamondTrap( std::string name);
        DiamondTrap(DiamondTrap const& src);
        DiamondTrap& operator=( DiamondTrap const& src);
        ~DiamondTrap();
        void    attack(const std::string& target);
        void    whoAmI();
    
    private:
        std::string _name;
};