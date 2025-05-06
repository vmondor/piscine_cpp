#include <iostream>
#include <string>
#include "Zombie.hpp"


int	main()
{
	Zombie	zombie("Zombie");
	zombie.announce();
	Zombie *zombie2 = newZombie("Zombie2");
	if (!zombie2)
		return (1);
	zombie2->announce();
	randomChump("Zombie3");

	delete zombie2;
	return (0);
}