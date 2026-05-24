#pragma once
#include <string>


class Character{

public :

    Character();
    Character(const std::string Name, int PV, int PVmax, int Attack, int Defense, int vitesse, int pointsAction);

    virtual ~Character();       // Virtual -> destruction propre des éléments des classes enfants (Utilisation des destructeurs enfants avant celui-ci)

    
    void TakeDamage(int dégats);
    virtual void Attack(Character& target);     // Virtual = Polymorphisme -> Permet d'appeler les méthodes propres aux classes enfants
    bool IsAlive();

    
    std::string getName() const;
    int getPV() const;
    int getVitesse() const;
    int getDefense() const;
    int getAttack() const;
    int getPVmax() const;
    int getPointsAction() const;
    int getDefBonus() const;
    void setPV(int newPV);
    void setPointsAction(int NewPA);
    void setDefenseBonus(int defenseBonus);


protected :
    
    const std::string m_Name;
    int m_PV;
    int m_PVmax;
    int m_Attack;
    int m_Defense;      // compris entre 0 et 100
    int m_vitesse;
    int m_pointsAction;
    int m_defenseBonus = 0;

};

