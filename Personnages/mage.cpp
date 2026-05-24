#include <iostream>
#include "mage.hpp"
#include <string>
#include <vector>


// Constructeurs & Destructeurs

mage::mage()
    : Character("Mage", 100, 100, 10, 10, 3, 100), s_mana(0), s_degat_sort(10), s_min_mana(3)
{}

mage::mage(const std::string name, int PV, int PVmax, int Attack, int Defense, int vitesse, int pointsAction, int mana, int dégat_sort, int min_mana)
    : Character(name, PV, PVmax, Attack, Defense, vitesse, pointsAction), s_mana(mana), s_degat_sort(dégat_sort), s_min_mana(min_mana)
{}

mage::~mage()
{
    std::cout << "Destruction (M) : " << m_Name << std::endl;
}


// Méthodes

void mage::AttackMagic(std::vector<Character*>& targets)
{
    std::cout << "Le " << m_Name << " blesse toute l'équipe adverse !" << std::endl;
    s_mana -= s_min_mana;
        
    // Itération sur chaque ennemi dans le vecteur
    for (Character* enemy : targets) 
    {
        if (enemy->IsAlive())               // "->" pour les pointeurs <=> (*enemy).IsAlive()
        {
            int nouveauxPV = enemy->getPV() - s_degat_sort;
            if (nouveauxPV < 0)
            {
                nouveauxPV = 0;
            }
            enemy->setPV(nouveauxPV); 
                
            std::cout << " - " << enemy->getName() << " subit " << s_degat_sort << " points de degats magiques." << std::endl;
        }
    }
}


// Getters & Setters

int mage::getMana() const
{
    return s_mana;
}

int mage::getDegatSort() const
{
    return s_degat_sort;
}

int mage::getMinMana() const
{
    return s_min_mana;
}

int mage::getIQ() const
{
    return s_IQ;
}

void mage::setMana(int NewMana)
{
    s_mana = NewMana;
}
