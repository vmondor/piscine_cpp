#pragma once

#include <iostream>
#include <string>

class Fixed
{
    public :
        Fixed();
        Fixed(int const number);
        Fixed(float const number);
        Fixed( Fixed const &fixedCopy );
        Fixed& operator=(Fixed const &fixedCopy);
        ~Fixed();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;
    
    private :
        int                 _number;
        static const int    _bits = 8;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);
