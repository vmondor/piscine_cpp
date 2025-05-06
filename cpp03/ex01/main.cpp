#include <iostream>
#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap ScavTrap1("ScavTrap1");
	ScavTrap ScavTrap2("ScavTrap2");
	ScavTrap ScavTrap3("ScavTrap3");
	ScavTrap ScavTrap4(ScavTrap1);

	ScavTrap1 = ScavTrap2;
	ScavTrap1.attack("ScavTrap2");
	ScavTrap1.attack("ScavTrap3");
	ScavTrap1.takeDamage(5);
	ScavTrap2.takeDamage(9);
	ScavTrap2.takeDamage(10);
	ScavTrap3.beRepaired(10);
	ScavTrap3.takeDamage(19);
	ScavTrap1.setAttackDamage(5);
	ScavTrap1.attack("ScavTrap2");
	return 0;
}