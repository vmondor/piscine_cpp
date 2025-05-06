/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:19:22 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/18 17:25:59 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(): AForm::AForm("ShrubberyCreationForm", 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& src)
{
    this->_target = src._target;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& src)
{
    if (this != &src)
        this->_target = src._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
    if (!this->getIsSigned())
        throw AForm::IsNotSignedException();
    if (executor.getGrade() > this->getExecutedGrade())
        throw AForm::GradeTooLowException();
    std::string filename = this->_target + "_shrubbery";
    std::ofstream result(filename.c_str());
    if (!result.is_open())
        std::cerr << "Error: Open file" << std::endl;
    else
    {
        result << "              ,@@@@@@@," << std::endl;
        result << "      ,,,.   ,@@@@@@/@@,  .oo8888o. " << std::endl;
        result << "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o " << std::endl;
        result << "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88' " << std::endl;
        result << "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888' " << std::endl;
        result << "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88' " << std::endl;
        result << "  `&%\\ ` /%&'    |.|        \\ '|8' " << std::endl;
        result << "      |o|        | |         | | " << std::endl;
        result << "      |.|        | |         | | " << std::endl;
        result << "   \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_ by vmondor" << std::endl;
        result.close();
    }
}
