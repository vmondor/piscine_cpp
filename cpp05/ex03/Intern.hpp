/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:24:14 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/19 13:40:00 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>


class Intern
{
    public:
        Intern();
        Intern(Intern const& src);
        Intern& operator=(Intern const& src);
        ~Intern();

        AForm* makeForm(std::string formName, std::string targetName);
        typedef AForm* (*FormFunction)(std::string target);
        static AForm* createPresidentielPardon(std::string target);
        static AForm* createRobotomyRequest(std::string target);
        static AForm* createShrubberyCreation(std::string target);
};