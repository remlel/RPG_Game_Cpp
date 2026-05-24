#include "guerrier.hpp"
#include <iostream>
#include <string>
#include <vector>

// Constructeurs & Destructeurs

guerrier::guerrier()
    : Character("Guerrier", 150, 150, 20, 15, 5, 100), g_capa_bouclier(1), g_charge(1), g_is_charged(false)
{}

guerrier::guerrier(std::string name, int PV, int PVmax, int Attack, int Defense, int vitesse, int pointsAction, int capa_bouclier, int charge, bool isCharged)
    : Character(name, PV, PVmax, Attack, Defense, vitesse, pointsAction), g_capa_bouclier(capa_bouclier), g_charge(charge), g_is_charged(isCharged)
{}

guerrier::~guerrier()
{
    std::cout << "Destruction (G) : " << m_Name << std::endl;
}


// Méthodes

void guerrier::Attack(Character& target) 
{
    if (g_is_charged)
    {
        std::cout << "Charge de " << m_Name << " sur " << target.getName() << std::endl;
        target.TakeDamage(m_Attack*5);
        g_is_charged = false;
    }
    else
    {
        std::cout << "Attaque strandard de " << m_Name << " sur " << target.getName() << std::endl;
        target.TakeDamage(m_Attack);
    }
}

void guerrier::Charge()
{
    g_charge -= 1;
    g_is_charged = true;
}


// Getters & Setters

int guerrier::getCapaBouclier() const
{
    return g_capa_bouclier;
}

int guerrier::getCharge() const
{
    return g_charge;
}

void guerrier::setCapaBouclier(int Capa)
{
    g_capa_bouclier = Capa;
}

void guerrier::setCharge(int Charge)
{
    g_charge = Charge;
}

