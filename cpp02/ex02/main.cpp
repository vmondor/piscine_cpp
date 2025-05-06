#include <iostream>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}

// int main(void)
// {
//     Fixed a;
//     Fixed const b(Fixed(5.05f) * Fixed(2));

//     std::cout << a << "\t\tis a at start" << std::endl;
//     std::cout << ++a << "\tis a at ++a" << std::endl;
//     std::cout << a << "\tis a after ++a" << std::endl;
//     std::cout << a++ <<"\tis a at a++" << std::endl;
//     std::cout << a << "\tis a after a++" << std::endl;
//     std::cout << b << "\t\tvalue of b" << std::endl;
//     std::cout << std::endl;

//     bool res = a < b;
//     std::cout << "res of a < b\t" << res << std::endl;
//     res = a > b;
//     std::cout << "res of a > b\t" << res << std::endl;
//     res = a <= b;
//     std::cout << "res of a <= b\t" << res << std::endl;
//     res = a >= b;
//     std::cout << "res of a >= b\t" << res << std::endl;
//     res = a == b;
//     std::cout << "res of a == b\t" << res << std::endl;
//     res = a != b;
//     std::cout << "res of a != b\t" << res << std::endl;
//     std::cout << std::endl;

//     Fixed test1 = 10;
//     Fixed test2 = 15;
//     std::cout << "value of test1 and test2\t" << test1 << "\t" << test2 << std::endl;
//     Fixed resultat = test1 + test2;
//     std::cout << "resultat of test1 + test2\t = " << resultat << std::endl;
//     resultat = test1 - test2;
//     std::cout << "resultat of test1 - test2\t = " << resultat << std::endl;
//     resultat = test1 * test2;
//     std::cout << "resultat of test1 * test2\t = " << resultat << std::endl;
//     resultat = test2 / test1;
//     std::cout << "resultat of test2 / test1\t = " << resultat << std::endl;
//     std::cout << std::endl;

//     std::cout << Fixed::max(a, b) << "\t\tthe max of a and b" << std::endl;
//     std::cout << Fixed::min(a, b) << "\tthe min of a and b" << std::endl;

//     return 0;
// }