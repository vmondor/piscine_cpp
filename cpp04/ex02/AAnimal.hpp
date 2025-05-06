/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:55:51 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/06 14:08:38 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class AAnimal
{
    public :
        AAnimal();
        AAnimal(std::string type);
        AAnimal(AAnimal const& src);
        AAnimal& operator=(AAnimal const& src);
        virtual ~AAnimal();
        virtual void    makeSound(void) const = 0;
        void            setType(std::string type);
        std::string     getType(void) const;
    
    protected :
        std::string     _type;
};
