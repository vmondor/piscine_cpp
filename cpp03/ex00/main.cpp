#include <iostream>
#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap claptrap1("claptrap1");
	ClapTrap claptrap2("claptrap2");
	ClapTrap claptrap3("claptrap3");

	claptrap1.attack("claptrap2");
	claptrap1.attack("claptrap3");
	claptrap1.takeDamage(5);
	claptrap2.takeDamage(9);
	claptrap2.takeDamage(10);
	claptrap3.beRepaired(10);
	claptrap3.takeDamage(19);
	claptrap1.attack("claptrap2");
	return 0;
}