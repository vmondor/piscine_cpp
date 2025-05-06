/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:28:06 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/18 17:09:00 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm::AForm("PresidentialPardonForm", 25, 5)
{
    
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm::AForm("PresidentialPardonForm", 25, 5), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& src)
{
    this->_target = src._target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& src)
{
    if (this != &src)
        this->_target = src._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
    if (!this->getIsSigned())
        throw AForm::GradeTooLowException();
    if (executor.getGrade() > this->getExecutedGrade())
        throw AForm::GradeTooLowException();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

