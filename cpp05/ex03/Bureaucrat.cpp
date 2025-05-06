/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:20:00 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/20 12:58:09 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(100)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const& src): _name(src._name), _grade(src._grade)
{
 
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& src)
{
    if (this != &src)
    {
        Bureaucrat *dest = new Bureaucrat(src);
        return *dest;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{

}

std::string Bureaucrat::getName( void ) const
{
    return this->_name;
}

int Bureaucrat::getGrade( void ) const
{
    return this->_grade;
}

void    Bureaucrat::incrementGrade( void )
{
    this->_grade--;
    if (this->_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    
}

void    Bureaucrat::decrementGrade( void )
{
    this->_grade++;
    if (this->_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
void    Bureaucrat::signForm( AForm& form)
{
    if (form.getIsSigned())
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    else
    {
        std::cout << this->_name << " couldn't sign " << form.getName() << " because ";
        if (this->_grade > form.getSignedGrade())
            std::cout << "the grade is too low" << std::endl;
        else
            std::cout << "the form is not yet signed" << std::endl;
    }
}
void    Bureaucrat::executeForm(AForm const& form)
{
    try
    {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
    
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}
