#pragma once
#include "../Personnages/Personnages.hpp"



const int SEUIL = 100;

enum GameState 
{
    CALCUL_TOUR,
    TOUR_IA,
    TOUR_JOUEUR_CHOIX_ACTION,
    TOUR_JOUEUR_CHOIX_CIBLE,
    FIN_PARTIE
};

struct GameData
{
    std::vector<Character*> Team1;
    std::vector<Character*> Team2;
    std::vector<Character*> AllCharacters;
};

GameData Création_Equipe();

bool IsTeamAlive(const std::vector<Character*>& targets);

std::vector<Character*> Liste_Persos_Actifs(std::vector<Character*>& L_Perso);

Character* Tour_Character(std::vector<Character*>& targets);

