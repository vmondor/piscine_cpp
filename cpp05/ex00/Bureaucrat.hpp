/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:58:29 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/17 15:50:02 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Grade too High");
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
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(Bureaucrat const& src);
        Bureaucrat& operator=(Bureaucrat const& src);
        ~Bureaucrat();
        std::string getName( void ) const;
        int getGrade( void ) const;
        void    incrementGrade( void );
        void    decrementGrade( void );

    private:
        std::string const _name;
        int _grade;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);