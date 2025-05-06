#include <iostream>
#include <string>
#include "Fixed.hpp"

Fixed::Fixed(): _number(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(Fixed const &fixedCopy): _number(fixedCopy._number)
{
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

Fixed& Fixed::operator=(Fixed const &fixedCopy)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixedCopy)
    {
        this->_number = fixedCopy._number;
    }
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_number;

}

void    Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_number = raw;
    return ;
}