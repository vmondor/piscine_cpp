#pragma once

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(std::string name);
        FragTrap(FragTrap const& src);
        FragTrap& operator=(FragTrap const& src);
        void    attack(const std::string& target);
        void    highFivesGuys(void);
        ~FragTrap();
};