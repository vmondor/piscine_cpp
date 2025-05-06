/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:20:39 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/05 12:33:28 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
    public :
        Cat();
        Cat(std::string type);
        Cat(Cat const& src);
        Cat& operator=(Cat const& src);
        ~Cat();
        void    makeSound() const;
};