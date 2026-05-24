#include "character.hpp"
#pragma once
#include <string>
#include <vector>


class mage : public Character
{
public :

    mage();
    mage(const std::string name, int PV, int PVmax, int Attack, int Defense, int vitesse, int pointsAction, int mana, int dégat_sort, int min_mana);

    ~mage();

    void AttackMagic(std::vector<Character*>& targets);

    int getMana() const;
    int getDegatSort() const;
    int getMinMana() const;
    int getIQ() const;
    void setMana(int NewMana);

private :

    int s_mana;
    int s_degat_sort;
    int s_min_mana;
    int s_IQ = 1;

};