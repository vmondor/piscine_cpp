/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:58:29 by vmondor           #+#    #+#             */
/*   Updated: 2024/10/03 16:08:38 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

template< typename T >
class Array
{
    public:
        Array(): _array(0), _size(0) {}
        Array( unsigned int n ): _array(new T[n]()), _size(n) {}
        Array& operator=(Array const& src)
        {
            if (this != &src)
            {
                delete[] _array;
                this->_size = src._size;
                this->_array = new T[this->size];
                for (unsigned int i = 0; i < _size; i++)
                    this->_array[i] = src._array[i];
            }
            return *this;
        }
        Array(Array const& src): _array(new T[src._size]), _size(src._size)
        {
            for (unsigned int i = 0; i < _size; i++)
                this->_array[i] = src._array[i];
        }
        ~Array ( void ) { delete[] this->_array; }
        unsigned int size( void ) const { return this->_size; }
        T& operator[](unsigned int index)
        {
            if (index >= this->_size)
                throw std::out_of_range("index out of range");
            return this->_array[index];
        }
        const T& operator[](unsigned int index) const
        {
            if (index >= this->_size)
                throw std::out_of_range("index out of range");
            return this->_array[index];
        }

    private:
        T*              _array;
        unsigned int    _size;
};
