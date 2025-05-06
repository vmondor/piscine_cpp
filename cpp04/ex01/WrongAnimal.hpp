/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:07:58 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/05 13:45:37 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class WrongAnimal
{
    public :
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(WrongAnimal const& src);
        WrongAnimal& operator=(WrongAnimal const& src);
        virtual     ~WrongAnimal();
        void        makeSound(void) const;
        void        setType(std::string type);
        std::string getType(void) const;

    protected :
        std::string _type;
};