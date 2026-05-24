#include "Fonctions_utilitaires.hpp"
#include <iostream>
#include <limits>


Character* ChoixCible(std::vector<Character*>& Team, const sf::Event::KeyPressed* keyPress)
{                  
    std::vector<Character*> cibles;
    for (size_t i=0; i < Team.size(); ++i)
    {
        if (Team[i]->IsAlive())
        {
        cibles.push_back(Team[i]);  
        }
    }
    
    if (cibles.empty())
    {
        return nullptr;
    }
    
    int choix = Choix_Player(cibles.size(), keyPress);
    if (choix == -1)
    {
        return nullptr;
    }
    else
    {
        return cibles[choix - 1];
    }
}

int Attaque(std::vector<Character*>& Team, Character* perso, const sf::Event::KeyPressed* keyPress)
{
    Character* cible = ChoixCible(Team, keyPress);
    if (cible)
    {
        perso->Attack(*cible);
        return 0;
    }
    else
    {
        return 1;
    }
}

int Choix_Player(int max, const sf::Event::KeyPressed* keyPress)
{
    int valeur = -1;        // -1 signifie "Touche invalide" par défaut

    int code_touche = static_cast<int>(keyPress->code);

    
    if (code_touche == 27 || code_touche == 76) valeur = 1;
    else if (code_touche == 28 || code_touche == 77) valeur = 2;
    else if (code_touche == 29 || code_touche == 78) valeur = 3;
    
    if (valeur >= 1 && valeur <= max)
    {
        return valeur; 
    }
    else
    {
        if (max == 1)
        {
            std::cout << "Mauvaise touche. Choisis 1 :" << std::endl << std::flush;
        }
        else
        {
            std::cout << "Mauvaise touche. Choisis un entier entre 1 et " << max << " :" << std::endl << std::flush;
        }
        
        return -1; 
    }
}

void Affichage_Attaque(std::vector<Character*>& Team)
{
    std::cout << "Quel ennemi attaquer?" << std::endl;
    int numero = 1;
    for (Character* ennemi : Team) 
    {
        if (ennemi->IsAlive()) 
        {
            std::cout << numero << ") " << ennemi->getName() << std::endl;
            numero++;
        }
    }
    std::cout << "Choix de l'ennemi a attaqué :" << std::endl;
}