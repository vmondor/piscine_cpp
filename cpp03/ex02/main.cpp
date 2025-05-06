#include <iostream>
#include "FragTrap.hpp"

int main( void )
{
	FragTrap FragTrap1("FragTrap1");
	FragTrap FragTrap2("FragTrap2");
	FragTrap FragTrap3("FragTrap3");
	FragTrap FragTrap4(FragTrap1);

	FragTrap1 = FragTrap2;
	FragTrap1.attack("FragTrap2");
	FragTrap1.attack("FragTrap3");
	FragTrap1.takeDamage(5);
	FragTrap2.takeDamage(9);
	FragTrap2.takeDamage(10);
	FragTrap3.beRepaired(10);
	FragTrap3.takeDamage(19);
	FragTrap1.setAttackDamage(5);
	FragTrap1.attack("FragTrap2");
	FragTrap1.highFivesGuys();
	return 0;
}