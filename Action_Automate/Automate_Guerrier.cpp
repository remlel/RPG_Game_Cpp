#include "Automate_Guerrier.hpp"
#include "Fonctions_Automate.hpp"
#include <vector>
#include <iostream>


void Automate_Guerrier(guerrier& guerrier, std::vector<Character*>& Team1, std::vector<Character*>& Team2)
{             
    if (guerrier.getCharge() > 0)
    {
        guerrier.Charge();
        Character* Cible = nullptr;
        for (Character* Perso : Team1)
        {
            if (Cible == nullptr && Perso->IsAlive())
            {
                Cible = Perso;
            }
            else if (Cible != nullptr && Perso->IsAlive() && Cible->getPV() < Perso->getPV())
            {
                Cible = Perso;
            }
        }
        
        Attack(&guerrier, Cible);
    }

    else if (guerrier.getCapaBouclier() != 0)
    {
        for (Character* Membre : Team2)
            {
                Membre->setDefenseBonus(15);
            }
        guerrier.setCapaBouclier(guerrier.getCapaBouclier() - 1);
        std::cout << guerrier.getName() << " a protégé son équipe avec un bouclier (" << guerrier.getDefBonus() << ") !" << std::endl;
    }

    else
    {
        Attack(&guerrier, Choix_IA_Attack(Team1));
    }
}
    








    