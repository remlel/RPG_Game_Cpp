#include "character.hpp"
#include <string>
#include <iostream>


// Constructeurs & Destructeurs

Character::Character()
    : m_Name(""), m_PV(0), m_PVmax(0), m_Attack(0), m_Defense(0), m_vitesse(0), m_pointsAction(0)  
{}

Character::Character(const std::string Name, int PV, int PVmax, int Attack, int Defense, int vitesse, int pointsAction)
    : m_Name(Name), m_PV(PV), m_PVmax(PVmax), m_Attack(Attack), m_Defense(Defense), m_vitesse(vitesse), m_pointsAction(pointsAction)
{}

Character::~Character()
{
    std::cout << "Destruction (C) : " << m_Name << std::endl;
}


// Méthodes

void Character::TakeDamage(int dégats)
{
    // Utilisation de floats 
    int defense = m_Defense + m_defenseBonus;
    if (defense > 99)
    {
        defense = 99;
    }
    m_PV -= dégats * (1.0f - (float)(defense) / 100.0f);

    if (m_PV < 0) m_PV = 0;             // Pas de PV négatifs
}

void Character::Attack(Character& target)
{
    std::cout << "Attaque strandard de " << m_Name << " sur " << target.m_Name << std::endl;
    target.TakeDamage(m_Attack);
}

bool Character::IsAlive()
{
    return m_PV > 0;
}


// Getters & Setters

std::string Character::getName() const
{
    return m_Name;
}

int Character::getPV() const
{
    return m_PV;
}

int Character::getVitesse() const
{
    return m_vitesse;
}

int Character::getDefense() const
{
    return m_Defense + m_defenseBonus;
}

int Character::getAttack() const
{
    return m_Attack;
}

int Character::getPVmax() const
{
    return m_PVmax;
}

int Character::getPointsAction() const
{
    return m_pointsAction;
}

int Character::getDefBonus() const
{
    return m_defenseBonus;
}

void Character::setPV(int newPV)
{
    m_PV = newPV;
}

void Character::setPointsAction(int NewPA)
{
    m_pointsAction = NewPA;
}

void Character::setDefenseBonus(int defenseBonus)
{
    m_defenseBonus = defenseBonus;
}