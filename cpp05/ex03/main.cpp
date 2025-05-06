/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:43:15 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/20 11:36:53 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* rrf;
    AForm* rrf2;
    AForm* rrf3;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    rrf2 = someRandomIntern.makeForm("presidential pardon", "Bender");
    rrf3 = someRandomIntern.makeForm("shrubbery creation", "Bender");
    delete rrf;
    delete rrf2;
    delete rrf3;
}

// #include "Bureaucrat.hpp"
// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "Intern.hpp"

// int main()
// {
//     Intern random;
//     AForm    *rrf;
//     Bureaucrat *boss = new Bureaucrat("boss", 1);
//     rrf = random.makeForm("robotomy request", "Bender");
    
//     try
//     {
//         boss->executeForm(*rrf);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
    
//     try
//     {
//         boss->signForm(*rrf);
//         rrf->beSigned(*boss);
//         boss->signForm(*rrf);
//         boss->executeForm(*rrf);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     try
//     {
//         delete rrf;
//         rrf = random.makeForm("presidential pardon", "Thanksgiving Turkey");
//         boss->signForm(*rrf);
//         rrf->beSigned(*boss);
//         boss->executeForm(*rrf);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     try
//     {
//         delete rrf;
//         rrf = random.makeForm("shrubbery creation", "santa claus");
//         rrf->beSigned(*boss);
//         boss->executeForm(*rrf);
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     delete rrf;
//     delete boss;
// }
