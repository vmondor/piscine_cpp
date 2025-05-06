/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:58:29 by vmondor           #+#    #+#             */
/*   Updated: 2024/10/03 13:06:50 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>


template< typename T >
void   swap( T &a, T &b)
{
    T   temp;
    temp = a;
    a = b;
    b = temp;
}

template< typename T >
T const& min( T const& a, T const& b)
{
    return ( a < b ? a : b );
}

template< typename T >
T const& max( T const& a, T const& b)
{
    return ( a > b ? a : b );
}
