#pragma once

#include <iostream>
#include <string>

class Fixed
{
    public :
        Fixed();
        Fixed( int const number );
        Fixed( float const number );
        Fixed( Fixed const &fixedCopy );
        Fixed& operator=( Fixed const &fixedCopy );
       
        bool operator>( Fixed const &fixed );
        bool operator<( Fixed const &fixed );
        bool operator>=( Fixed const &fixed );
        bool operator<=( Fixed const &fixed );
        bool operator==( Fixed const &fixed );
        bool operator!=( Fixed const &fixed );
         
        Fixed operator+( Fixed const &fixed );
        Fixed operator-( Fixed const &fixed );
        Fixed operator*( Fixed const &fixed );
        Fixed operator/( Fixed const &fixed );

        Fixed& operator++();
        Fixed& operator--();
        Fixed operator++( int );
        Fixed operator--( int );

        ~Fixed();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt( void ) const;

        static          Fixed& min(Fixed &a, Fixed &b);
        static const    Fixed& min(Fixed const &a, Fixed const &b);
        static          Fixed& max(Fixed &a, Fixed &b);
        static const    Fixed& max(Fixed const &a, Fixed const &b);

    
    private :
        int                 _number;
        static const int    _bits = 8;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);
