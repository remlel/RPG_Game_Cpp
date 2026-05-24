#include "Action_Guerrier.hpp"
#include "Fonctions_utilitaires.hpp"
#include <vector>
#include <iostream>
#include <limits>

int Action_Guerrier(guerrier& guerrier, std::vector<Character*>& Team1, std::vector<Character*>& Team2, const sf::Event::KeyPressed* keyPress, int status, int choix)
{            
    //Actions possibles guerrier

    if (guerrier.getCharge() == 0 && guerrier.getCapaBouclier() == 0)
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
            int result_A = Attaque(Team2, &guerrier, keyPress);
            return result_A;
        }
    }
                
    else if (guerrier.getCharge() != 0 && guerrier.getCapaBouclier() == 0)
    {
        if (status == 0)
        {
            choix = Choix_Player(2, keyPress);
            if (choix == 1 || choix == 2)
            {
                Affichage_Attaque(Team2);
            }
            return choix;
        }
                    
        if (status == 1)
        {
            if (choix == 1)
            {
                int result_A = Attaque(Team2, &guerrier, keyPress);
                return result_A;
            }

            else
            {
                guerrier.Charge();
                int result_A = Attaque(Team2, &guerrier, keyPress);
                if (result_A == 1)
                {
                    guerrier.setCharge(guerrier.getCharge() + 1);
                }
                return result_A;
            }
        }
    }

    else if (guerrier.getCharge() == 0 && guerrier.getCapaBouclier() != 0)
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
                int result_A = Attaque(Team2, &guerrier, keyPress);
                return result_A;
            }
            else
            {
                for (Character* Membre : Team1)
                {
                    Membre->setDefenseBonus(15);   
                }
                guerrier.setCapaBouclier(guerrier.getCapaBouclier() - 1);
                return 0;
            }
        }
    } 

    else
    {
        if (status == 0)
        {
            choix = Choix_Player(3, keyPress);
            if (choix == 1 || choix == 2)
            {
                Affichage_Attaque(Team2);
            }
            return choix;
        }

        if (status == 1)
        {
            if (choix == 1)
            {
                int result_A = Attaque(Team2, &guerrier, keyPress);
                return result_A;
            }
            else if (choix == 2)
            {
                guerrier.Charge();
                int result_A = Attaque(Team2, &guerrier, keyPress);
                if (result_A == 1)
                {
                    guerrier.setCharge(guerrier.getCharge() + 1);
                }
                return result_A;
            }
            else
            {
                for (Character* Membre : Team1)
                {
                    Membre->setDefenseBonus(15);   
                }
                guerrier.setCapaBouclier(guerrier.getCapaBouclier() - 1);
                return 0;
            }
        }
    }
    return -1;
}