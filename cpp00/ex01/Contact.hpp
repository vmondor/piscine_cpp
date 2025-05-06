#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	public:
		Contact();
		Contact(std::string firstname, std::string lastname, std::string nickname, std::string phonenumber, std::string darkestSecret);
		~Contact();
		void		setIndex(int i);
		void		setFirstname(std::string firstname);
		void		setLastname(std::string lastname);
		void		setNickname(std::string nickname);
		void		setPhoneNumber(std::string phoneNumber);
		void		setDarkestSecret(std::string darkestSecret);
		int			getIndex() const;
		std::string	getFirstname() const;
		std::string	getLastname() const;
		std::string	getNickname() const;
		std::string	getPhoneNumber() const;
		std::string	getDarkestSecret() const;
		void		display() const;

	private:
		int			_index;
		std::string	_firstname;
		std::string	_lastname;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif