#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}
void	PhoneBook::addContact(Contact newContact, int i)
{
	this->_contacts[i] = newContact;
	return ;
}

void	PhoneBook::displayContact(int index) const
{
	this->_contacts[index].display();
}

std::string	PhoneBook::truncStr(std::string str) const
{
	std::string newStr;

	if (str.length() > 10)
	{
		str[9] = '.';
		newStr = str.substr(0, 10);
		return (newStr);
	}
	return (str);
}

void	PhoneBook::displayList() const
{
	std::cout << std::right << std::setw(10) << "INDEX" << " | "
	<< std::right << std::setw(10) << truncStr("FIRSTNAME") << " | "
	<< std::right << std::setw(10) << truncStr("LASTNAME") << " | "
	<< std::right << std::setw(10) << truncStr("NICKNAME") << std::endl;
	for (int i(0); i < 8; i++)
	{
		std::cout 
		<< std::right << std::setw(10) << this->_contacts[i].getIndex() << " | "
		<< std::right << std::setw(10) << truncStr(this->_contacts[i].getFirstname()) << " | "
		<< std::right << std::setw(10) << truncStr(this->_contacts[i].getLastname()) << " | "
		<< std::right << std::setw(10) << truncStr(this->_contacts[i].getNickname())
		<< std::endl;
	}
	std::cout << std::endl;
	return ;
}

