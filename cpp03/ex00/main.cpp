
#include "ClapTrap.h"
#include <iostream>

#define RED "\033[31m"
#define RESET "\033[0m"

int main(void) {
    std::cout << RED
              << "HIIIII WEEEEELLLCOMEEEEE TO THEEEE FIGHTTTTT OF THE DECADE!!!"
              << std::endl
              << RED << "BOTH FIGHTERS ENTER THE ARENA" << RESET << std::endl;

    ClapTrap nb1("adjoly");
    ClapTrap nb2("ltouzali");
	std::cout << std::endl;

	nb1.setAttackDamage(5);
    nb1.attack(nb2.getName());
    nb2.takeDamage(nb1.getAttackDamage());

	nb2.setAttackDamage(4);
	nb2.attack(nb1.getName());
    nb1.takeDamage(nb2.getAttackDamage());

    nb2.setAttackDamage(299792458);
    std::cout
        << RED << nb2.getName()
        << " INVOKES THE POWER OF PHYSICS, SETTING HIS POWER TO THE SPEED "
           "OF LIGHT!!!"
        << RESET << std::endl;
    std::cout << RED << "OH MY GOD, HOW COULD " << nb1.getName() << " SURVIVE?"
              << RESET << std::endl;
    nb1.beRepaired(3249570025);
    std::cout << RED << "WHAT IS THAT!?!?!?!?!" << RESET << std::endl
              << RED << "IS THAT THE..." << RESET << std::endl
              << RED << "THE..." << RESET << std::endl
              << RED << "THE WINDOWS BLUE SCREEN ERROR SQUARED 0XDEAD?!?!?!"
              << RESET << std::endl;

    nb1.attack(nb2.getName());
    nb2.takeDamage(nb1.getAttackDamage());

    nb2.attack(nb1.getName());
    nb1.takeDamage(nb2.getAttackDamage());

    std::cout << RED << "WHAT A GAME, MY FRIEND!!!" << RESET << std::endl
              << RED << "IF " << nb2.getName()
              << " DOESN'T HEAL, THIS COULD BE OVER FOR HIM NEXT ROUND, BUT "
                 "ANYTHING IS POSSIBLE!!!!!"
              << RESET << std::endl;
    nb2.beRepaired(2950);
    std::cout << RED
              << "OH MY GOD, THAT'S A HEAL OF THE SCHWARZSCHILD RADIUS FROM "
              << nb2.getName() << RESET << std::endl
              << RED << "THIS ISN'T MUCH, BUT THE ATTACK OF " << nb1.getName()
              << " IS STILL " << nb1.getAttackDamage() << RESET << std::endl;

    nb1.attack(nb2.getName());
    nb2.takeDamage(nb1.getAttackDamage());

    nb2.attack(nb1.getName());
    nb1.takeDamage(nb2.getAttackDamage());
    nb1.setAttackDamage(6800);
    std::cout << RED << nb1.getName()
              << " JUST UPGRADED HIS POWER TO THE SPEED OF THE FAMOUS SOLIDUM "
                 "D5-P5536 SSD U2 15MM 7.68TB!"
              << RESET << std::endl;

    nb1.attack(nb2.getName());
    nb2.takeDamage(nb1.getAttackDamage());

    nb2.attack(nb1.getName());
    std::cout << RED << nb2.getName() << " TRIES TO ATTACK BUT IS DEAD!!!"
              << RESET << std::endl
              << RED << "THAT'S A WIN FOR " << nb1.getName() << "!!!!!" << RESET
              << std::endl;

    return 0;
}
