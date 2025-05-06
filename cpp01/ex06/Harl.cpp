#include <iostream>
#include <string>
#include "Harl.hpp"

Harl::Harl()
{
    return ;
}

Harl::~Harl()
{
    return ;
}

void    Harl::complain(std::string level)
{
    void    (Harl::*function[])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i(0); i < 4; i++)
    {
        if (level == levels[i])
        {
            switch (i)
            {
                case 0:
                    for (int j = 0; j < 4; j++)
                        (this->*function[j])();
                    break;
                case 1:
                    for (int j = 1; j < 4; j++)
                        (this->*function[j])();
                    break;
                case 2:
                    for (int j = 2; j < 4; j++)
                        (this->*function[j])(); 
                    break;
                case 3:
                    for (int j = 3; j < 4; j++)
                        (this->*function[j])();
                    break;
                default:
                    std::cout << "Invalid level" << std::endl;
                    break;
            }
            return ;
        }
    }
    std::cout << "Invalid level" << std::endl;
    return ;
}
void    Harl::debug(void)
{
    std::cout << "[ DEBUG ] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
    return ; 
}

void    Harl::info(void)
{
    std::cout << "[ INFO ] I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
    return ; 
}

void    Harl::warning(void)
{
    std::cout << "[ WARNING ] I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
    return ; 
}

void    Harl::error(void)
{
    std::cout << "[ ERROR ] This is unacceptable ! I want to speak to the manager now." << std::endl;
    return ; 
}
