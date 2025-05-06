#include <iostream>
#include <string>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap Constructor with name called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(ClapTrap const& src): _name(src._name), _hitPoints(src._hitPoints), _energyPoints(src._energyPoints), _attackDamage(src._attackDamage)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    return ;
}

ClapTrap& ClapTrap::operator=(ClapTrap const& src)
{
    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
    return ;
}


void    ClapTrap::attack(const std::string& target)
{
    if (this->_energyPoints == 0)
        std::cout << "ClapTrap " << this->_name << " has no more energy points" << std::endl;
    else
    {
        // this->_energyPoints -= (this->_energyPoints >= 5) ? 5 : this->_energyPoints;
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
        this->_energyPoints--;
    }
    return ;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints == 0)
        std::cout << "ClapTrap " << this->_name << " is dead";
    else if (amount > this->_hitPoints)
    {
        std::cout << "ClapTrap " << this->_name << " takes " << this->_hitPoints << " damage" << std::endl;
        this->_hitPoints = 0;
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage" << std::endl;
        this->_hitPoints -= amount;
    }
    return ;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints == 0)
        std::cout << "ClapTrap " << this->_name << " has no more energy points";
    else
    {
        std::cout << "ClapTrap " << this->_name << " gets " << amount << " hit points" << std::endl;
        this->_hitPoints += amount;
        this->_energyPoints--;
    }
    return ;
}

void    ClapTrap::setName(std::string name)
{
    this->_name = name;
    return ;
}

void    ClapTrap::setHitPoints(unsigned int hitPoints)
{
    this->_hitPoints = hitPoints;
    return ;
}

void    ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
    this->_energyPoints = energyPoints;
    return ;
}

void    ClapTrap::setAttackDamage(unsigned int attackDamage)
{
    this->_attackDamage = attackDamage;
    return ;
}

std::string    ClapTrap::getName(void) const
{
    return (this->_name);
}

unsigned int    ClapTrap::getHitPoints(void) const
{
    return (this->_hitPoints);
}

unsigned int    ClapTrap::getEnergyPoints(void) const
{
    return (this->_energyPoints);
}

unsigned int    ClapTrap::getAttackDamage(void) const
{
    return (this->_attackDamage);
}
