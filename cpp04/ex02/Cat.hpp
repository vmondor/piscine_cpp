/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:20:39 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/06 14:10:59 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    public :
        Cat();
        Cat(std::string type);
        Cat(Cat const& src);
        Cat& operator=(Cat const& src);
        ~Cat();
        void    makeSound() const;
    
    private :
        Brain*  _brain;
};