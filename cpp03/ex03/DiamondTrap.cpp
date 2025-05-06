#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap constructor called for " << _name << std::endl;
    return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const& src) : ClapTrap(src), FragTrap(src), ScavTrap(src), _name(src._name)
{
    std::cout << "DiamondTrap copy constructor called for " << _name << std::endl;
    return ;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& src)
{
    if (this != &src)
    {
        ClapTrap::operator=(src);
        _name = src._name;
    }
    std::cout << "DiamondTrap copy assignment operator called for " << _name << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
    return ;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
    return ;
}
