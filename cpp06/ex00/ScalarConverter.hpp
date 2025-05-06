/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:58:29 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/25 14:59:00 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>

class ScalarConverter
{
    public:
        static void convert( std::string str );
    
    private:
        ScalarConverter();
        ScalarConverter( ScalarConverter const& src );
        ScalarConverter& operator=( ScalarConverter const& src );
        ~ScalarConverter();
};
