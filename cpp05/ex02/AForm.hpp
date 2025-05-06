/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:45:23 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/18 17:09:49 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
{
    public:
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
        class IsNotSignedException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Form is not signed");
                }
        };
        AForm();
        AForm( std::string name, int signedGrade, int executedGrade );
        AForm( AForm const& src );
        AForm& operator=( AForm const& src );
        virtual ~AForm();
        std::string getName( void ) const;
        bool        getIsSigned( void ) const;
        int         getSignedGrade( void ) const;
        int         getExecutedGrade( void ) const;
        void        beSigned( Bureaucrat& bureaucrat );

        virtual void execute( Bureaucrat const & executor ) const = 0;

    private:
        std::string const _name;
        bool        _is_signed;
        int const   _signedGrade;
        int const   _executedGrade;
};

std::ostream &operator<<(std::ostream &os, AForm const &form);