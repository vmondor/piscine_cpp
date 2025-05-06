/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:06:37 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/18 11:21:43 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("document"), _is_signed(false), _signedGrade(1), _executedGrade(1)
{

}

Form::Form( std::string name, int signedGrade): _name(name), _signedGrade(signedGrade), _executedGrade(1)
{
    if (this->_signedGrade < 1 || this->_executedGrade < 1)
        throw Form::GradeTooHighException();
    else if (this->_signedGrade > 150 || this->_executedGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form( Form const& src ): _name(src._name), _is_signed(src._is_signed), _signedGrade(src._signedGrade), _executedGrade(src._executedGrade)
{

}

Form& Form::operator=( Form const& src )
{
    if (this != &src)
    {
        Form *dest = new Form(src);
        return *dest;
    }
    return *this;
}

Form::~Form()
{

}

std::string Form::getName( void ) const
{
    return this->_name;
}

bool Form::getIsSigned( void ) const
{
    return this->_is_signed;
}

int Form::getSignedGrade( void ) const
{
    return this->_signedGrade;
}

int Form::getExecutedGrade( void ) const
{
    return this->_executedGrade;
}

void Form::beSigned( Bureaucrat& bureaucrat )
{
    if (bureaucrat.getGrade() <= this->_signedGrade)
         this->_is_signed = true;
    else
       throw GradeTooLowException();
}



std::ostream &operator<<( std::ostream &os, Form const &form )
{
    os << "Name\t\t: " << form.getName() << std::endl;
    os << "Is signed\t: " << form.getIsSigned() << std::endl;
    os << "Signed grade\t: " << form.getSignedGrade() << std::endl;
    os << "Execute grade\t: " << form.getExecutedGrade() << std::endl;
    return os;
}
