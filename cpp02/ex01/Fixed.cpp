#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(): _number(0)
{
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(int const number) : _number(number)
{
    std::cout << "Int constructor called" << std::endl;
    this->_number = (this->_number << this->_bits);
    return ;
}

Fixed::Fixed(float const number)
{
    std::cout << "Float constructor called" << std::endl;
    this->_number = int(roundf(number * (1 << this->_bits)));
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
    return this->_number;

}

void    Fixed::setRawBits( int const raw )
{
    this->_number = raw;
    return ;
}

float   Fixed::toFloat( void ) const
{
    return (float(this->_number) / (1 << this->_bits));
}

int Fixed::toInt( void ) const
{
    return this->_number >> this->_bits;
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
    os << fixed.toFloat();
    return os;
}