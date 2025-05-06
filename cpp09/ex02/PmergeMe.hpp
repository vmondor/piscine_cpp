/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:58:29 by vmondor           #+#    #+#             */
/*   Updated: 2024/10/22 17:19:29 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <ctime>
#include <algorithm>
#include <iomanip>

class PmergeMe
{
    public:
        class InvalidParsingException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Error");
                }
        };
        PmergeMe(int ac, char **av);
        ~PmergeMe();
        

    private:
        std::list<int>      _lst;
        std::vector<int>    _vec;
        PmergeMe( PmergeMe const& src );
        PmergeMe& operator=( PmergeMe const& src );
        void    parsing( int ac, char **av );
        void    displayLst( void ) const;
        void    displayVec( void ) const;
        void    mergeInsertSortVec( void );
        void    mergeInsertSortLst( void );
};