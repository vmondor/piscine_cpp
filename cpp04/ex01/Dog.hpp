/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:59:51 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/05 15:15:30 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(std::string type);
        Dog(Dog const& src);
        Dog& operator=(Dog const& src);
        ~Dog();
        void    makeSound() const;
    
    private:
        Brain*  _brain;
};
