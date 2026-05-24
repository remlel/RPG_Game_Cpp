#include "Action_Mage.hpp"
#include "Fonctions_utilitaires.hpp"
#include <iostream>
#include <limits>
#include <vector>

int Action_Mage(mage& wizard, std::vector<Character*>& Team2, const sf::Event::KeyPressed* keyPress, int status, int choix)
{
    //Actions possibles mages

    if (wizard.getMana() >= wizard.getMinMana())
    {
        if (status == 0)
        {
            choix = Choix_Player(2, keyPress);
            if (choix == 1)
            {
                Affichage_Attaque(Team2);
            }
            return choix;
        }
        
        if (status == 1)
        {
            if (choix == 1)
            {
                int result_A = Attaque(Team2, &wizard, keyPress);
                return result_A;
            }
            else
            {
                wizard.AttackMagic(Team2);
                return 0;
            }
        }
    }

    else
    {
        if (status == 0)
        {
            choix = Choix_Player(1, keyPress);
            if (choix == 1)
            {
                Affichage_Attaque(Team2);
            }
            return choix;
        }
        if (status == 1)
        {
            int result_A = Attaque(Team2, &wizard, keyPress);
            return result_A;
        }
    }
    return -1;
}