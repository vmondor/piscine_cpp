#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact(Contact newContact, int i);
		void	displayContact(int index) const;
		void	displayList() const;
		std::string	truncStr(std::string str) const;

	private:
		Contact _contacts[8];
};



#endif