/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:43:15 by vmondor           #+#    #+#             */
/*   Updated: 2024/09/18 11:28:18 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
    Bureaucrat *a = new Bureaucrat("CHAD", 1);
    std::cout << *a << std::endl;
    Bureaucrat *b = new Bureaucrat("Emmanuel", 49);
    std::cout << *b << std::endl;
    Form *doc1 = new Form();
    std::cout << *doc1 << std::endl;
    Form *doc2 = new Form("49.3", 30);
    try
    {
        a->signForm(*doc1);
        doc1->beSigned(*a);
        a->signForm(*doc1);
        b->signForm(*doc2);
        doc2->beSigned(*b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form c = Form("minishell.c", 158);
        c.beSigned(*a);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form d = Form("minishell.c", 20);
        d.beSigned(*b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
    delete a;
    delete b;
    delete doc1;
    delete doc2;
    return 0;
}