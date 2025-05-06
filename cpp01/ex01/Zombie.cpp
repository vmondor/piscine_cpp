#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie::Zombie( std::string name ) : _name( name )
{
	return ;
}

Zombie::Zombie()
{
	return ;
}

Zombie::~Zombie()
{
	return ;
}

void	Zombie::announce( void )
{
	std::cout  << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
