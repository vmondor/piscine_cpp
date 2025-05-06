/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:25:48 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/19 11:26:55 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm::AForm("RobotomyRequestForm", 72, 45), _target("default"), _exec(true)
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm::AForm("RobotomyRequestForm", 72, 45), _target(target), _exec(true)
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& src)
{
    this->_target = src._target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& src)
{
    if (this != &src)
        this->_target = src._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
    if (!this->getIsSigned())
        throw AForm::IsNotSignedException();
    if (executor.getGrade() > this->getExecutedGrade())
        throw AForm::GradeTooLowException();
    std::cout << "* drilling noises *" << std::endl;
    if (this->_exec)
    {
        std::cout << this->_target << " has been robotized" << std::endl;
        this->_exec = false;
    }
    else
    {
        std::cout << "Robotomy failed on " << this->_target << std::endl;
        this->_exec = true;
    }

}

