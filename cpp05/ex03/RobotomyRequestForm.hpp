/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 15:24:35 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/19 11:20:53 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const& src);
        RobotomyRequestForm& operator=(RobotomyRequestForm const& src);
        ~RobotomyRequestForm();

        virtual void execute( Bureaucrat const & executor ) const;
    private:
        std::string _target;
        mutable bool _exec;
};