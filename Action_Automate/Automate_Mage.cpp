#include "Automate_Mage.hpp"
#include "Fonctions_Automate.hpp"
#include <vector>
#include <iostream>


void Automate_Mage(mage& mage, std::vector<Character*>& Team1)
{
    int N_ennemi = 0;
    for (Character* Perso : Team1)
    {
        if (Perso->IsAlive())
        {
            N_ennemi += 1;
        }
    }

    if (N_ennemi > 1 && mage.getMana() >= mage.getMinMana())
    {
        mage.AttackMagic(Team1);
    }

    else
    {
        Attack(&mage, Choix_IA_Attack(Team1));
    }
}