/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmondor <vmondor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:43:15 by vmondor           #+#    #+#             */
/*   Updated: 2024/10/01 13:51:52 by vmondor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Fonction qui génère aléatoirement une instance de A, B ou C
Base* generate()
{
    int random = std::rand() % 3;
    if (random == 0)
    {
        return new A;
    }
    else if (random == 1)
    {
        return new B;
    }
    else
    {
        return new C;
    }
}

// Fonction pour identifier le type via un pointeur
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "C" << std::endl;
    }
    else
    {
        std::cout << "Type inconnu" << std::endl;
    }
}

// Fonction pour identifier le type via une référence (sans utiliser de pointeur)
void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (const std::exception &e)
    {
    }

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;    
    }
    catch (const std::exception &e)
    {
    }

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch (const std::exception &e)
    {
    }
}


int main()
{
    std::srand(std::time(0));

    Base* instance = generate();

    //Pointeur
    std::cout << "Identification via pointeur: ";
    identify(instance);

    //Référence
    std::cout << "Identification via référence: ";
    identify(*instance);

    delete instance;
    return 0;
}