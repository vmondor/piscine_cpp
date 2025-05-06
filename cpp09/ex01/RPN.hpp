/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:58:29 by vmondor           #+#    #+#             */
/*   Updated: 2024/10/23 13:06:22 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN
{
    public:
        class InvalidExpressionException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Error");
                }
        };
        class DivisionByZeroException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Error: division by zero.");
                }
        };
        RPN();
        RPN( RPN const& src );
        RPN& operator=( RPN const& src );
        ~RPN();

        void    calc( std::string expression );
        int     getResult() const;


    private:
        std::stack<int> _stack;
        int     _temp_result;
        bool    isOperator( std::string str );
        bool    isNumber( std::string str );
        void    applyOperator( char c, int a, int b );
        int     tooLargeNumber( std::string str );

};