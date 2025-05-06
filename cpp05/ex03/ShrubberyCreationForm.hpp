/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:16:09 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/18 16:48:09 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <iostream>
#include <string>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm( std::string target );
        ShrubberyCreationForm( ShrubberyCreationForm const& src );
        ShrubberyCreationForm& operator=( ShrubberyCreationForm const& src );
        virtual ~ShrubberyCreationForm();

        virtual void execute( Bureaucrat const & executor ) const;
    private:
        std::string _target;
};