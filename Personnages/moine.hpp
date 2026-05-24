#include "character.hpp"
#pragma once
#include <string>

class moine : public Character
{

public : 

    moine();
    moine(const std::string Name, int PV, int PVmax, int Attack, int Defense, int vitesse, int pointsAction, int healingPV);

    ~moine();

    void Heal(Character* target);

    int getHealingPV() const;

private :

    int p_healingPV;

};