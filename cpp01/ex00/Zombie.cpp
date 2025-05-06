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
	std::cout  << this->_name << " destructed" << std::endl;
	return ;
}

void	Zombie::announce( void )
{
	std::cout  << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
