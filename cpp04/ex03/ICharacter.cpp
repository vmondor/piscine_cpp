/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:27:09 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/12 12:38:33 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

ICharacter::ICharacter()
{
    return ;
}

ICharacter::ICharacter(ICharacter const& cpy)
{
    (void)cpy;
    return ;
}

ICharacter& ICharacter::operator=(ICharacter const& src)
{
    (void)src;
    return *this;
}
