#include "Action_Moine.hpp"
#include "Fonctions_utilitaires.hpp"
#include <iostream>
#include <limits>
#include <vector>

int Action_Moine(moine& monk, std::vector<Character*>& Team1, std::vector<Character*>& Team2, const sf::Event::KeyPressed* keyPress, int status, int choix)
{


    std::vector<Character*> Team1_Soignable;
    for (Character* Perso : Team1)
    {
        if (Perso->IsAlive() && Perso != &monk)
        {
            Team1_Soignable.push_back(Perso);
        }
    }

    if (Team1_Soignable.size() > 0)
    {
        if (status == 0)
        {
            choix = Choix_Player(2, keyPress);
            if (choix == 1)
            {
                Affichage_Attaque(Team2);
            }
            if (choix == 2)
            {
                std::cout << "Alliés soignables :" << std::endl;
                for (size_t i = 0; i < Team1_Soignable.size(); ++i)
                {
                    std::cout << i+1 << ") " << Team1_Soignable[i]->getName() << std::endl;
                }
        
                std::cout << "Choix d'allié (numéro) :" << std::endl;
            }
            return choix;
        }
        
        if (status == 1)
        {
            if (choix == 1)
            {
                int result_A = Attaque(Team2, &monk, keyPress);
                return result_A;
            }
            else
            {
                choix = Choix_Player(Team1_Soignable.size(), keyPress);
                if (choix != -1)
                {
                    monk.Heal(Team1_Soignable[choix-1]);
                    return 0;
                }
                else
                {
                    return 1;
                }
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
            int result_A = Attaque(Team2, &monk, keyPress);
            return result_A;
        }
    }
    return -1;
}