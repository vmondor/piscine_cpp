#include "Zombie.hpp"

void	randomChump( std::string name )
{
	Zombie	*zombie = new Zombie(name);
	if (!zombie)
		return ;
	zombie->announce();
    delete zombie;
	return ;
}
