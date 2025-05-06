#include <iostream>
#include <string>
#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

std::string &Weapon::getType()
{
	std::string &typeREF = this->_type;
	return (typeREF);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}