/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:58:29 by vmondor           #+#    #+#             */
/*   Updated: 2024/10/09 17:58:09 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

    
class Span
{
    class OutofboundsException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Its not possible to add a number");
            }
    };
    class NotEnoughElementsException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("There is not enough elements");
            }
    };
    
    public:
        Span ( unsigned int n );
        Span( Span const& src );
        Span& operator=( Span const& src );
        ~Span() {};
        void addNumber( int number );
        int shortestSpan();
        int longestSpan();

        template < typename I >
        void addNumbers(I begin, I end)
        {
            if (std::distance(begin, end) + this->_container.size() > this->_n)
                throw OutofboundsException();
            this->_container.insert(this->_container.end(), begin, end);
        }


    private:
        Span();
        unsigned int        _n;
        std::vector<int>    _container;
};
