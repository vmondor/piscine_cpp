#pragma once

#include <iostream>
#include <string>

class Fixed
{
    public :
        Fixed();
        Fixed( Fixed const &fixedCopy );
        Fixed& operator=(Fixed const &fixedCopy);
        ~Fixed();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
    
    private :
        int                 _number;
        static const int    _bits = 8;
};
