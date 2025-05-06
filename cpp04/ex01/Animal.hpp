/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:55:51 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/05 12:47:03 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal
{
    public :
        Animal();
        Animal(std::string type);
        Animal(Animal const& src);
        Animal& operator=(Animal const& src);
        virtual ~Animal();
        virtual void    makeSound(void) const;
        void            setType(std::string type);
        std::string     getType(void) const;
    
    protected :
        std::string     _type;
};
