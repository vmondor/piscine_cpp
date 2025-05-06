/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:06:37 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/19 14:52:36 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("document"), _is_signed(false), _signedGrade(1), _executedGrade(1)
{

}

AForm::AForm( std::string name, int signedGrade, int executedGrade ): _name(name), _is_signed(false), _signedGrade(signedGrade), _executedGrade(executedGrade)
{
    if (this->_signedGrade < 1 || this->_executedGrade < 1)
        throw AForm::GradeTooHighException();
    else if (this->_signedGrade > 150 || this->_executedGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm( AForm const& src ): _name(src._name), _is_signed(src._is_signed), _signedGrade(src._signedGrade), _executedGrade(src._executedGrade)
{

}

AForm& AForm::operator=( AForm const& src )
{
    (void)src;
    return *this;
}

AForm::~AForm()
{

}

std::string AForm::getName( void ) const
{
    return this->_name;
}

bool AForm::getIsSigned( void ) const
{
    return this->_is_signed;
}

int AForm::getSignedGrade( void ) const
{
    return this->_signedGrade;
}

int AForm::getExecutedGrade( void ) const
{
    return this->_executedGrade;
}

void AForm::beSigned( Bureaucrat& bureaucrat )
{
    if (bureaucrat.getGrade() <= this->_signedGrade)
         this->_is_signed = true;
    else
       throw GradeTooLowException();
}



std::ostream &operator<<( std::ostream &os, AForm const &form )
{
    os << "Name\t\t: " << form.getName() << std::endl;
    os << "Is signed\t: " << form.getIsSigned() << std::endl;
    os << "Signed grade\t: " << form.getSignedGrade() << std::endl;
    os << "Execute grade\t: " << form.getExecutedGrade() << std::endl;
    return os;
}
