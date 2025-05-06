#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
    std::cout << "ScavTrap constructor called" << std::endl;
    return ;
}

ScavTrap::ScavTrap(ScavTrap const& src): ClapTrap(src)
{
    std::cout << "ScavTrap copy constructor  called" << std::endl;
    return ;
}

ScavTrap& ScavTrap::operator=(ScavTrap const& src)
{
    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;
    std::cout << "ScavTrap copy assignment operator called" << std::endl;
    return *this;
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoints == 0)
        std::cout << "ScavTrap " << this->_name << " has no more energy points" << std::endl;
    else
    {
        // this->_energyPoints -= (this->_energyPoints >= 5) ? 5 : this->_energyPoints;
        std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
        this->_energyPoints--;
    }
    return ;
}

void    ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << this->_name << " is now in gate keeper mode" << std::endl;
    return ;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
    return ;
}