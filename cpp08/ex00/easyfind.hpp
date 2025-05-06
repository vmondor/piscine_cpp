/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:58:29 by vmondor           #+#    #+#             */
/*   Updated: 2024/10/09 16:21:05 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <exception>

    
class NoFoundException : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return ("No found occurence");
        }
};

template< typename T >
typename T::iterator easyfind( T& container, int value )
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw NoFoundException();
    else
        std::cout << "Occurence found" << std::endl;
    return it;
}
