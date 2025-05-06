/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:20:00 by vmondor           #+#    #+#             */
/*   Updated: 2024/10/01 12:36:55 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void    ScalarConverter::convert( std::string const str )
{
    if (str.empty())
    {
        std::cerr << "Error: string empty" << std::endl;
        return ;
    }
    char*   end;
    double  num_d = std::strtod(str.c_str(), &end);
    
    // char
    long asciiValue = std::atol(str.c_str());
    if (std::isnan(num_d) || std::isinf(num_d))
        std::cout << "char: " << "impossible" << std::endl;
    else if ((asciiValue >= 0 && asciiValue <= 31) || asciiValue == 127)
        std::cout << "char: Non displayable" << std::endl;
    else if (asciiValue >= 33 && asciiValue <= 126)
        std::cout << "char: '" << static_cast<char>(asciiValue) << "'" << std::endl;
    else
        std::cout << "char: impossible" << std::endl;
    
    // int
    // int num_i = std::atoi(str.c_str());
    int num_i = static_cast<int>(num_d);
    if (std::isnan(num_d) || std::isinf(num_d))
        std::cout << "int: " << "impossible" << std::endl;
    else
        std::cout << "int: " << num_i << std::endl;
    
    // float
    float num_f = static_cast<float>(num_d);
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(num_f) << "f" << std::endl;
    
    // double 
    if (*end != '\0' && *end != 'f')
        std::cerr << "double: impossible"  << std::endl;
    else
        std::cout << "double: " << static_cast<double>(num_d) << std::endl;
}
