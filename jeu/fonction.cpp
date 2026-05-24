#include "fonction.hpp"


GameData Création_Equipe()
{

    GameData data;

    guerrier* guerrier1 = new guerrier("Guerrier1", 150, 150, 20, 15, 20, 0, 1, 1, false);
    guerrier* guerrier2 = new guerrier("Guerrier2", 150, 150, 20, 15, 20, 0, 1, 1, false);

    mage* mage1 = new mage("Mage1", 100, 100, 12, 10, 15, 0, 0, 8, 3);
    mage* mage2 = new mage("Mage2", 100, 100, 12, 10, 15, 0, 0, 8, 3);

    moine* moine1 = new moine("Moine1", 80, 80, 10, 5, 12, 0, 15);
    moine* moine2 = new moine("Moine2", 80, 80, 10, 5, 12, 0, 15);

    data.Team1 = {guerrier1, mage1, moine1};
    data.Team2 = {guerrier2, mage2, moine2};
    data.AllCharacters = {guerrier1, mage1, moine1, guerrier2, mage2, moine2};

    return data;
}


bool IsTeamAlive(const std::vector<Character*>& targets)
{
    for (Character* perso : targets)
    {
        if (perso->IsAlive())
        {
            return true;
        }
    }
    return false;
}


std::vector<Character*> Liste_Persos_Actifs(std::vector<Character*>& L_Perso)
{
    std::vector<Character*> Perso_MaxPoints;
    if (L_Perso.empty()) return Perso_MaxPoints;
    int maxPoints = L_Perso[0]->getPointsAction();

    for (int i = 1; i < L_Perso.size(); ++i)
        {
            if (L_Perso[i]->getPointsAction() > maxPoints)
            {
                maxPoints = L_Perso[i]->getPointsAction();
            }
        }

    if (maxPoints < SEUIL)
    {
        return Perso_MaxPoints;
    }
    for (int i = 0; i < L_Perso.size(); ++i)
    {
        if (L_Perso[i]->getPointsAction() == maxPoints)
        {
            Perso_MaxPoints.push_back(L_Perso[i]);
        }
    }
    return Perso_MaxPoints;
}


Character* Tour_Character(std::vector<Character*>& targets)
{
    if (targets.empty()) return nullptr;

    int index = std::rand() % targets.size();

    return targets[index];
}

