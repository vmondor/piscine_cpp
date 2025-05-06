/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:45:23 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/17 17:26:23 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class Form
{
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Grade too high");
            }
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Grade too low");
            }
    };

    public:
        Form();
        Form( std::string name, int signedGrade);
        Form( Form const& src );
        Form& operator=( Form const& src );
        ~Form();
        std::string getName( void ) const;
        bool        getIsSigned( void ) const;
        int         getSignedGrade( void ) const;
        int         getExecutedGrade( void ) const;
        void        beSigned( Bureaucrat& bureaucrat );

    private:
        std::string const _name;
        bool        _is_signed;
        int const   _signedGrade;
        int const   _executedGrade;
};

std::ostream &operator<<(std::ostream &os, Form const &form);