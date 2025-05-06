/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:35:12 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/19 15:06:25 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    return ;
}

Intern::Intern(Intern const& src)
{
    if (this != &src)
        *this = src;
}

Intern& Intern::operator=(Intern const& src)
{
    if (this != &src)
        *this = src;
    return *this;
}

Intern::~Intern()
{
    
}

AForm* Intern::makeForm(std::string formName, std::string targetName)
{
    std::string formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm* (*formCreate[])(std::string) = {&Intern::createPresidentielPardon, &Intern::createRobotomyRequest, &Intern::createShrubberyCreation};
    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreate[i](targetName);
        }
    }
    std::cerr << "Error: Form " << formName << " not found" << std::endl;
    return NULL;
}

AForm* Intern::createPresidentielPardon(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequest(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubberyCreation(std::string target)
{
    return new ShrubberyCreationForm(target);
}
