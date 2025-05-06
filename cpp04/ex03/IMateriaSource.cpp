/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:23:31 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/12 12:39:11 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
    return ;
}

IMateriaSource::IMateriaSource(IMateriaSource const& cpy)
{
    (void)cpy;
    return ;
}

IMateriaSource& IMateriaSource::operator=(IMateriaSource const& src)
{
    (void)src;
    return *this;
}
