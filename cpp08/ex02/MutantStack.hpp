/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:58:29 by vmondor           #+#    #+#             */
/*   Updated: 2024/10/11 15:32:42 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <deque>

template < typename T >
class MutantStack : public std::stack<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        MutantStack() : std::stack<T>() {}
        MutantStack(MutantStack<T> const& src) : std::stack<T>(src) {}
        MutantStack<T>& operator=(MutantStack<T> const& src)
        {
            if (this != &src)
                std::stack<T>::operator=(src);
            return *this;
        }
        
        iterator begin()
        {
            return this->c.begin();
        }
        const_iterator begin() const
        {
            return this->c.begin();
        }

        iterator end()
        {
            return this->c.end();
        }

        const_iterator end() const
        {
            return this->c.end();
        }

        reverse_iterator rbegin()
        {
            return this->c.rbegin();
        }

        const_reverse_iterator rbegin() const
        {
            return this->c.rbegin();
        }

        reverse_iterator rend()
        {
            return this->c.rend();
        }

        const_reverse_iterator rend() const
        {
            return this->c.rend();
        }

        void    pop()
        {
            this->c.pop_back();
        }

        void    push( T nb )
        {
            this->c.push_back(nb);
        }

};