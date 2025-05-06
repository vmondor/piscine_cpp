/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:36:02 by vmondor           #+#    #+#             */
/*   Updated: 2024/10/09 18:33:09 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span ( unsigned int n ): _n(n)
{
        
}

Span::Span( Span const& src )
{
    this->_n = src._n;
    for (unsigned int i = 0; i < src._container.size(); i++)
    {
        this->_container.push_back(src._container[i]);
    }
}

Span& Span::operator=( Span const& src )
{
    if (this != &src)
    {
        this->_container.erase(this->_container.begin(), this->_container.end());
        this->_n = src._n;
        for (unsigned int i = 0; i < src._container.size(); i++)
        {
            this->_container.push_back(src._container[i]);
        }
    }
    return *this;
}

void Span::addNumber( int number )
{
    if (this->_container.size() >= this->_n)
        throw OutofboundsException();
    this->_container.push_back(number);
}

int Span::shortestSpan()
{
    if (this->_container.size() < 2)
        throw NotEnoughElementsException();
    std::vector<int> copy(this->_container.begin(), this->_container.end());
    std::sort(copy.begin(), copy.end());
    int min = 2147483647;
    for(size_t i = 1; i < copy.size(); i++)
    {
        int current = copy[i] - copy[i -1];
        if (current < min)
            min = current;
    }
    return min;
}

int Span::longestSpan()
{
    if (this->_container.size() < 2)
        throw NotEnoughElementsException();
    std::vector<int> copy(this->_container.begin(), this->_container.end());
    std::sort(copy.begin(), copy.end());
    return copy.back() - copy.front();
}
