#include "Actions_Possibles.hpp"
#include <iostream>


void Actions_Possibles(Character* Perso, std::vector<Character*> Team1)
{
    if (guerrier* warrior = dynamic_cast<guerrier*>(Perso))
    {
        if (warrior->getCharge() == 0 && warrior->getCapaBouclier() == 0)
        {
            std::cout << "Actions Possibles : 1) Attaque classique" << std::endl;
            std::cout << "Choix d'action (1) :" << std::endl;
            
        }

        else if (warrior->getCharge() != 0 && warrior->getCapaBouclier() == 0)
        {
            std::cout << "Actions Possibles : 1) Attaque classique 2) Charge" << std::endl;
            std::cout << "Choix d'action (1 ou 2) :" << std::endl;
        }

        else if (warrior->getCharge() == 0 && warrior->getCapaBouclier() != 0)
        {
            std::cout << "Actions Possibles : 1) Attaque classique 2) Protection équipe" << std::endl;
            std::cout << "Choix d'action (1 ou 2) :" << std::endl;
        }

        else
        {
            std::cout << "Actions Possibles : 1) Attaque classique 2) Charge 3) Protection équipe" << std::endl;
            std::cout << "Choix d'action (1, 2 ou 3) :" << std::endl;
        }
    }

    if (mage* wizard = dynamic_cast<mage*>(Perso))
    {
        if (wizard->getMana() >= wizard->getMinMana())
        {
            std::cout << "Actions Possibles : 1) Attaque classique 2) Attaque Magique" << std::endl;
            std::cout << "Choix d'action (1 ou 2) :" << std::endl;
        }

        else
        {
            std::cout << "Actions Possibles : 1) Attaque classique" << std::endl;
            std::cout << "Choix d'action (1) :" << std::endl;
        }
    }

    if (moine* monk = dynamic_cast<moine*>(Perso))
    {
        std::vector<Character*> Team1_Soignable;
        for (Character* Perso : Team1)
        {
            if (Perso->IsAlive() && Perso != monk)
            {
                Team1_Soignable.push_back(Perso);
            }
        
        }
        if (Team1_Soignable.size() > 0)
        {
            std::cout << "Actions Possibles : 1) Attaque classique 2) Soigner" << std::endl;
            std::cout << "Choix d'action (1 ou 2) :" << std::endl;
        }

        else
        {
            std::cout << "Actions Possibles : 1) Attaque classique" << std::endl;
            std::cout << "Choix d'action (1) :" << std::endl;
        }
    }
}