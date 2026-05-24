#include "moine.hpp"
#include <iostream>
#include <string>


// Constructeurs & Destructeurs

moine::moine()
    : Character("Moine", 80, 80, 10, 5, 2, 100), p_healingPV(15)
{}

moine::moine(const std::string Name, int PV, int PVmax, int Attack, int Defense, int vitesse, int pointsAction, int healingPV)
    : Character(Name, PV, PVmax, Attack, Defense, vitesse, pointsAction), p_healingPV(healingPV)
{}

moine::~moine()
{
    std::cout << "Destruction (P) : " << m_Name << std::endl;
}


// Méthodes

void moine::Heal(Character* target)
{   
    if ((target->getPVmax() - target->getPV()) > p_healingPV)
    {
        int new_PV = target->getPV() + p_healingPV;
        target->setPV(new_PV);
        std::cout << m_Name << " a rajouté " << p_healingPV << " à " << target->getName() << std::endl;
    }
    else
    {
        target->setPV(target->getPVmax());
        std::cout << target->getName() << " au maximum de ses PV : " << target->getPVmax() << std::endl;
    }
}


// Getters & Setters

int moine::getHealingPV() const
{
    return p_healingPV;
}

