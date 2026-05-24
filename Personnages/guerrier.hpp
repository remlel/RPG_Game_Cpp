#pragma once
#include "character.hpp"
#include <string>
#include <vector>

class guerrier : public Character {     // Les éléments public dans Character restent public chez guerrier

public :

    guerrier();
    guerrier(std::string name, int PV, int PVmax, int Attack, int Defense, int vitesse, int pointsAction, int capa_bouclier, int charge, bool isCharged);

    ~guerrier();

    void Attack(Character& target) override;
    void Charge();

    int getCapaBouclier() const;
    int getCharge() const;
    void setCapaBouclier(int Capa);
    void setCharge(int Charge);

private :

    bool g_is_charged;         // Etat de la charge 
    int g_capa_bouclier;      // Nombre de protection possible des alliés
    int g_charge;             // Nombre de charge possible

};
