#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
    std::cout << "FragTrap constructor called" << std::endl;
    return ;
}

FragTrap::FragTrap(FragTrap const& src): ClapTrap(src)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    return ;
}

FragTrap& FragTrap::operator=(FragTrap const& src)
{
    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    return *this;
}

void    FragTrap::attack(const std::string& target)
{
    if (this->_energyPoints == 0)
        std::cout << "FragTrap " << this->_name << " has no more energy points" << std::endl;
    else
    {
        // this->_energyPoints -= (this->_energyPoints >= 5) ? 5 : this->_energyPoints;
        std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage" << std::endl;
        this->_energyPoints--;
    }
    return ;
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << " high fives guys" << std::endl;
    return ;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
    return ;
}