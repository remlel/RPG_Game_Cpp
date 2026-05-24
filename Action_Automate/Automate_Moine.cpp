#include "Automate_Moine.hpp"
#include "Fonctions_Automate.hpp"
#include <vector>
#include <iostream>

void Automate_Moine(moine& moine, std::vector<Character*>& Team1, std::vector<Character*>& Team2)
{
    std::vector<Character*> Team2Alive;
    for (Character* Perso : Team2)
    {
        if (Perso->IsAlive())
        {
            Team2Alive.push_back(Perso);
        }
    }
    
    bool maxPV = true;

    for (Character* Perso : Team2Alive)
    {
        if (Perso->getPV() < 0.8*Perso->getPVmax() && Perso != &moine)
        {
            maxPV = false;
            break;
        }
    }

    
    if (Team2Alive.size() == 1 || maxPV)
    {
        Attack(&moine, Choix_IA_Attack(Team1));
    }

    else
    {
        Character* Allié = nullptr;
        for (Character* Perso : Team2Alive)
        {
            if (Perso == &moine)
            {
                continue;
            }

            if (Allié == nullptr || Allié->getPV() > Perso->getPV())
            {
                Allié = Perso;
            }
        }

        if (Allié)
        {
            moine.Heal(Allié);
        } 
        else
        {
            Attack(&moine, Choix_IA_Attack(Team1));
        }
    }
}