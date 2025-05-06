#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap Tyrion("Diamond1");

    Tyrion.attack("Diamond2");
    Tyrion.takeDamage(10);
    Tyrion.beRepaired(4);
    Tyrion.guardGate();
    Tyrion.highFivesGuys();
    Tyrion.whoAmI();
}