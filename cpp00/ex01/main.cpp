#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <sstream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

bool	isAlpha(std::string const &str)
{
	for(std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!std::isalpha(static_cast<unsigned char>(*it)))
			return false;
	}
	return true;
}

bool	isDigit(std::string const &str)
{
	for(std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!std::isdigit(static_cast<unsigned char>(*it)))
			return false;
	}
	return true;
}

void	addContact(PhoneBook *phonebook, int i)
{
	Contact newContact;
	std::string firstname, lastname, nickname, phonenumber, darkestSecret;
	do
	{
		std::cout << "Firstname : ";
		if (!std::getline(std::cin, firstname))
			std::exit(0) ;
	} while (firstname.empty() || !isAlpha(firstname));
	do
	{
		std::cout << "Lastname : ";
		if (!std::getline(std::cin, lastname))
			std::exit(0) ;
	} while (lastname.empty() || !isAlpha(lastname));
	do
	{
		std::cout << "Nickname : ";
		if (!std::getline(std::cin, nickname))
			std::exit(0) ;
	} while (nickname.empty() || !isAlpha(nickname));
	do
	{
		std::cout << "PhoneNumber : ";
		if (!std::getline(std::cin, phonenumber))
			std::exit(0) ;
	} while (phonenumber.empty() || !isDigit(phonenumber) || phonenumber.length() != 10);
	do
	{
		std::cout << "DarkestSecret : ";
		if (!std::getline(std::cin, darkestSecret))
			std::exit(0) ;
	} while (darkestSecret.empty());
	newContact.setFirstname(firstname);
	newContact.setLastname(lastname);
	newContact.setNickname(nickname);
	newContact.setPhoneNumber(phonenumber);
	newContact.setDarkestSecret(darkestSecret);
	newContact.setIndex(i);
	std::cout << "***** "<< firstname << " added *****" << std::endl;
	phonebook->addContact(newContact, i);
}

void	searchContact(PhoneBook *phonebook)
{
	std::string	string_index;
	int			index;
	phonebook->displayList();
	do
	{
		std::cout << "Enter contact index : ";
		if (!std::getline(std::cin, string_index))
			std::exit(0);
		if (!isDigit(string_index))
			continue ;
		std::stringstream ss(string_index);
		ss >> index;
	} while (!(index >= 0 && index <= 7));
	phonebook->displayContact(index);
}

int	main(int ac, char **av)
{
	(void)av;
	int	i(0);
	std::string command;
	PhoneBook phonebook;

	if (ac != 1)
	{
		std::cout << "Invalid argument" << std::endl;
		return (1);
	}
	do
	{
		std::cout << "***** ADD - SEARCH - EXIT *****" << std::endl;
		std::cout << std::endl;
		std::cout << "Phonebook> ";
		if(!std::getline(std::cin, command))
			std::exit(0);
		if (command == "ADD")
		{
			if (i == 8)
				i = 0;
			addContact(&phonebook, i);
			i++;
		}
		else if (command == "SEARCH")
		{
			searchContact(&phonebook);
		}
		else if (command == "EXIT" || std::cin.eof())
		{
			std::cout << "EXIT" << std::endl;
			break ;
		}
		else
			std::cout << "Invalid argument" << std::endl;
	} while (command != "ADD" || command != "SEARCH" || command != "EXIT" || command.empty());
	return (0);
}