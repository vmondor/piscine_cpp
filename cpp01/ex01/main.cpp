#include <iostream>
#include <string>
#include "Zombie.hpp"


int	main()
{
	Zombie *zombie = zombieHorde(3, "Zombie");
	if (!zombie)
		return (1);
	for (int i = 0; i < 3; i++)
	{
		zombie[i].announce();
	}
	delete [] zombie;
	return (0);
}