#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(): _number(0)
{
    return ;
}

Fixed::Fixed(int const number) : _number(number)
{
    this->_number = (this->_number << this->_bits);
    return ;
}

Fixed::Fixed(float const number)
{
    this->_number = int(roundf(number * (1 << this->_bits)));
    return ;
}

Fixed::Fixed(Fixed const &fixedCopy): _number(fixedCopy._number)
{
    return ;
}

Fixed::~Fixed()
{
    return ;
}

Fixed& Fixed::operator=(Fixed const &fixedCopy)
{
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

bool Fixed::operator>(Fixed const &fixed)
{
    return this->_number > fixed._number;
}

bool Fixed::operator<(Fixed const &fixed)
{
    return this->_number < fixed._number;
}

bool Fixed::operator>=(Fixed const &fixed)
{
    return this->_number >= fixed._number;
}

bool Fixed::operator<=(Fixed const &fixed)
{
    return this->_number <= fixed._number;
}

bool Fixed::operator==(Fixed const &fixed)
{
    return this->_number == fixed._number;
}

bool Fixed::operator!=(Fixed const &fixed)
{
    return this->_number != fixed._number;
}


Fixed   Fixed::operator+(Fixed const &fixed)
{
    Fixed   fix;

    fix.setRawBits(this->_number + fixed._number);
    return fix;
}

Fixed   Fixed::operator-(Fixed const &fixed)
{
    Fixed   fix;

    fix.setRawBits(this->_number - fixed._number);
    return fix;
}

Fixed   Fixed::operator*(Fixed const &fixed)
{
    Fixed   fix;

    fix.setRawBits(this->_number * fixed._number >> this->_bits);
    return fix;
}

Fixed   Fixed::operator/(Fixed const &fixed)
{
    Fixed   fix;

    fix.setRawBits((this->_number * (1 << this->_bits)) / fixed._number);
    return fix;
}

Fixed& Fixed::operator++()
{
    this->_number++;
    return *this;
}

Fixed& Fixed::operator--()
{
    this->_number--;
    return *this;
}

Fixed Fixed::operator++( int )
{
    Fixed   fix = *this;

    ++*this;
    return fix;
}

Fixed Fixed::operator--( int )
{
    Fixed   fix = *this;

    --*this;
    return fix;
}

Fixed&  Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed&  Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a._number < b._number)
        return a;
    return b;
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a._number > b._number)
        return a;
    return b;
}