#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact() : _index(0), _firstname(""), _lastname(""), _nickname(""), _phoneNumber(""), _darkestSecret("")
{
	return ;
}
Contact::Contact(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string darkestSecret) :
	_firstname(firstname), _lastname(lastname), _nickname(nickname), _phoneNumber(phonenumber), _darkestSecret(darkestSecret)
{
	return ;
}

Contact::~Contact()
{
	return ;
}
void		Contact::setIndex(int i)
{
	this->_index = i;
}
void		Contact::setFirstname(std::string firstname)
{
	this->_firstname = firstname;
	return ;
}

void		Contact::setLastname(std::string lastname)
{
	this->_lastname = lastname;
	return ;
}

void		Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
	return ;
}

void		Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
	return ;
}

void		Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
	return ;
}

int	Contact::getIndex() const
{
	return this->_index;
}

std::string	Contact::getFirstname() const
{
	return this->_firstname;
}

std::string	Contact::getLastname() const
{
	return this->_lastname;
}

std::string	Contact::getNickname() const
{
	return this->_nickname;
}

std::string	Contact::getPhoneNumber() const
{
	return this->_phoneNumber;
}

std::string	Contact::getDarkestSecret() const
{
	return this->_darkestSecret;
}

void	Contact::display() const
{
	std::cout << "Firstname\t: " << this->getFirstname() << std::endl;
	std::cout << "Lastname\t: " << this->getLastname() << std::endl;
	std::cout << "Nickname\t: " << this->getNickname() << std::endl;
	std::cout << "Phone Number\t: " << this->getPhoneNumber() << std::endl;
	std::cout << "DarkestSecret\t: " << this->getDarkestSecret() << std::endl;
	std::cout << std::endl;
	return ;
}