#include "Fonctions_Automate.hpp"
#include <iostream>


Character* Choix_IA_Attack(std::vector<Character*>& Team)
{
    Character* Cible = nullptr;
    for (Character* Perso : Team)
        {
            if (!Perso->IsAlive())
            {
                continue;
            }
            if (Cible == nullptr || Cible->getPV() > Perso->getPV())
            {
                Cible = Perso;
            }
        }
    return Cible;
}

void Attack(Character* Perso, Character* Target)
{
    if (Target == nullptr)   
        {
            std::cout << "erreur cible : pointeur nul" << std::endl;
        }            
        else
        {
            Perso->Attack(*Target);
        }
}